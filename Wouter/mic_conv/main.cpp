
#include <stdio.h>
#include <math.h>
#include "port_audio.h"

int main()
{
    TestCallback callback;
    Port_Audio portAudio { callback };


    try {
        portAudio.setup(44100, 64);
    }
    catch (std::runtime_error& e) {
        std::cerr << "error during startup: " << e.what() << std::endl;
    }

    std::cin.get();

    try {
        portAudio.teardown();
    }
    catch (std::runtime_error& e) {
        std::cerr << "error during teardown: " << e.what() << std::endl;
    }

    return 0;
}