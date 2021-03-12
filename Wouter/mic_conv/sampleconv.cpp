#include <iostream>
#include "../headers/sampleconv.h"

SampleConv::SampleConv(std::vector<float> IRP, float IS){
  IR = IRP;
  InputSample = IS;
  CountIr = 0;
}

SampleConv::~SampleConv() {

}

float SampleConv::getSamp() {
  float OutputSample = InputSample * IR[CountIr];
  CountIr += 1;
  if (CountIr >= IR.size()) {
    CountIr = 0;
  }
  return OutputSample;
}
