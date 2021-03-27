#include <iostream>
#include <cmath>
#include <Windows.h>
#include "port_audio.h"
#include "ringbuffer.h"


const int numberOfDelays = 11000;
int randList[numberOfDelays];
int iDelays[numberOfDelays];
float fVolumes[numberOfDelays];
double DelayMultiplier = 0.1;
double delayVal = 2.0;

void InitializeDelayList();

void DisplayHelpInfo();

void SetupAudio(PortAudio &portAudio);

void TeardownAudio(PortAudio &portAudio);


struct TestCallback : public AudioIODeviceCallback {

    TestCallback() {
        InitializeDelayList();
    }

    ~TestCallback() = default;

    void prepareToPlay(int sampleRate, int numSamplesPerBlock) override {
        SampleRate = sampleRate;
    }

    void process(float *input, float *output, int numSamples, int numChannels) override {
        for (auto i = 0; i < numSamples; ++i) {
            ringbuffer1.push(0.1 * input[i * numChannels]);
            auto SingleSample = ringbuffer1.getSamples(iDelays, fVolumes);
            output[i * 2] = SingleSample;
            output[i * 2 + 1] = SingleSample;
        }
    }

    //Initiate all values
    //ringbuffer
    ringBuffer ringbuffer1{500000};
    int SampleRate = 0;
    double CurrentTimeS = 0.0;  //init start time in seconds
};


int main() {
    TestCallback callback{};
    PortAudio portAudio{callback};

    DisplayHelpInfo();

    SetupAudio(portAudio);

    // keep the program running and listen for user input, q = quit

    while (true) {
        // live keyboard in
        // quit the program
        int lastDelayMultiplier = 0;
        if (GetAsyncKeyState('Q') & 0x8000) {
            TeardownAudio(portAudio);
            break;
        } else if (GetAsyncKeyState('1') & 0x8000) {
            DelayMultiplier += 0.0001;
        } else if (GetAsyncKeyState('2') & 0x8000) {
            DelayMultiplier -= 0.0001;
        } else if (DelayMultiplier != lastDelayMultiplier) {
            delayVal = 2.0;
            InitializeDelayList();
        }
    }
    //end the program
    return 0;
}

void TeardownAudio(PortAudio &portAudio) {
    try {
        portAudio.teardown();
    }
    catch (std::runtime_error &e) {
        std::cerr << "error during teardown: " << e.what() << std::endl;
    }
}

void SetupAudio(PortAudio &portAudio) {
    try {
        portAudio.setup(44100, 128);
    }
    catch (std::runtime_error &e) {
        std::cerr << "error during startup: " << e.what() << std::endl;
    }
}

void DisplayHelpInfo() {
    std::cout << std::endl;
    std::cout << "\n\nPress 'q' when you want to quit the program." << std::endl;
    std::cout << "\n\nPress '1' to increase length." << std::endl;
    std::cout << "\n\nPress '2' to decrease length." << std::endl;
}

void InitializeDelayList() {
    float j = 1.0;
    for (int i = 0; i < numberOfDelays; i++) {
        randList[i] = rand() % 10 + 2;
        delayVal += randList[i] * i * DelayMultiplier;
        iDelays[i] = (int) delayVal;
        fVolumes[i] = j;
        j = j * 0.97f;
    }
}