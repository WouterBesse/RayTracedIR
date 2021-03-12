#include <iostream>
#include <list>
#include "../headers/synth.h"

Synth::Synth(int oscy1, int oscy2, int oscy3, float freq, float amp, float phase) {
  this->freq = freq;
  this->amp = amp;
  this->phase = phase;
  osc1 = oscy1;
  osc2 = oscy2;
  osc3 = oscy3;
  // Logic setting all voices to their respective waveform
}

Synth::~Synth() {
  delete wav1;
  delete wav2;
  delete wav3;
}

void Synth::setSampleRate(int SR) {
  samplerate = SR;
    if (osc1 == 1) {
        wav1 = new Sine(freq, amp, phase, samplerate);
    } else if (osc1 == 2) {
        wav1 = new Square(freq, amp, phase, samplerate);
    } else {
        wav1 = new Triangle(freq, amp, phase, samplerate);
    }
    if (osc2 == 1) {
        wav2 = new Sine(freq, amp, phase, samplerate);
    } else if (osc2 == 2) {
        wav2 = new Square(freq, amp, phase, samplerate);
    } else {
        wav2 = new Triangle(freq, amp, phase, samplerate);
    }
    if (osc3 == 1) {
        wav3 = new Sine(freq, amp, phase, samplerate);
    } else if (osc3 == 2) {
        wav3 = new Square(freq, amp, phase, samplerate);
    } else {
        wav3 = new Triangle(freq, amp, phase, samplerate);
    }
}

float Synth::getSValAdd(float freq) {
  sBuf = wav1->getSamp(freq) + wav2->getSamp(freq) + wav3->getSamp(freq);
  sBufdiv = sBuf / 3;
    freq = 0;
    if(freq = 0) {
        return 0;
    } else {
        return sBufdiv;
    }
  //  std::cout << freq << "freqsynth\n";

}

float Synth::getSValMult(float freq) {
  sBuf = wav1->getSamp(freq) * wav2->getSamp(freq) * wav3->getSamp(freq);
  sBufdiv = sBuf * 100;
    if(freq) {
        return 0;
    } else {
        return sBufdiv;
    }
}

// Generates 7 random values for the melody
std::vector<float> Synth::MelodyMaker() {
  std::vector<float> NewMel = {};
  for(unsigned int i = 0; i < 7; i++) {
    NewMel.push_back (500 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(2000 - 500))));
  };
  return NewMel;
}
