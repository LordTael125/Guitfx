#include <iostream>
#include <Effects/DistortionEngine.hpp>
#include <algorithm>
#include <cmath>


DistortionEngine::DistortionEngine()
    :   stream_(nullptr),
        drive_(10.0f),
        threshold_(0.6f),
        outputGain_(0.3f),
        running_(false){}


DistortionEngine::~DistortionEngine() {
    stop();

}

int DistortionEngine::start(const float* in, float* out, unsigned long framesperbuffer)
{
    running_=true;
    return this -> simple_tanhDistort(in, out,framesperbuffer);
}

void DistortionEngine::stop() {
    running_=false;
}

int DistortionEngine::simple_tanhDistort(
    const float* in, float* out, unsigned long framesPerBuffer)
{
    if (!out) return paAbort;

    if(!in){
        std::fill(out, out + framesPerBuffer, 0.0f);
        return paContinue;
    }

    for (unsigned long i = 0;i < framesPerBuffer; ++i){
        float x = in[i] * drive_;

        float y = std::tanh(x);

        out[i]= y*outputGain_;
    }
    return paContinue;
}


int DistortionEngine::double_filterDistort(const float* in, float* out, unsigned long framesPerBuffer){
    if (!out) return paAbort;

    if(!in){
        std::fill(out,out+framesPerBuffer,0.0f);
        return paContinue;
    }

    return paContinue;
};