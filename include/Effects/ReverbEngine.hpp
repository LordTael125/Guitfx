#pragma once
#include <portaudio.h>

enum ReverbMode {Hall,Room,Chamber,Spring,Plate,Default};

struct ReverbParam{
    float OutputLevel;
    float Tone;
    float Time;
    ReverbMode Mode = Default;
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

        bool Start();
        void Stop();


};