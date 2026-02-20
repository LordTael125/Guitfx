#pragma once

namespace Delay {
    enum mode {
        echoDelay,
        feedbackDelay,
        ping_pongDelay
    };
}

namespace Distortion {
        struct DistortionParam{
            float Drive;
            float Threshold;
            float OutputGain;
        }typedef DistortionParam;
}

namespace Reverb {
    enum ReverbMode {Hall,Room,Chamber,Spring,Plate,Default};
    struct ReverbParam{
            float OutputLevel;
            float Tone;
            float Time;
            ReverbMode Mode = Default;
    }typedef ReverbParam;
}