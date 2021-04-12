#ifndef IMAGER_H
#define IMAGER_H

#include <cstdio>
#include <vector>
#include "ray.h"

class Imager {
protected:
FILE* pgmimg;
int width = 1920;
int height = 1080;
std::vector<TracedRay> tracedPixels;
//int image[width][height];

public:
  Imager();
  ~Imager();
  //void saveImage(const std::vector<TracedRay> &tracedRays);
  void writeImage(std::vector<TracedRay> *tracedRays);
};

#endif // IMAGER_H
