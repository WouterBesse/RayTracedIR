#include <iostream>
#include "../headers/convolution.h"

Convolution::Convolution(std::vector<float> IRP){
  ImpulseResponse = IRP;
  SampleLength = IRP.size();
  Counter = 0;
  Convs.reserve(SampleLength + 1);
}

Convolution::~Convolution() {

}

float Convolution::getSamp(float CurSampy) {
  float Output = 0;
  //Makes a new Class instance for each sample that's put in.
  //That sample plays back the Impulse Response and multiplies it with the og sample it got.
  //Once it has played the full Impulse Response has played it gets removed.

  //Remove instance when it has played
  if(Counter >= SampleLength) {
    Convs.erase(Convs.begin());
  }

  //Makes a new IR instance
  Convs.push_back(SampleConv(ImpulseResponse, CurSampy));
  //Adds all Impulse Response values
  for(long long unsigned int i = 0; i < Convs.size(); ++i) {
    Output += Convs[i].getSamp();//}
  }
  ++Counter;
  return Output;
}
