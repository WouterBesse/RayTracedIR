#include <iostream>
#include "./sampleconv.h"

class Convolution
{
public:
  Convolution(std::vector<float>);
  ~Convolution();
  float getSamp(float);
private:
  std::vector<float> ImpulseResponse;
  std::vector<SampleConv> Convs;
  int SampleLength;
  int Counter;

};
