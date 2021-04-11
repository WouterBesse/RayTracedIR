#include "rayTracer.h"

RayTracer::RayTracer() {
}

RayTracer::~RayTracer() {
}

void RayTracer::rayTrace(Camera* camera, ShapeSet* scene) {
  int bounceCount = 5; // make >= 1

  // Data saver to prevent writing large files over and over
  // set to 0 to write totalRayDistanceData only (use for program)
  // set to 1 to write pgm image and bounceData (low level debugging, less data)
  // set to 2 to write all debugging files (writes a lot more data)
  int dataSaver = 1;

  TracedRay tracedRay;
  std::vector<TracedRay> tracedRays[bounceCount + 1];

  std::cout << '\n' << "Casting rays..." << '\n';

  for (int x = 0; x < width; x++) {
    for (int y = 0; y < height; y++) {
      Vector2 screenCoord((2.0f*x) / width - 1.0f, (-2.0f*y) / height + 1.0f);
      Ray ray = camera->makeRay(screenCoord);
      Intersection intersection(ray);
      if (scene->intersect(intersection)) {
        tracedRay.x = x;
        tracedRay.y = y;
        tracedRay.rayInBounds = true;
        tracedRay.interDistance = intersection.t;
        tracedRay.summedDistance = intersection.t;
        tracedRay.pointOfIntersect = intersection.pointOfIntersect;
        tracedRay.rayOrigin = ray.origin;
        tracedRay.rayDirection = ray.direction;
        tracedRay.planeNormal = intersection.normalAtPOI;
        tracedRays[0].push_back(tracedRay);
      } else {
        tracedRay.x = x;
        tracedRay.y = y;
        tracedRay.rayInBounds = false;
        tracedRays[0].push_back(tracedRay);
      }
    }
  }

  if (dataSaver == 2) {
    std::ofstream debugData;
    debugData.open("debugData.txt");

    for (int i = 0; i < tracedRays[0].size(); i++) {
      if (tracedRays[0][i].rayInBounds != 0) {
        debugData << "x: " << tracedRays[0][i].x << '\t';
        debugData << "y: " << tracedRays[0][i].y << '\t';
        debugData << "inBounds: " << tracedRays[0][i].rayInBounds << '\t';
        debugData << "intDst: " << tracedRays[0][i].interDistance << '\t';
        debugData << "pointOfIntersectXYZ: " << '\t' <<
        tracedRays[0][i].pointOfIntersect.x << " " <<
        tracedRays[0][i].pointOfIntersect.y << " " <<
        tracedRays[0][i].pointOfIntersect.z << '\n';
      }
    }
    debugData.close();
    std::cout << "---debugData.txt file written---" << '\n';

    std::ofstream intersectionDataN;
    intersectionDataN.open("intersectionDataN.txt");

    for (int i = 0; i < tracedRays[0].size(); i++) {
      if (tracedRays[0][i].rayInBounds != 0) {
        intersectionDataN << tracedRays[0][i].interDistance << '\n';
      }
    }

    intersectionDataN.close();
    std::cout << "---intersectionDataN.txt file written---" << '\n';

    std::ofstream intersectionDataC;
    intersectionDataC.open("intersectionDataC.txt");

    for (int i = 0; i < tracedRays[0].size(); i++) {
      if (tracedRays[0][i].rayInBounds != 0) {
        intersectionDataC << tracedRays[0][i].interDistance << ", ";
      }
    }

    intersectionDataC.close();
    std::cout << "---intersectionDataC.txt file written---" << '\n';
  }

  if (dataSaver == 1 || dataSaver == 2) {
    // ---make image file---
    int tempImage[height][width];
    int temp = 0;
    int xPixel = 0;
    int yPixel = 0;
    int pixelColor = 0;

    for (int i = 0; i < tracedRays[0].size(); i++) {
      if (tracedRays[0][i].rayInBounds != 0) {
        xPixel = tracedRays[0][i].x;
        yPixel = tracedRays[0][i].y;
        pixelColor = 255 - tracedRays[0][i].interDistance * 25;
        tempImage[yPixel][xPixel] = pixelColor;
      } else {
        xPixel = tracedRays[0][i].x;
        yPixel = tracedRays[0][i].y;
        tempImage[yPixel][xPixel] = 255;
      }
    }

    FILE* pgmimg;
    pgmimg = fopen("pgmimg.pgm", "wb");
    // Writing Magic Number to the File
    fprintf(pgmimg, "P2\n");
    // Writing Width and Height
    fprintf(pgmimg, "%d %d\n", width, height);
    // Writing the maximum gray value
    fprintf(pgmimg, "255\n");

    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        temp = tempImage[i][j];
        // Writing the gray values in the 2D array to the file
        fprintf(pgmimg, "%d ", temp);
      }
      fprintf(pgmimg, "\n");
    }
    fclose(pgmimg);
    std::cout << "---pgmimg.pgm file written---" << '\n';
  }

  Vector curNormal;
  Point curPointOfIntersect;
  Vector vI;
  Vector vR;
  float summedDistance;

  // Recursive bouncing
  std::cout << '\n' << "Tracing rays..." << '\n';
  for (int i = 0; i < bounceCount; i ++) {
    for (int j = 0; j < tracedRays[i].size(); j++) {
      if (tracedRays[i][j].rayInBounds != 0) {
        summedDistance = tracedRays[i][j].summedDistance;
        curNormal = tracedRays[i][j].planeNormal;
        curPointOfIntersect = tracedRays[i][j].pointOfIntersect;
        vI = curPointOfIntersect - tracedRays[i][j].rayOrigin;
        vR = vI - ((2 * dot(curNormal, vI)) * curNormal);

        Ray ray(curPointOfIntersect, vR.normalized());
        Intersection intersection(ray);

        if (scene->intersect(intersection)) {
          tracedRay.rayInBounds = true;
          tracedRay.interDistance = intersection.t;
          tracedRay.summedDistance = summedDistance + intersection.t;
          tracedRay.pointOfIntersect = intersection.pointOfIntersect;
          tracedRay.rayOrigin = ray.origin;
          tracedRay.rayDirection = ray.direction;
          tracedRay.planeNormal = intersection.normalAtPOI;
          tracedRays[i+1].push_back(tracedRay);
        } else {
          tracedRay.rayInBounds = false;
          tracedRays[i+1].push_back(tracedRay);
        }
      } else {
        tracedRay.rayInBounds = false;
        tracedRays[i+1].push_back(tracedRay);
      }
    }
  }
  std::vector<float> raySummedDistances;
  for (int j = 0; j < tracedRays[bounceCount].size(); j++) {
    Vector returnRay = Point(0.0f, 0.0f, 0.0f) -
    tracedRays[bounceCount][j].pointOfIntersect;
    float totalRayDistance = tracedRays[bounceCount][j].summedDistance +
    returnRay.length();
    raySummedDistances.push_back(totalRayDistance);
  }

  if (dataSaver == 0 || dataSaver == 2) {
    std::ofstream totalRayDistanceDataN;
    totalRayDistanceDataN.open("totalRayDistanceDataN.txt");

    for (int i = 0; i < raySummedDistances.size(); i++) {
      if (tracedRays[0][i].rayInBounds != 0) {
        totalRayDistanceDataN << raySummedDistances[i] << "\n";
      }
    }

    totalRayDistanceDataN.close();
    std::cout << "---totalRayDistanceDataN.txt file written---" << '\n';

    std::ofstream totalRayDistanceDataC;
    totalRayDistanceDataC.open("totalRayDistanceDataC.txt");

    for (int i = 0; i < raySummedDistances.size(); i++) {
      if (tracedRays[0][i].rayInBounds != 0) {
        totalRayDistanceDataC << raySummedDistances[i] << ", ";
      }
    }

    totalRayDistanceDataC.close();
    std::cout << "---totalRayDistanceDataC.txt file written---" << '\n';
  }

  if(dataSaver == 1 || dataSaver == 2) {
    std::ofstream bounceData;
    bounceData.open("bounceData.txt");

    for (int i = 0; i < bounceCount; i++) {
      bounceData << "Origin-xyz: ";
      bounceData << tracedRays[i][1036975].rayOrigin.x << ", " <<
      tracedRays[i][1036975].rayOrigin.y << ", " <<
      tracedRays[i][1036975].rayOrigin.z << '\n';
      bounceData << "Direction-xyz: ";
      bounceData << tracedRays[i][1036975].rayDirection.x << ", " <<
      tracedRays[i][1036975].rayDirection.y << ", " <<
      tracedRays[i][1036975].rayDirection.z << '\n';
      bounceData << "rayInBounds: " << tracedRays[i][1036975].rayInBounds
      << '\n' << '\n';
    }
    bounceData << "tracedRays[x].size(): " << tracedRays[bounceCount].size()
    << '\n';
    bounceData.close();
    std::cout << "---BounceData.txt file written---" << '\n' << '\n';
  }
}

void RayTracer::traceScene(ShapeSet* scene) {

  width = SCREEN_WIDTH;
  height = SCREEN_HEIGHT;

  PerspectiveCamera camera(Point(0.0f, 0.0f, 0.0f), Vector(0.0f, 0.0f, 1.0f),
  Vector(), 25.0f * PI / 180.0f, (float)width / (float)height);

  rayTrace(&camera, scene);
}
