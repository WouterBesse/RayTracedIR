#include <iostream>
//#include "./oscillator.h"
#include "./sine.h"
#include "./square.h"
#include "./triangle.h"
#include <vector>

class Synth {
public:
  Synth(int osc1, int osc2, int osc3, float freq, float amp, float phase);
  ~Synth();
  float getSValAdd(float freq);
  float getSValMult(float freq);
  void setSampleRate(int SR);
  
  std::vector<float> MelodyMaker();
private:
  float freq;
  float amp;
  float phase;
  int samplerate;
  int osc1, osc2, osc3;
  Oscillator* wav1;
  Oscillator* wav2;
  Oscillator* wav3;
  float sBuf;
  float sBufdiv;
};
