#include <iostream>
#include ".\reverb.h"

Reverb::Reverb() {
    std::cout << "kaas2 \n";
    DisplayHelpInfo();
    portAudio = new PortAudio{callback};
}

Reverb::~Reverb()= default;

int Reverb::startVerb() {


    SetupAudio();

    // keep the program running and listen for user input, q = quit

    while (true) {
        // live keyboard in
        // quit the program
        int lastDelayMultiplier = 0;
        if (IsKeyPressed('Q')) {
            TeardownAudio();
            break;
        } else if (IsKeyPressed('1')) {
            callback.addDelayMultiplier(0.0001);
        } else if (IsKeyPressed('2')) {
            callback.remDelayMultiplier(0.0001);
        } else if (callback.getDelayMultiplier() != lastDelayMultiplier) {
            callback.setDelayVal(2.0);
            callback.setDelayList();
        }
    }
    return 0;
}

int Reverb::IsKeyPressed(char Key) { return GetAsyncKeyState(Key) & 0x8000; }

void Reverb::TeardownAudio() const {
    try {
        portAudio->teardown();
    }
    catch (std::runtime_error &e) {
        std::cerr << "error during teardown: " << e.what() << std::endl;
    }

}

void Reverb::SetupAudio() const {

    try {
        portAudio->setup(44100, 128);
    }
    catch (std::runtime_error &e) {
        std::cerr << "error during startup: " << e.what() << std::endl;
    }
}

void Reverb::DisplayHelpInfo() {
    std::cout << std::endl;
    std::cout << "\n\nPress 'q' when you want to quit the program." << std::endl;
    std::cout << "\n\nPress '1' to increase length." << std::endl;
    std::cout << "\n\nPress '2' to decrease length." << std::endl;
}