#include "ray.h"
#include <iostream>

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
  ray.pointOfIntersect = ray.origin + dot(ray.direction, t);
  std::cout << "Ray direction x: " << ray.direction.x << "Ray direction y: " << ray.direction.y << "Ray direction z: " << ray.direction.z  << "\n";
//  std::cout << ray.pointOfIntersect << "\n";
}
/*
  bool Intersection::intersectedBounds() const {
    return (inBounds = true);
  }
*/
