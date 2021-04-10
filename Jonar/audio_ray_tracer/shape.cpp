#include "shape.h"

ShapeSet::ShapeSet() {
}

ShapeSet::~ShapeSet() {
}

void ShapeSet::addPlane(Plane* plane) {
  planes.push_back(plane);
}

bool ShapeSet::intersect(Intersection& intersection) {
  //bool doesIntersect = false;
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
/*
bool ShapeSet::intersectTriPlanes(Intersection& intersection) {
  bool doesIntersect = false;
  for (std::vector<Plane*>::iterator iter = planes.begin();
  iter != planes.end();
  ++iter) {
    Plane *curPlane = *iter;
    if (curPlane->inBounds(intersection))
    doesIntersect = true;
  }
  return doesIntersect;
}
*/

Plane::Plane(Point& coordA, Point& coordB, Point& coordC) {
  vertA = coordA;
  vertB = coordB;
  vertC = coordC;
  //std::cout << "vertA.z: " << vertA.z << '\n';
  //std::cout << "vertB.z: " << vertB.z << '\n';
  //std::cout << "vertC.z: " << vertC.z << '\n';
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
    //std::cout << "dDotN == 0 is true" << '\n';
    return false;
  }
  float t = dot(position - intersection.ray.origin, normal) / dDotN;
  if (t <= RAY_T_MIN || t >= intersection.t) {
    //std::cout << "t outside of min to max" << '\n';
    return false;
  }
  //intersection.setPointOfIntersect(t);
  bool curIntInBounds = inBounds(intersection, t);
  if (curIntInBounds != 1) {
    //std::cout << "inBounds is false or t bigger than intersection.t" << '\n';
    return false;
    //
  }
  //std::cout << "Hallo hallo hallo" << '\n';
  intersection.t = t;
  intersection.aPlane = this;
  return true;
}
//t >= intersection.t;
/*
float Plane::getSX() {
  float smallestX = coords[0].x;
  for (i = 1; i < 3; i++) {
    if (smallestX > coords[i].x) {
      smallestX = coords[i].x;
    }
  }
  return smallestX;
}
*/

bool Plane::inBounds(Intersection& intersection, float t) {
  Point intPoint = intersection.ray.origin + intersection.ray.direction * t;
  bool pit = false;
  //std::cout << "intPointXYZ: " << intPoint.x << '\t' <<
  //intPoint.y << '\t' <<
  //intPoint.z << '\n';
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
/*
  srand((unsigned)time(NULL));

  float r1 = (float) rand()/RAND_MAX;
  float r2 = (float) rand()/RAND_MAX;
  float r3 = (float) rand()/RAND_MAX;
  float r4 = (float) rand()/RAND_MAX;
  if(r1 + r2 > 1) {
    r1 = 1 - r1;
    r2 = 1 - r2;
  }
  if(r3 + r4 > 1) {
    r3 = 1 - r3;
    r4 = 1 - r4;
  }

  Point onPlane1 = vertA + (r1 * edgeAB) + (r2 * edgeAC);
  Point onPlane2 = vertA + (r3 * edgeAB) + (r4 * edgeAC);
*/

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
