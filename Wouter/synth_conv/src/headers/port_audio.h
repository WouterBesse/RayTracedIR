//
// Created by woute met hulp van Wouter Ensink on 22/02/2021.
//
#pragma once
#include <portaudio.h>
#include <iostream>
#include <exception>
#include <random>


struct AudioIODeviceCallback {

    virtual void prepareToPlay(int sampleRate, int numSamplesPerBlock) {}

    virtual void process(float* input, float* output, int numSamples, int numChannels) = 0;

    virtual void releaseResources() {}
};





class Port_Audio {
public:
    Port_Audio(AudioIODeviceCallback& callback) : callback {callback } {}
    ~Port_Audio(){}

    void setup(int sampleRate, int framesPerBuffer) {
        

        if (Pa_Initialize() != paNoError)
            throw std::runtime_error("failed to start port audio");

        outputParameters.device = Pa_GetDefaultOutputDevice(); /* default output device */

        if (outputParameters.device == paNoDevice) 
            throw std::runtime_error("Error: No default output device.\n");
        
        outputParameters.channelCount = 2;       /* stereo output */
        outputParameters.sampleFormat = paFloat32; /* 32 bit floating point output */
        outputParameters.suggestedLatency = Pa_GetDeviceInfo(outputParameters.device)->defaultLowOutputLatency;
        outputParameters.hostApiSpecificStreamInfo = nullptr;

        callback.prepareToPlay(sampleRate, framesPerBuffer);

        auto error = Pa_OpenStream(
              &stream,
              nullptr, /* no input */
              &outputParameters,
              sampleRate,
              framesPerBuffer,
              paClipOff,      /* we won't output out of range samples so don't bother clipping them */
              &Port_Audio::internalCallback,
              this);

        if (error != paNoError)
            throw std::runtime_error("failed to open callback");

        Pa_SetStreamFinishedCallback(stream, &Port_Audio::streamFinished);

        if (Pa_StartStream(stream) != paNoError)
            throw std::runtime_error("failed to start stream");
    }


    void teardown() {
        if (Pa_StopStream(stream) != paNoError)
            throw std::runtime_error("failed to stop stream");


        if (Pa_CloseStream(stream) != paNoError);
            throw std::runtime_error("failed to close stream");

        Pa_Terminate();
    }


    AudioIODeviceCallback& callback;

private:

    PaStreamParameters outputParameters;
    PaStream* stream;

    static int internalCallback(const void* inputBuffer, void* outputBuffer,
                            unsigned long framesPerBuffer,
                            const PaStreamCallbackTimeInfo* timeInfo,
                            PaStreamCallbackFlags statusFlags,
                            void* userData)
    {
        auto* input = (float*) inputBuffer;
        auto* output = (float*) outputBuffer;

        auto* self = reinterpret_cast<Port_Audio*> (userData);

        self->callback.process(input, output, framesPerBuffer, outputParameters.channelCount);

        return 0;
    }

    static void streamFinished( void* userData )
    {
        auto* self = reinterpret_cast<Port_Audio*> (userData);
        self->callback.releaseResources();
        std::cout << "Stream Completed\n";
    }

};






