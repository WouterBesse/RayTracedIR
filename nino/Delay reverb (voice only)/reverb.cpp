#include <iostream>
#include <thread>
#include <cmath>
#include <fstream>
#include <vector>
#include <string>
#include <thread>
#include <atomic>
#include <condition_variable>
#include <Windows.h>

#include "jack_module.h"
#include "math.h"

#include "ringbuffer.h"



const int numberOfDelays = 11000;
int randList[numberOfDelays];
int iDelays[numberOfDelays];
float fVolumes[numberOfDelays];
double delaymultiplier = 0.1;
double j = 1.0;
double delayVal = 2.0;


int reverb(int argc,char **argv)
{

  for(int i = 0; i < numberOfDelays; i++)
  {
    randList[i] = rand() % 10 + 2;
    delayVal += randList[i] * i * delaymultiplier;
    iDelays[i] = delayVal;
    fVolumes[i] = j;
    j = j * 0.97;
  }
  //fVolumes[0] = 1.0;

  // create a JackModule instance
  JackModule jack;

  // init the jack, use program name as JACK client name
  jack.init("example.exe");
  double samplerate = jack.getSamplerate();

  //ringbuffer
  ringBuffer ringbuffer1(500000);

  double CurrentTimeS = 0.0;  //init start time in seconds
  int CurrentSamp = 0;//declare the first sample

  //wat leuke text en info:
  std::cout << std::endl;
  std::cout << "\n\nPress 'q' when you want to quit the program."<<std::endl;
  std::cout << "\n\nPress '1' to increase length."<<std::endl;
    std::cout << "\n\nPress '2' to decrease length."<<std::endl;

 double SingleSample = 0.0;
  //assign a function to the JackModule::onProces
  jack.onProcess = [&ringbuffer1, &samplerate, &CurrentTimeS, &CurrentSamp, &SingleSample](jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBufL, jack_default_audio_sample_t *outBufR, jack_nframes_t nframes) {


    for(unsigned int i=0;i<nframes;i++)
    {
      ringbuffer1.push
      (0.1 * inBuf[i]);
      CurrentSamp += 1;
      CurrentTimeS = CurrentSamp / samplerate;
      SingleSample = ringbuffer1.getSamples(iDelays,fVolumes);
      if(i % 2 == 0)
      {
        outBufL[i] = SingleSample;

      }
      else
      {
        outBufR[i] = SingleSample;

      }


    }
    return 0;
  };

  jack.autoConnect();


  //keep the program running and listen for user input, q = quit

  bool running = true;
  int nCurrentKey = -1;
	bool bKeyPressed = false;
  while (running)
  {
    //live keyboard in
    bKeyPressed = false;
    //quit the program
    double lastDelayMultiplier;
    if (GetAsyncKeyState('Q') & 0x8000)
    {
      running = false;
      jack.end();
      break;
    }
    else if (GetAsyncKeyState('1') & 0x8000)
    {
      delaymultiplier += 0.0001;
    }
    else if (GetAsyncKeyState('2') & 0x8000)
    {
      delaymultiplier -= 0.0001;
    }
    else if (delaymultiplier != lastDelayMultiplier)
    {
      double j = 1.0;
      double delayVal = 2.0;
      for(int i = 0; i < numberOfDelays; i++)
      {
        iDelays[i] = delayVal;
        delayVal += randList[i] * i * delaymultiplier;
        fVolumes[i] = j;
        j = j * 0.97;
        //std::cout<<j;
      }
      //std::cout<<iDelays[100];
      lastDelayMultiplier = delaymultiplier;
    }



    //must be last: resetting values for toggling and sending note off value
    if (!bKeyPressed)
    {
      if (nCurrentKey != -1)
      {
        nCurrentKey = -1;
      }
    }


  }

  //end the program
  return 0;
} // main()

int main(int argc,char **argv)
{
  reverb(argc,argv);
}
