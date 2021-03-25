#pragma once
#include <iostream>
#include <vector>

class ringBuffer
{
public:
  ringBuffer(int length);
  ~ringBuffer();

  void push(double dInput);
  double getSample(int iDelay);
  double getSamples(int iDelays[],float fVolumes[]);

protected:

  double dInput;
  int iDelay;
  int iDelays;
  float fVolumes;
  int iRingBuf = 0; //iteration of the ring buffer
  double sample;
  //int ringBuf[0];
  std::vector<double> ringBuf;
  int length;
  double out = 0.0;


};
