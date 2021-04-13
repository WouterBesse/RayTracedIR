#ifndef RAYTRACER_H
#define RAYTRACER_H

#include "camera.h"
#include "shape.h"
#include "vectormath.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdio>

#define SCREEN_WIDTH 10
#define SCREEN_HEIGHT 10

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

class RayTracer {
public:
  int width;
  int height;
  std::vector<std::vector<float>> raySummedDistances;
  std::vector<float> tempSummedD;
  std::vector<int> delayTimesSamples;

  RayTracer(int);
  ~RayTracer();
  void rayTrace(Camera* camera, ShapeSet* scene);
  void traceScene(ShapeSet* scene, float, float, float);
  std::vector<int> getRaySum();
  int sampleRate;
};

#endif // RAYTRACER_H
