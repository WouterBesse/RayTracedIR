#include "../headers/ray.h"

Ray::Ray(const Point &origin, const Vector &direction, float tMax) :
        origin(origin),
        direction(direction),
        tMax(tMax) {
}

Ray::~Ray() {
}

Intersection::Intersection(const Ray &ray) :
        ray(ray),
        t(ray.tMax),
        aPlane(NULL) {
}

Intersection::~Intersection() {
}

bool Intersection::intersectedPlane() const {
    return (aPlane != NULL);
}
