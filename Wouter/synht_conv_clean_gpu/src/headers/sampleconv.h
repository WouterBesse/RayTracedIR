#include <iostream>
#include <vector>

class SampleConv
{
public:
  SampleConv(std::vector<float>, float);
  ~SampleConv();
  float getSamp();
  float InputSample;
private:
  std::vector<float> IR;

  long long unsigned int CountIr;
};
