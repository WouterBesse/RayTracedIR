#ifndef SHAPE_H
#define SHAPE_H

#include <vector>
#include "ray.h"
#include <iostream>
//#include "time.h"

class ShapeSet {
//protected:


public:
  ShapeSet();
  virtual ~ShapeSet();
  void addPlane(Plane* plane);
  virtual bool intersect(Intersection& intersection);
//  virtual bool intersectTriPlanes(Intersection& intersection);
  std::vector<Plane*> planes;

};

class Plane {
protected:
  Point position;
  Vector normal;
  Point vertA;
  Point vertB;
  Point vertC;
  Vector edgeAB;
  Vector edgeAC;

public:
  Plane(Point& coordA, Point& coordB, Point& coordC);
  virtual ~Plane();
  virtual bool intersect(Intersection& intersection);
  virtual bool inBounds(Intersection& intersection);
  virtual bool sameSide(Point p1, Point p2, Point a ,Point b);
  virtual bool pointInTriangle(Point p, Point a, Point b, Point c);
};

#endif // SHAPE_H
