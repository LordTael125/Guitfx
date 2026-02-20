#include <iostream>
#include <Effects/DelayEngine.hpp>
#include <algorithm>
#include <cmath>


int DelayEngine::start(const float* in, float* out, unsigned long framesperbuffer){
    switch (statMode) {
        case echoDelay : 
            apply_echo(in, out, framesperbuffer);
            break;
        case feedbackDelay :
            apply_feedback(in,out,framesperbuffer);
            break;
        case ping_pongDelay :
            apply_pingpong(in, out, framesperbuffer);
            break;
    }

    return 0;
}

bool DelayEngine::apply_echo(const float* in, float* out, unsigned long framesperbuffer){}