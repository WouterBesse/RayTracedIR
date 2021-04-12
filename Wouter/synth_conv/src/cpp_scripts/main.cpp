#include <iostream>
#include <thread>
//#include "../headers/jack_module.h"
#include "../headers/synth.h"
//#include "../headers/csv.h" // Got csv parser from https://github.com/ben-strasser/fast-cpp-csv-parser
//#include "../headers/convolution.h"
#include "../headers/port_audio.h"
#include <limits>
#include <fstream>
#include <string>
#include <iterator>
#include <math.h>
#include <list>
#include <string>
#include <vector>
#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif


struct TestCallback : public AudioIODeviceCallback {

    void prepareToPlay(int sampleRate, int numSamplesPerBlock) override {
        samplerate = sampleRate;
        synthesizer.setSampleRate(sampleRate);
    }

    void process(float* input, float* output, int numSamples, int numChannels) override {
        int hs = samplerate / 2;
        for (auto i = 0; i < numSamples * 2; ++i) {
          x += 1;
          if (x % hs == 0) {
            // Sets the current frequency to the one stored in the melody vector and saves it to a store vector
            freq = mel.at(melnum);
            store.push_back (freq);
            melnum ++;
            if(melnum > 6) melnum = 0;
          }
          if (syntyp == 0) {
            output[i] = synthesizer.getSValAdd(freq);
          } else if (syntyp == 1) {
            output[i] = synthesizer.getSValMult(freq);
          } else {
            output[i] = (synthesizer.getSValMult(freq) + synthesizer.getSValAdd(freq)) / 2;
          }

           // output[i] = 0.5 * distribution(device);
        }
    }
  
  int samplerate = 0;
  float amp = 0.1;
  float freq = 0;
  float phase = 1;
  std::vector<float> mel{ 195.997718, 0, 220, 0, 246.941651, 0, 195.997718};
  std::vector<float> store{};
  Synth synthesizer(1, 2, 3, freq, amp, phase);
  int syntyp = 0;
  int melnum = 0;
  int x = 0;

};

int main() {
  std::cout << "FLIPFLANS!";
  TestCallback callback;
  Port_Audio portAudio { callback };


  try {
      portAudio.setup(44100, 64);
  }
  catch (std::runtime_error& e) {
      std::cerr << "error during startup: " << e.what() << std::endl;
  }

  // Create Impulse Response Vector from csv file
//  io::LineReader in(
//          "../data/Impulse_Response.csv");
//  std::vector<float> ImpulseVector;
//  while (char *line = in.next_line()) {
//      ImpulseVector.push_back(std::stof(line));
//  }
  // Define all initial values
  
  //Convolution verb(ImpulseVector);
  float sdelta = freq / samplerate;
  
  

  

    

  //   for(unsigned int i = 0; i < nframes; i++) {
  //     x += 1;
  //     if (x % hs == 0) {
  //       // Sets the current frequency to the one stored in the melody vector and saves it to a store vector
  //       freq = mel.at(melnum);
  //       store.push_back (freq);
  //       melnum ++;
  //       if(melnum > 6) melnum = 0;
  //     }
  //     if (syntyp == 0) {
  //       outBuf[i] = synthesizer.getSValAdd(freq);
  //     } else if (syntyp == 1) {
  //       outBuf[i] = synthesizer.getSValMult(freq);
  //     } else {
  //       outBuf[i] = (synthesizer.getSValMult(freq) + synthesizer.getSValAdd(freq)) / 2;
  //     }
  //   }
  //   return 0;
  // };


  //keep the program running and listen for user input, q = quit
  std::cout << "\n\nWhat would you like to do? (press 'H' enter to see all the possibilities)\n";
  bool running = true;

  while (running)
  {
    switch (std::cin.get())
    {
      case 'q':
        running = false;
        try {
        portAudio.teardown();
        }
        catch (std::runtime_error& e) {
            std::cerr << "error during teardown: " << e.what() << std::endl;
        }
        break;
      case 'p':
        std::cout << "frequency: " << freq << "\n";
        std::cout << "samplerate: " << samplerate << "\n";
        std::cout << "amplitude: " << amp << "\n";
        std::cout << "phase: " << phase << "\n";
        std::cout << "delta: " << sdelta << "\n";
        break;
      case 'm':
        callback.mel = callback.synthesizer.MelodyMaker();
        break;
      case 'r':
        callback.syntyp = 1;
        break;
      case 'a':
        callback.syntyp = 0;
        break;
      case 'c':
        callback.syntyp = 2;
        break;
      case 'h':
        std::cout << "Hello, you can type a key to execute it's funtion, the following keys are possible: \n";
        std::cout << "m - See synthesizer values \n";
        std::cout << "m - Generate new melody \n";
        std::cout << "r - Set synthesizer to ring modulation \n";
        std::cout << "a - Set synthesizer to adding the waves \n";
        std::cout << "c - Set synthesizer to a combination of the previous two modes \n";
        std::cout << "s - Save notes synth has played so far \n";
        std::cout << "q - Quit synth \n \n";
        break;
      case 's':
        // Saving code found on https://stackoverflow.com/questions/6406356/how-to-write-vector-values-to-a-file
        std::ofstream outFile("Melody.txt");
        for (const auto &e : callback.store) outFile << e << "\n";
        outFile.close();
        break;
    }

  }

  return 0;
} // main()
