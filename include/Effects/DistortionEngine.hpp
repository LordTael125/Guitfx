#pragma once
#include <portaudio.h>
#include <vector>
#include <DataType.hpp>


class DistortFilters {
    public :
        float prev_lf_input = 0.0, prev_lf_output = 0.0;
        float prev_hf_input = 0.0, prev_hf_output = 0.0;
        virtual float low_pass_filter(Audio::audioBuffer) = 0;
        virtual float high_pass_filter(Audio::audioBuffer) = 0;
};

class DistortionEngine : public DistortFilters{

    public :
        DistortionEngine();
        ~DistortionEngine();

        int start(Audio::audioBuffer);
        void stop();

        
        void updateParam(Distortion::DistortionParam param){
            drive_ = param.Drive;
            threshold_ = param.Threshold;
            outputGain_ = param.OutputGain;
        };
        void setDrive(float d) { drive_ = d; };
        void setThreshold(float t) {threshold_ = t;};
        void setOutputGain(float g) {outputGain_ = g;};

    private :


        int simple_tanhDistort(Audio::audioBuffer);

        int double_filterDistort(Audio::audioBuffer);
        
        float low_pass_filter(float x);
        float high_pass_filter(float x);

        PaStream* stream_;
        float drive_;
        float threshold_;
        float outputGain_;
        
        bool running_;



};