#include "ray.h"

Ray::Ray(const Point& origin, const Vector& direction, float tMax):
origin(origin),
direction(direction),
tMax(tMax)
{
}

Ray::~Ray() {
}

Intersection::Intersection(const Ray& ray):
ray(ray),
t(ray.tMax),
aPlane(NULL)
{
}

Intersection::~Intersection() {
}

bool Intersection::intersectedPlane() const {
  return (aPlane != NULL);
}

void Intersection::setPointOfIntersect() {
  pointOfIntersect = ray.origin + ray.direction * t;
  //pointOfIntersect = ray.pointOfIntersect;
}
/*
  bool Intersection::intersectedBounds() const {
    return (inBounds = true);
  }
*/
