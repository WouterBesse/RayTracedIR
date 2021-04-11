#ifndef RAYTRACER_H
#define RAYTRACER_H

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

class RayTracer {
public:
  int width;
  int height;

  RayTracer();
  ~RayTracer();
  void rayTrace(Camera* camera, ShapeSet* scene);
  void traceScene(ShapeSet* scene);
};

#endif // RAYTRACER_H
