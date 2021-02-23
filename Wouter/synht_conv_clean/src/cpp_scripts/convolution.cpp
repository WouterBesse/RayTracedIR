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

float Convolution::getSamp(float CurSampy) {
  float Output = 0;
  if(Counter >= SampleLength) {
    Convs.erase(Convs.begin());
  }
  Convs.push_back(SampleConv(ImpulseResponse, CurSampy));
  for(long long unsigned int i = 0; i < Convs.size(); ++i) {
//    if(i==0) {
//        std::cout << Convs[0].getSamp() << "First sample\n";
//    } else if(i==1){
//        std::cout << Convs[1].getSamp() << "Secondsample\n";
//    } else {
    Output += Convs[i].getSamp();//}
  }
  //std::cout << Convs[0].InputSample << "First Input\n";
//  if(Output > 1) {
//      std::cout << "TO MUCH!\n";
//  }
//    std::cout << Output << "Verb output\n";
  //Output = Output / Convs.size();
  ++Counter;
  return Output;
}
