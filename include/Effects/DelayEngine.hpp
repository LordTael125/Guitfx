#pragma once
#include <portaudio.h>
#include <DataType.hpp>

class DelayEngine {

    public :
        bool status;
        enum mode {echoDelay,feedbackDelay,ping_pongDelay};
        mode statMode;
        int start(const float* in, float* out, unsigned long framesperbuffer);
        void stop();

        // int applyDelay(const float* in, float* out, unsigned long framesperbuffer);


    private:
        bool apply_echo(const float* in, float* out, unsigned long framesperbuffer);
        bool apply_feedback(const float* in, float* out, unsigned long framesperbuffer);
        bool apply_pingpong(const float* in, float* out, unsigned long framesperbuffer);

        int echo_filter1(float* in);


};