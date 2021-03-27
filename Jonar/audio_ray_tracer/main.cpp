#include "camera.h"
#include "shape.h"
//#include "imager.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdio>

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080


struct TracedRay {
  int x;
  int y;
  bool rayIntersected;
  bool rayInBounds;
  float interDistance;
  Point pointOfIntersect;
};

void rayTrace(Camera* camera, ShapeSet* scene) {
TracedRay tracedRay;
std::vector<TracedRay> tracedRays;

int width = SCREEN_WIDTH;
int height = SCREEN_HEIGHT;

  for (int x = 0; x < width; x++) {
    for (int y = 0; y < height; y++) {
      Vector2 screenCoord((2.0f*x) / width - 1.0f,
      (-2.0f*y) / height + 1.0f);
      Ray ray = camera->makeRay(screenCoord);

      Intersection intersection(ray);
      if (scene->intersect(intersection)) {
        tracedRay.x = x;
        tracedRay.y = y;
        tracedRay.rayIntersected = true;
        tracedRay.rayInBounds = true;
        tracedRay.interDistance = intersection.t;
        tracedRay.pointOfIntersect = intersection.pointOfIntersect;
        tracedRays.push_back(tracedRay);
      } else {
        tracedRay.x = x;
        tracedRay.y = y;
        tracedRay.rayIntersected = true;
        tracedRay.rayInBounds = false;
        tracedRay.interDistance = intersection.t;
        tracedRays.push_back(tracedRay);
      }
    }
  }

/*
  for (std::vector<TracedRay>::iterator iter = tracedRays.begin();
  iter != tracedRays.end(); ++iter) {
    std::cout << *iter.x << '\n';
  }
*/

std::ofstream debugData;
debugData.open("debugData.txt");

for (int i = 0; i < tracedRays.size(); i++) {
  if (tracedRays[i].rayInBounds != 0) {
  debugData << "x: " << tracedRays[i].x << '\t';
  debugData << "y: " << tracedRays[i].y << '\t';
  //intersectionData << "intSct: " << tracedRays[i].rayIntersected << '\t';
  debugData << "inBounds: " << tracedRays[i].rayInBounds << '\t';
  debugData << "intDst: " << tracedRays[i].interDistance << '\t';
  debugData << "pointOfIntersectXYZ: " << '\t' <<
  tracedRays[i].pointOfIntersect.x << " " <<
  tracedRays[i].pointOfIntersect.y << " " <<
  tracedRays[i].pointOfIntersect.z << '\n';
}
}
debugData.close();
std::cout << "---debugData.txt file written---" << '\n';

std::ofstream intersectionDataN;
intersectionDataN.open("intersectionDataN.txt");

for (int i = 0; i < tracedRays.size(); i++) {
  if (tracedRays[i].rayInBounds != 0) {
  intersectionDataN << tracedRays[i].interDistance << '\n';
}
}

intersectionDataN.close();
std::cout << "---intersectionDataN.txt file written---" << '\n';

std::ofstream intersectionDataC;
intersectionDataC.open("intersectionDataC.txt");

for (int i = 0; i < tracedRays.size(); i++) {
  if (tracedRays[i].rayInBounds != 0) {
  intersectionDataC << tracedRays[i].interDistance << ", ";
}
}

intersectionDataC.close();
std::cout << "---intersectionDataC.txt file written---" << '\n';

// ---make image file---

  int tempImage[height][width];
  int temp = 0;
  int xPixel = 0;
  int yPixel = 0;

  for (int i = 0; i < tracedRays.size(); i++) {
    if (tracedRays[i].rayInBounds != 0) {
      xPixel = tracedRays[i].x;
      yPixel = tracedRays[i].y;
      tempImage[yPixel][xPixel] = 0;
    } else {
      xPixel = tracedRays[i].x;
      //std::cout << "xPixel: " << xPixel << '\n';
      yPixel = tracedRays[i].y;
      tempImage[yPixel][xPixel] = 255;
    }
  }
    /*
    if(xPixel >= width - 1) {
      yPixel += 1;
      xPixel = 0;
    } else {
      xPixel = xPixel + 1;
    }
  }
*/
  /*
  int temp = 0;
  int imageWidth = 13;
  int imageHeight = 13;
  int image[13][13] = {
	{ 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15 },
	{ 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31},
	{ 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47},
	{ 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63},
	{ 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79},
	{ 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95 },
	{ 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111},
	{ 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127},
	{ 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143},
	{ 159, 159, 159, 159, 159, 159, 159, 159, 159, 159, 159, 159, 159},
	{ 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175},
	{ 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191},
	{ 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207}
	};
*/
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

int main(int argc, char *argv[]) {

  int width = SCREEN_WIDTH;
  int height = SCREEN_HEIGHT;
  //int pixelCount = width * height;

  PerspectiveCamera camera(Point(0.0f, 0.0f, 0.0f), Vector(0.0f, 0.0f, 1.0f),
  Vector(), 25.0f * PI / 180.0f, (float)width / (float)height);

  Point coordA;
  Point coordB;
  Point coordC;

  coordA.x = 0.0f;
  coordA.y = 0.0f;
  coordA.z = 3.0f;
  coordB.x = -1.5f;
  coordB.y = 0.0f;
  coordB.z = 3.0f;
  coordC.x = 0.0f;
  coordC.y = 1.0f;
  coordC.z = 3.0f;

/*
  coordA.x = 3.0f;
  coordA.y = 0.0f;
  coordA.z = 4.0f;
  coordB.x = 10.0f;
  coordB.y = 3.0f;
  coordB.z = 0.0f;
  coordC.x = 0.0f;
  coordC.y = 12.0f;
  coordC.z = 3.0f;

//diagonale stippen
  coordA.x = 0.0f;
  coordA.y = 0.0f;
  coordA.z = 3.0f;
  coordB.x = 4.0f;
  coordB.y = 0.0f;
  coordB.z = 3.0f;
  coordC.x = 0.0f;
  coordC.y = 4.0f;
  coordC.z = 3.0f;
*/


  ShapeSet scene;
  Plane triangle1(coordA, coordB, coordC);
/*
  coordA.x = 3.0f;
  coordA.y = 0.0f;
  coordA.z = 0.0f;
  coordB.x = 3.0f;
  coordB.y = 0.0f;
  coordB.z = 4.0f;
  coordC.x = 3.0f;
  coordC.y = 4.0f;
  coordC.z = 0.0f;
  Plane triangle2(coordA, coordB, coordC);
*/
  //Plane floor(Point(0.0f, 0.0f, 0.0f), Vector());
	scene.addPlane(&triangle1);
  //scene.addPlane(&triangle2);
  //std::cout << "scene[0].coordA.y: " << scene.planes[0]->vertA.y << '\n';

  rayTrace(&camera, &scene);
}
