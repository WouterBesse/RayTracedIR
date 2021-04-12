#include <iostream>
#include "./port_audio.h"
#include "./ringbuffer.h"
#include "./reverb.h"
#include <thread>

//placeholder!!! allemaal nodig om even een reverb lijst aan te maken
const int numberOfDelays = 500;
int randList[numberOfDelays];
int iDelays[numberOfDelays];
float fVolumes[numberOfDelays];
double delaymultiplier = 0.1;
double j = 1.0;
double delayVal = 2.0;



int main()
{
    //placeholder
    for(int i = 0; i < numberOfDelays; i++)
    {
        randList[i] = rand() % 10 + 2;
        delayVal += randList[i] * i * delaymultiplier;
        iDelays[i] = delayVal;
        fVolumes[i] = j;
        j = j * 0.999;
    }

    Reverb ninoVerb;
    std::thread reverbThread = std::thread(&Reverb::startVerb, ninoVerb);
    //ninoVerb.startVerb();

    ninoVerb.updateDelayList(iDelays, fVolumes);

    reverbThread.join();

    return 0;
}
