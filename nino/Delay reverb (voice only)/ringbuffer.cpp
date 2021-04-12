#include "ringbuffer.h"

//constructor and destructor
ringBuffer::ringBuffer(int length) {
    this->length = length;

    ringBuf.reserve(length);
    for (int i = 0; i <= length; i++) {
        ringBuf.push_back(0.0);
    }
}

ringBuffer::~ringBuffer() = default;

void ringBuffer::push(double dInput) {
    ringBuf[iRingBuf] = dInput;
    iRingBuf++;
    iRingBuf = iRingBuf % length;
}

double ringBuffer::getSamples(int const *iDelays, float const *fVolumes) {
    out = 0.0;
    int size = 1000;
    for (int i = 0; i <= size; i++) {
        out += fVolumes[i] * ringBuf[(iRingBuf + length - iDelays[i + (i % 2) + (iRingBuf % 2)] % length) % length];
    }
    return out;
}
