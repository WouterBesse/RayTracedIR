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


int iDelays[1000];
float fVolumes[1000];
double delaymultiplier = 0.1;



int main(int argc,char **argv)
{
  double j = 1.0;
  double delayVal = 2.0;
  for(int i = 0; i < 300; i++)
  {
    iDelays[i] = delayVal;
    delayVal += (rand() % 5 + 30) * i * delaymultiplier;
    fVolumes[i] = j;
    j = j * 0.94;
  }
  fVolumes[0] = 1.0;
    // for(int i = 0; i < 500; i++){
    //   iDelays[i] = 100000 - (iDelays[i] % 100000);
    // }
    std::cout<<delaymultiplier;


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


  //assign a function to the JackModule::onProces
  jack.onProcess = [&ringbuffer1, &samplerate, &CurrentTimeS, &CurrentSamp](jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

    for(unsigned int i=0;i<nframes;i++)
    {
      ringbuffer1.push
      (0.1 * inBuf[i]);
      CurrentSamp += 1;
      CurrentTimeS = CurrentSamp / samplerate;
      outBuf[i] = ringbuffer1.getSamples(iDelays,fVolumes);
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
    if (GetAsyncKeyState('Q') & 0x8000)
    {
      running = false;
      jack.end();
      break;
    }
    if (GetAsyncKeyState('1') & 0x8000)
    {
      delaymultiplier += 0.0001;
      double j = 1.0;
      double delayVal = 2.0;

      for(int i = 0; i < 1000; i++)
      {
        iDelays[i] = delayVal;
        delayVal += (rand() % 10 + 2) * i * delaymultiplier;
        fVolumes[i] = j;
        j = j * 0.97;
      }
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
