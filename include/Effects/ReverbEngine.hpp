#pragma once
#include <portaudio.h>
#include <DataType.hpp>

class ReverbEngine {

    public :
        ReverbEngine();
        ~ReverbEngine();
        
        Reverb::ReverbParam RevParam;
        bool StartHallReverb(Reverb::ReverbParam Param);
        bool StartRoomReverb(Reverb::ReverbParam Param);
        bool StartChamberReverb(Reverb::ReverbParam Param);
        bool StartSpringReverb(Reverb::ReverbParam Param);
        bool StartPlateReverb(Reverb::ReverbParam Param);

        bool Start();
        void Stop();


};