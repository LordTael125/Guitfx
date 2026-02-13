#pragma once
// #include <portaudio.h>


class ControlEngine {

    public :
        ControlEngine();
        ~ControlEngine();
        enum ReverbMode {Hall=0,Room=1,Chamber=2,Spring=3,Plate=4,Default=5};

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
            ReverbMode Mode = Hall;
        }typedef ReverbParam;

        DistortionParam DistortionValue;
        void setDistortionParam(DistortionParam);
        bool startDistortionEngine();
        void stopDistortionEngine();   

        ReverbParam ReverbValue;
        void setReverbParam(ReverbParam);
        bool startReverbEngine();
        void stopReverbEngine();


};