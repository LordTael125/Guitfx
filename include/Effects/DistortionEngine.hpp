#pragma once
#include <portaudio.h>

class DistortionEngine {

    public :
        DistortionEngine();
        ~DistortionEngine();

        int start(const float* in, float* out, unsigned long framesperbuffer);
        void stop();

        

        void setDrive(float d) { drive_ = d; };
        void setThreshold(float t) {threshold_ = t;};
        void setOutputGain(float g) {outputGain_ = g;};

    private :


        int process_distort(const float* in, float* out, unsigned long framesPerBuffer);
        

        PaStream* stream_;
        float drive_;
        float threshold_;
        float outputGain_;
        
        bool running_;


};