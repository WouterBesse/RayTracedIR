#include <iostream>
#include "./port_audio.h"
#include "./ringbuffer.h"
#include "./reverb.h"
#include <thread>

int main()
{
    Reverb ninoVerb;
    std::thread reverbThread = std::thread(&Reverb::startVerb, ninoVerb);
    //ninoVerb.startVerb();

    reverbThread.join();

    return 0;
}
