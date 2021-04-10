#pragma once
#include <iostream>
#include <vector>

class ringBuffer {
public:
    ringBuffer(int length);

    ~ringBuffer();

    void push(double dInput);

    double getSamples(std::vector<int>, std::vector<float>);

protected:

    int iRingBuf = 0; //iteration of the ring buffer
    double sample{};
    std::vector<double> ringBuf;
    int length;
    double out = 0.0;


};
