#pragma once
#include <iostream>
#include <vector>

class ringBuffer {
public:
    explicit ringBuffer(int length);

    ~ringBuffer();

    void push(double dInput);

    double getSamples(int const *iDelays, float const *fVolumes);

protected:

    int iRingBuf = 0; //iteration of the ring buffer
    double sample{};
    std::vector<double> ringBuf;
    int length;
    double out = 0.0;


};
