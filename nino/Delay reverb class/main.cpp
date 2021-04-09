#include <iostream>
#include "./port_audio.h"
#include "./ringbuffer.h"
#include "./reverb.h"
//#include <thread>

int main()
{
    std::cout << "kaas \n";
    Reverb ninoVerb;
//    std::thread reverbThread = std::thread(&reverb::startVerb, ninoVerb);
    ninoVerb.startVerb();
//    reverbThread.join();
    return 0;
}
