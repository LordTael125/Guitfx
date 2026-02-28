#pragma once


namespace Delay {
    enum DelayMode {echoDelay, feedbackDelay, ping_pongDelay};
    struct DelayParam 
    {
        float Level;
        float Feedback;
        float Time;
        DelayMode Mode;
    } typedef DelayParam;

}

namespace Distortion {
        struct DistortionParam 
        {
            float Drive;
            float Threshold;
            float OutputGain;
        }typedef DistortionParam;
}

namespace Reverb {
    enum ReverbMode {Hall,Room,Chamber,Spring,Plate,Default};
    struct ReverbParam 
    {
        float OutputLevel;
        float Tone;
        float Time;
        ReverbMode Mode = Default;
    }typedef ReverbParam;
}

namespace Audio {
    struct audioBuffer 
    {
        const float* in;
        float* out;
        unsigned long framesPerBuffer;
    }typedef audioBuffer;

}

namespace Gate {
    struct GateParam {
        float Threshold;
        float Decay;
    };
}