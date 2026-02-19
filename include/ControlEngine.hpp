#pragma once
#include <portaudio.h>


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

        virtual int applyEffects(const float* in, float* out, unsigned long framesperbuffer)=0;
        

    
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
        enum ReverbMode {Hall,Room,Chamber,Spring,Plate,Default};

        bool LiveStatus;

        bool Distortion=false;
        bool Reverb=false;
        bool Delay=false;
        bool Chorus=false;

        struct DistortionParam{
            float Drive;
            float Threshold;
            float OutputGain;
        }typedef DistortionParam;

        struct ReverbParam{
            float OutputLevel;
            float Tone;
            float Time;
            ReverbMode Mode = Default;
        }typedef ReverbParam;

        

        

        bool startEngine();
        void stopEngine();
        
        

        DistortionParam DistortionValue;
        void setDistortionParam(DistortionParam);
  

        ReverbParam ReverbValue;
        void setReverbParam(ReverbParam);

        int applyEffects(const float* in, float* out, unsigned long framesperbuffer);

        


    


};

