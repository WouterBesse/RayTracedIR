#include <iostream>
#include <vector>

class SampleConv
{
public:
  SampleConv(std::vector<float>, float);
  ~SampleConv();
  float getSamp();
private:
  std::vector<float> IR;
  float InputSample;
  long long unsigned int CountIr;
};
