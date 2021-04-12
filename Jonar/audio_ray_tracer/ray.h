/*
#
# 2021 Jonar Verbart
# Part of RayTracedIR by Wouter Besse, Nino Saglia and Jonar Verbart
#
*/

#ifndef RAY_H
#define RAY_H

#include "vectormath.h"
#include "iostream"

// Prevent rays from intersecting with their origin
#define RAY_T_MIN 0.0001f

// Limit for 'infinite' distances
#define RAY_T_MAX 1.0e30f

struct Ray {
  Point origin;
  Vector direction;
  float tMax;

  Ray(const Point& origin, const Vector& direction, float tMax = RAY_T_MAX);
  virtual ~Ray();
};

class Plane;

struct Intersection {
  Ray ray;
  float t;  // t is standard notation for the calculated intersection distance
  Plane *aPlane;
  Point pointOfIntersect;
  Vector normalAtPOI;

  Intersection(const Ray& ray);
  virtual ~Intersection();

  bool intersectedPlane() const;
};

#endif // RAY_H
