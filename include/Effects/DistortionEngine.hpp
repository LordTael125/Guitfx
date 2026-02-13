#pragma once
#include <portaudio.h>

class DistortionEngine {

    public :
        DistortionEngine();
        ~DistortionEngine();

        bool start();
        void stop();

        void setDrive(float d) { drive_ = d; };
        void setThreshold(float t) {threshold_ = t;};
        void setOutputGain(float g) {outputGain_ = g;};

    private :
        static int audioCallBack(
            const void* inputBuffer,
            void* outputBuffer,
            unsigned long framesPerBuffer,
            const PaStreamCallbackTimeInfo* timeInfo,
            PaStreamCallbackFlags statusFlag,
            void* userdata);
        

        void applyDistortionToBuffer(
            const float* input,
            float* output,
            std::size_t numSamples,
            float drive,
            float outputGain);
        
    
        int process(const float* in, float* out, unsigned long framesPerBuffer);

        PaStream* stream_;
        float drive_;
        float threshold_;
        float outputGain_;
        
        bool running_;


};