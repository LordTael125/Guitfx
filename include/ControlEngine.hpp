#pragma once
#include <portaudio.h>
#include <Effects/DelayEngine.hpp>
#include <Effects/DistortionEngine.hpp>

class audioEngine {

    public :
        audioEngine();
        ~audioEngine();
        PaStream* stream_;
        bool start_stream();
        void stop_stream();
        
        struct audioBuffer{
            const float* in;
            float* out;
            unsigned long framesperbuffer;
        } typedef audioBuffer;

        virtual int applyEffects(Audio::audioBuffer)=0;
        

    
    private :
        static int audioCallBack(
            const void* inputBuffer,
            void* outputBuffer,
            unsigned long framesPerBuffer,
            const PaStreamCallbackTimeInfo* timeInfo,
            PaStreamCallbackFlags statusFlag,
            void* userdata);

        bool pa_stream_status=false;

    protected :
        audioBuffer audioData;
        
};

class ControlEngine : public audioEngine{

    public :
        ControlEngine();
        ~ControlEngine();

        

        bool LiveStatus;

        bool Distortion=false;
        bool Reverb=false;
        bool Delay=false;
        bool Chorus=false;



        bool startEngine();
        void stopEngine();
        
        
        DistortionEngine DistEngine;
        Distortion::DistortionParam DistortionValue;
        void setDistortionParam();
  

        Reverb::ReverbParam ReverbValue;
        void setReverbParam();

        DelayEngine DelayEng;
        
        void setDelayMode(Delay::DelayMode);

        int applyEffects(Audio::audioBuffer);

        


    


};

