#include <iostream>
#include "./sampleconv.h"

class Convolution
{
public:
  Convolution(std::vector<float>);
  ~Convolution();
  float getSamp(float);
  __global__ void gpuCalc(std::vector<float>, std::vector<float>, int);
  __managed__ float outputvar;
private:
  std::vector<float> ImpulseResponse;
  std::vector<float> InputVector;
  std::vector<SampleConv> Convs;
  int SampleLength;
  int Counter;

};
