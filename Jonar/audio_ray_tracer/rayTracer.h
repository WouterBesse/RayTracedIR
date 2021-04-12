/*
#
# 2021 Jonar Verbart
# Part of RayTracedIR by Wouter Besse, Nino Saglia and Jonar Verbart
#
*/

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
  int x;  // birth pixel x of primary ray
  int y;  // birth pixel y of primary ray
  bool rayInBounds; // has a ray intersected within a plane
  float interDistance;  // distance to closest intersection
  float summedDistance; // distance of primary ray + bounces + return ray
  Point pointOfIntersect; // xyz of the ray's closest intersection
  Point rayOrigin;  // origin of the ray
  Vector rayDirection;  // direction of the ray
  Vector planeNormal; // normal of the plane that the ray has intersected with
};

class RayTracer {
public:
  int width;
  int height;

  RayTracer();
  ~RayTracer();
  void rayTrace(Camera* camera, ShapeSet* scene); // ray tracing algorithm
  void traceScene(ShapeSet* scene); // put a scene through the algorithm
};

#endif // RAYTRACER_H
