#include <iostream>
#include <Effects/ReverbEngine.hpp>
#include <algorithm>
#include <cmath>

ReverbEngine::ReverbEngine(){
    RevParam.Time=10.0;
    RevParam.OutputLevel=1.0;
    RevParam.Tone=0.5;
    RevParam.Mode=Default;
}

ReverbEngine::~ReverbEngine(){
    
}