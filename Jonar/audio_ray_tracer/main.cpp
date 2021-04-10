#include "camera.h"
#include "shape.h"
#include "vectormath.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdio>

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080


struct TracedRay {
  int x;
  int y;
  bool rayInBounds;
  float interDistance;
  float summedDistance;
  Point pointOfIntersect;
  Vector rayDirection;
  Point rayOrigin;
  Vector planeNormal;
};

void rayTrace(Camera* camera, ShapeSet* scene) {
  int width = SCREEN_WIDTH;
  int height = SCREEN_HEIGHT;
  int bounceCount = 5; // make >= 1 (real bounce count is bounceCount-1, as 1 is primary ray)

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
        /*if(tracedRay.rayInBounds){
        std::cout << "pointOfIntersect XYZ: " << intersection.pointOfIntersect.x << '\t' <<
        intersection.pointOfIntersect.y << '\t' << intersection.pointOfIntersect.z << '\n';
      } */
        tracedRay.rayOrigin = ray.origin;
        tracedRay.rayDirection = ray.direction;
        tracedRay.planeNormal = intersection.normalAtPOI;
        tracedRays[0].push_back(tracedRay);
      } else {
        tracedRay.x = x;
        tracedRay.y = y;
        tracedRay.rayInBounds = false;
        // tracedRay.interDistance = intersection.t;
        tracedRays[0].push_back(tracedRay);
      }
    }
  }

  std::ofstream debugData;
  debugData.open("debugData.txt");

  for (int i = 0; i < tracedRays[0].size(); i++) {
    if (tracedRays[0][i].rayInBounds != 0) {
    debugData << "x: " << tracedRays[0][i].x << '\t';
    debugData << "y: " << tracedRays[0][i].y << '\t';
    //intersectionData << "intSct: " << tracedRays[i].rayIntersected << '\t';
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

  Vector curNormal;
  Point curPointOfIntersect;
  Vector vI;
  Vector vR;
  float summedDistance;
  // NOW DO THE RECURSIVE BOUNCING
  std::cout << '\n' << "Tracing rays..." << '\n';
  for (int i = 0; i < bounceCount; i ++) {
    for (int j = 0; j < tracedRays[i].size(); j++) {
      if (tracedRays[i][j].rayInBounds != 0) {
        summedDistance = tracedRays[i][j].summedDistance;
        curNormal = tracedRays[i][j].planeNormal;
        curPointOfIntersect = tracedRays[i][j].pointOfIntersect;
        vI = curPointOfIntersect - tracedRays[i][j].rayOrigin;
        //vI = vI.normalized();
        vR = vI - ((2 * dot(curNormal, vI)) * curNormal);
        //vR = vR.normalized();

        Ray ray(curPointOfIntersect, vR.normalized());
        Intersection intersection(ray);
        //std::cout << "rayOrigin XYZ: " << ray.origin.x << '\t' <<
        //ray.origin.y << '\t' << ray.origin.z << '\n';
        //std::cout << "curPointOfIntersect XYZ: " << curPointOfIntersect.x << '\t' <<
        //curPointOfIntersect.y << '\t' << curPointOfIntersect.z << '\n';
        /*
        std::cout << "Ray-Origin XYZ: " << ray.origin.x << '\t' <<
        ray.origin.y << '\t' << ray.origin.z << '\n';
        std::cout << "Ray-Direction XYZ: " << ray.direction.x << '\t' <<
        ray.direction.y << '\t' << ray.direction.z << '\n';
*/
        if (scene->intersect(intersection)) {
          //std::cout << "till here" << '\n';
          //tracedRay.x = x;
          //tracedRay.y = y;
          tracedRay.rayInBounds = true;
          tracedRay.interDistance = intersection.t;
          tracedRay.summedDistance = summedDistance + intersection.t;
          tracedRay.pointOfIntersect = intersection.pointOfIntersect;
          tracedRay.rayOrigin = ray.origin;
          tracedRay.rayDirection = ray.direction;
          tracedRay.planeNormal = intersection.normalAtPOI;
          tracedRays[i+1].push_back(tracedRay);
        } else {
          //tracedRay.x = x;
          //tracedRay.y = y;
          tracedRay.rayInBounds = false;
          //tracedRay.interDistance = intersection.t;
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
    Vector returnRay = Point(0.0f, 0.0f, 0.0f) - tracedRays[bounceCount][j].pointOfIntersect;
    float totalRayDistance = tracedRays[bounceCount][j].summedDistance + returnRay.length();
    //std::cout << "totalRayDistance: " << totalRayDistance << '\n';
    raySummedDistances.push_back(totalRayDistance);
  }

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


  std::ofstream bounceData;
  bounceData.open("bounceData.txt");

  for (int i = 0; i < bounceCount; i++) {
    // 1036975
    bounceData << "Origin-xyz: ";
    bounceData << tracedRays[i][1036975].rayOrigin.x << ", " <<
    tracedRays[i][1036975].rayOrigin.y << ", " <<
    tracedRays[i][1036975].rayOrigin.z << '\n';
    bounceData << "Direction-xyz: ";
    bounceData << tracedRays[i][1036975].rayDirection.x << ", " <<
    tracedRays[i][1036975].rayDirection.y << ", " <<
    tracedRays[i][1036975].rayDirection.z << '\n';
    bounceData << "rayInBounds: " << tracedRays[i][1036975].rayInBounds << '\n' << '\n';
  }
  bounceData << "tracedRays[x].size(): " << tracedRays[bounceCount].size() << '\n';
  bounceData.close();
  std::cout << "---BounceData.txt file written---" << '\n' << '\n';
}

int main(int argc, char *argv[]) {

  int width = SCREEN_WIDTH;
  int height = SCREEN_HEIGHT;
  //int pixelCount = width * height;

  PerspectiveCamera camera(Point(0.0f, 0.0f, 0.0f), Vector(0.0f, 0.0f, 1.0f),
  Vector(), 25.0f * PI / 180.0f, (float)width / (float)height);

  Point coordA;
  Point coordB;
  Point coordC;

  // triangle1
  coordA.x = 0.0f;
  coordA.y = 0.0f;
  coordA.z = 4.0f;
  coordB.x = 1.5f;
  coordB.y = 0.0f;
  coordB.z = 4.0f;
  coordC.x = 0.0f;
  coordC.y = 1.0f;
  coordC.z = 4.0f;

  ShapeSet scene;
  Plane triangle1(coordA, coordB, coordC);
	scene.addPlane(&triangle1);

  coordA.x = 0.0f;
  coordA.y = 0.0f;
  coordA.z = 3.0f;
  coordB.x = -1.5f;
  coordB.y = 0.0f;
  coordB.z = 3.0f;
  coordC.x = 0.0f;
  coordC.y = 1.0f;
  coordC.z = 3.0f;

  Plane triangle2(coordA, coordB, coordC);
	scene.addPlane(&triangle2);

  Point coordD;
  Point coordE;
  Point coordF;
  Point coordG;
  Point coordH;

  //roomABCDEFGH
  coordA.x = 3.0f;
  coordA.y = -3.0f;
  coordA.z = -6.0f;

  coordB.x = -3.0f;
  coordB.y = -3.0f;
  coordB.z = -6.0f;

  coordC.x = -3.0f;
  coordC.y = -3.0f;
  coordC.z = 6.0f;

  coordD.x = 3.0f;
  coordD.y = -3.0f;
  coordD.z = 6.0f;

  coordE.x = 3.0f;
  coordE.y = 3.0f;
  coordE.z = -6.0f;

  coordF.x = -3.0f;
  coordF.y = 3.0f;
  coordF.z = -6.0f;

  coordG.x = -3.0f;
  coordG.y = 3.0f;
  coordG.z = 6.0f;

  coordH.x = 3.0f;
  coordH.y = 3.0f;
  coordH.z = 6.0f;

  Plane triangleABE(coordA, coordB, coordE);
  scene.addPlane(&triangleABE);
  Plane triangleBFE(coordB, coordF, coordE);
  scene.addPlane(&triangleBFE);

  Plane triangleDCH(coordD, coordC, coordH);
  scene.addPlane(&triangleDCH);
  Plane triangleCGH(coordC, coordG, coordH);
  scene.addPlane(&triangleCGH);

  Plane triangleBCG(coordB, coordC, coordG);
  scene.addPlane(&triangleBCG);
  Plane triangleBGF(coordB, coordG, coordF);
  scene.addPlane(&triangleBGF);

  Plane triangleADH(coordA, coordD, coordH);
  scene.addPlane(&triangleADH);
  Plane triangleAHE(coordA, coordH, coordE);
  scene.addPlane(&triangleAHE);

  Plane triangleABD(coordA, coordB, coordD);
  scene.addPlane(&triangleABD);
  Plane triangleBCD(coordB, coordC, coordD);
  scene.addPlane(&triangleBCD);

  Plane triangleFGH(coordF, coordG, coordH);
  scene.addPlane(&triangleFGH);
  Plane triangleEFH(coordE, coordF, coordH);
  scene.addPlane(&triangleEFH);

  rayTrace(&camera, &scene);
}
