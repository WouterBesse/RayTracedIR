#include "../headers/shape.h"

ShapeSet::ShapeSet() {
}

ShapeSet::~ShapeSet() {
}

void ShapeSet::addPlane(Plane* plane) {
  planes.push_back(plane);
}

bool ShapeSet::intersect(Intersection& intersection) {
  bool intInBounds = false;
  for (std::vector<Plane*>::iterator iter = planes.begin();
  iter != planes.end();
  ++iter) {
    Plane *curPlane = *iter;
    if (curPlane->intersect(intersection)) {
      intInBounds = true;
    }
  }
  return intInBounds;
}

Plane::Plane(Point& coordA, Point& coordB, Point& coordC) {
  vertA = coordA;
  vertB = coordB;
  vertC = coordC;
  edgeAB = vertA - vertB;
  edgeAC = vertA - vertC;
  normal = cross(edgeAB, edgeAC);
  normal = normal.normalized();
  position = vertA;
}

Plane::~Plane() {
}

bool Plane::intersect(Intersection& intersection) {
  float dDotN = dot(intersection.ray.direction, normal);
  if (dDotN == 0.0f) {
    return false;
  }
  float t = dot(position - intersection.ray.origin, normal) / dDotN;
  if (t <= RAY_T_MIN || t >= intersection.t) {
    return false;
  }
  bool curIntInBounds = inBounds(intersection, t);
  if (curIntInBounds != 1) {
    return false;
  }
  intersection.t = t;
  intersection.aPlane = this;
  return true;
}

bool Plane::inBounds(Intersection& intersection, float t) {
  Point intPoint = intersection.ray.origin + intersection.ray.direction * t;
  bool pit = false;
  if (pointInTriangle(intPoint, vertA, vertB, vertC)) {
    pit = true;
    Vector vPB = vertB - intPoint;
    Vector vPC = vertC - intPoint;
    Vector nAtPOI = cross(vPB, vPC);
    intersection.normalAtPOI = nAtPOI.normalized();
    intersection.pointOfIntersect = intPoint;
  }
  return pit;
}

bool Plane::sameSide(Point p1, Point p2, Point a ,Point b) {
  Vector cp1 = cross(b - a, p1 - a);
  Vector cp2 = cross(b - a, p2 - a);
  if (dot(cp1, cp2) >= 0.0f) {
    return true;
  } else {
    return false;
  }
}

bool Plane::pointInTriangle(Point p, Point a, Point b, Point c) {
  if (sameSide(p, a, b, c) && sameSide(p, b, a, c) && sameSide(p, c, a, b)) {
    return true;
  } else {
    return false;
  }
}
