#include <iostream>
#include <cmath>
#include <Windows.h>
#include <vector>
#include "./port_audio.h"
#include "./ringbuffer.h"




class Reverb {
public:
    Reverb();

    ~Reverb();

    int startVerb();

//    double getSamples(int const, float const);

    struct TestCallback : public AudioIODeviceCallback {

        TestCallback() {
            numberOfDelays = 500;
            randList.reserve(numberOfDelays + 1);
            iDelays.reserve(numberOfDelays  + 1);
            fVolumes.reserve(numberOfDelays  + 1);
            DelayMultiplier = 0.1;
            delayVal = 2.0;
            InitializeDelayList();

        }

        ~TestCallback() = default;

        void prepareToPlay(int sampleRate, int numSamplesPerBlock) override {
            SampleRate = sampleRate;
        }

        void process(float *input, float *output, int numSamples, int numChannels) override {
            for (auto i = 0; i < numSamples; ++i) {
                ringbuffer1.push(0.91 * input[i * numChannels]);
                auto SingleSample = ringbuffer1.getSamples(iDelays, fVolumes);
                output[i * 2] = SingleSample;
                output[i * 2 + 1] = SingleSample;
            }
        }

        float addDelayMultiplier(float NewDM){
            DelayMultiplier += NewDM;
            return DelayMultiplier;
        }

        [[nodiscard]] float getDelayMultiplier() const{
            return DelayMultiplier;
        }

        float remDelayMultiplier(float NewDM){
            DelayMultiplier -= NewDM;
            return DelayMultiplier;
        }

        float setDelayVal(float NewDV){
            delayVal = NewDV;
            return DelayMultiplier;
        }

        void setDelayList() {
            float j = 1.0;
            for (int i = 0; i < numberOfDelays; i++) {
                randList[i] = (10 + 2);
                delayVal += randList[i] * i * DelayMultiplier;
                iDelays[i] = (int) delayVal;
                fVolumes[i] = j;
                j = j * 0.97f;
                //std::cout<<i<<"/n";
            }
        }

        void InitializeDelayList() {
            float j = 1.0;
            for (int i = 0; i <= numberOfDelays; i++) {
                randList.push_back(rand() % 10 + 2);
                delayVal += randList[i] * i * DelayMultiplier;
                iDelays.push_back((int) delayVal);
                fVolumes.push_back(j);

            }
        }

        //Initiate all values
        //ringbuffer

        ringBuffer ringbuffer1{500000};
        int SampleRate;
        double CurrentTimeS = 0.0;  //init start time in seconds

        int numberOfDelays;
        std::vector<int>randList;
        std::vector<int>iDelays;
        std::vector<float>fVolumes;
        float DelayMultiplier;
        float delayVal;
    };

    PortAudio *portAudio;


    static void DisplayHelpInfo();

    void SetupAudio() const;

    void TeardownAudio() const;

    static int IsKeyPressed(char);

    TestCallback callback;



};

