#include <iostream>
#include "../headers/convolution.h"

Convolution::Convolution(std::vector<float> IRP){
  ImpulseResponse = IRP;
  SampleLength = IRP.size();
  Counter = 0;
  Convs.reserve(SampleLength + 1);
  InputVector.reserve(SampleLength + 1);
}

Convolution::~Convolution() {

}

__global__
void gpuCalc(std::vector<float> IR, std::vector<float> IN, int i) {
    int th = threadIdx.x + i; // the id number of our thread
    outputvar += IR[th] * IN[th];

}

float Convolution::getSamp(float CurSampy) {
  float Output = 0;
  outputvar = 0;
  //Makes a new Class instance for each sample that's put in.
  //That sample plays back the Impulse Response and multiplies it with the og sample it got.
  //Once it has played the full Impulse Response has played it gets removed.

  //Remove float from InputVector when it has played
  if(Counter >= SampleLength) {
    InputVector.pop_back();
  }
  //std::cout << "Kaas\n";
  InputVector.insert(InputVector.begin(), CurSampy);
  //InputVector.push_back(CurSampy);
  //Makes a new IR instance
  //Convs.push_back(SampleConv(ImpulseResponse, CurSampy));
  //Adds all Impulse Response values
  //  for(size_t i = 0; i < InputVector.size(); ++i) {
  //    Output += InputVector[i] * ImpulseResponse[i];
  //  }
  for(int i = 0; i < InputVector.size()) {
      if (InputVector.size() - i < 1024) {
          gpuCalc<<<1, InputVector.size() - i>>>(ImpulseResponse, InputVector, i);
          cudaDeviceSynchronize();
          i += InputVector - i;
      } else {
          gpuCalc<<<1, 1024>>>(ImpulseResponse, InputVector, i);
          cudaDeviceSynchronize();
          i += 1024;
      }
  }
  ++Counter;
  //std::cout << Output << "\n";
  //Output = Output / InputVector.size() * 50;
  //std::cout << Output << "\n";
  return outputvar;
}
