#ifndef RAY_H
#define RAY_H

#include "vectormath.h"
#include "iostream"

// In order to prevent bouncing rays self-intersecting
#define RAY_T_MIN 0.0001f

// 'Infinite' distance, used as a default value
#define RAY_T_MAX 1.0e30f

struct Ray {

    Point origin;
    Vector direction;
    float tMax;

    Ray(const Point &origin, const Vector &direction, float tMax = RAY_T_MAX);

    virtual ~Ray();
};

class Plane;

struct Intersection {
    Ray ray;
    float t;
    Plane *aPlane;
    Point pointOfIntersect;
    Vector normalAtPOI;

    Intersection(const Ray &ray);

    virtual ~Intersection();

    bool intersectedPlane() const;
};

#endif // RAY_H
