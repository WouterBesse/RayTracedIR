#ifndef RAY_H
#define RAY_H

#include "vectormath.h"

// In order to prevent bouncing rays self-intersecting
#define RAY_T_MIN 0.0001f

// 'Infinite' distance, used as a default value
#define RAY_T_MAX 1.0e30f

struct Ray {

  Point origin;
  Point pointOfIntersect;
  Vector direction;
  float tMax;

  Ray(const Point& origin, const Vector& direction, float tMax = RAY_T_MAX);
  virtual ~Ray();
};
/*
struct TracedRay {
  int x;
  int y;
  bool rayIntersected;
  bool rayInBounds;
  float interDistance;
  TracedRay();
  ~TracedRay();
};
*/
class Plane;

struct Intersection {
  Ray ray;
  float t;
  Plane *aPlane;

  Intersection(const Ray& ray);
  virtual ~Intersection();

  bool intersectedPlane() const;
  void setPointOfIntersect();
//  bool intersectedBounds() const;
};

#endif // RAY_H
