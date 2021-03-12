#include <iostream>
#include "../headers/sampleconv.h"
#include <fmt/format.h>

SampleConv::SampleConv(std::vector<float> IRP, float IS){
  IR = IRP;
  InputSample = IS;
  CountIr = 0;
}

SampleConv::~SampleConv() {

}

float SampleConv::getSamp() {
  //fmt::print("IR:{}",fmt::join(IR,"\n"));
  //std::cout << CountIr << "Counter \n";
  float OutputSample = InputSample * IR[CountIr];
  CountIr += 1;

  if (CountIr >= IR.size()) {
      //std::cout << "KAAS\n";
    CountIr = 0;
  }
  return OutputSample;
}
