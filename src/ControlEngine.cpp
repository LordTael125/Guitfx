#include <iostream>
#include <ControlEngine.hpp>
#include <algorithm>
#include <cmath>


ControlEngine::ControlEngine(){

}

ControlEngine::~ControlEngine(){
    
}


// DSP Header Inclusion
#include <Effects/DistortionEngine.hpp>
#include <Effects/ReverbEngine.hpp>


// Construct Distortion Engine
DistortionEngine DistEngine;
void ControlEngine::setDistortionParam(DistortionParam Param){

    // Debug Section Uncomment to check the entered Parameter values
    // std::cout<<"Debug:"<<std::endl;
    // std::cout<<"\tDrive :"<<Param.Drive<<std::endl;
    // std::cout<<"\tThreshold:"<<Param.Threshold<<std::endl;
    // std::cout<<"\tGain:"<<Param.OutputGain<<std::endl;
    DistEngine.setDrive(Param.Drive);
    DistEngine.setThreshold(Param.Threshold);
    DistEngine.setOutputGain(Param.OutputGain);
}
// Start Distortion engine model
bool ControlEngine::startDistortionEngine(){
    Distortion = true;

    DistEngine.start();
    return true;
}
// Stop Distortion engine model
void ControlEngine::stopDistortionEngine(){
    DistEngine.stop();
}


// Construct Reverb Engine
ReverbEngine RevEngine;
// void ControlEngine::setReverbParam(ReverbParam Param){
//     RevEngine.RevParam.OutputLevel = Param.OutputLevel;
//     RevEngine.RevParam.Tone = Param.Tone;
//     RevEngine.RevParam.Time = Param.Time;
//     // RevEngine.RevParam.Mode = Param.Mode;
// }