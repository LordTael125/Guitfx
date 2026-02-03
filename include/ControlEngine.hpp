#pragma once
// #include <portaudio.h>


class ControlEngine {

    public :

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
            char* Mode;
        }typedef ReverbParam;

        DistortionParam DistortionValue;
        void setParamDistortion(DistortionParam);
        bool startDistortionEngine();
        void stopDistortionEngine();



        


};