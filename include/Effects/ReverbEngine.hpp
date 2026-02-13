#pragma once
#include <portaudio.h>

enum ReverbMode {Hall=0,Room=1,Chamber=2,Spring=3,Plate=4,Default=5};

struct ReverbParam{
    float OutputLevel;
    float Tone;
    float Time;
    ReverbMode Mode = Hall;
}typedef ReverbParam;

class ReverbEngine {

    public :
        ReverbEngine();
        ~ReverbEngine();
        
        ReverbParam RevParam;
        bool StartHallReverb(ReverbParam Param);
        bool StartRoomReverb(ReverbParam Param);
        bool StartChamberReverb(ReverbParam Param);
        bool StartSpringReverb(ReverbParam Param);
        bool StartPlateReverb(ReverbParam Param);
        bool Stop();


};