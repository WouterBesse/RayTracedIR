#include <iostream>
#include "../headers/convolution.h"

Convolution::Convolution(std::vector<float> IRP){
  ImpulseResponse = IRP;
  SampleLength = IRP.size();
  Counter = 0;
  Convs.reserve(SampleLength);
}

Convolution::~Convolution() {

}

float Convolution::getSamp(float CurSamp) {
  float Output = 0;
  if(Counter >= SampleLength) {
    Convs.erase(Convs.begin());
  }
  Convs.push_back(SampleConv(ImpulseResponse, CurSamp));
  for(long long unsigned int i = 0; i < Convs.size(); ++i) {
    Output += Convs[i].getSamp();
  }
  Output = Output / Convs.size();
  ++Counter;
  return Output;
}
