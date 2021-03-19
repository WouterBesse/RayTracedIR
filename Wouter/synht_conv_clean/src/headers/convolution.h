#include <iostream>
#include "./sampleconv.h"
#include <immintrin.h>
#include <thread>
#include <mutex>

class Convolution
{
public:
  Convolution(std::vector<float>);
  ~Convolution();
  float getSamp(float);
  void ConvGenerator(std::vector<float>, std::vector<float>, int);
private:
  std::vector<float> ImpulseResponse;
  std::vector<float> InputVector;
  std::vector<SampleConv> Convs;
  int SampleLength;
  int Counter;
  float Output;
//  __m256 inputs;
//  __m256 impulses;
//  __m256 outy
//  __m256 tmp3;

};
