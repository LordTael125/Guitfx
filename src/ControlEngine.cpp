#include <iostream>
#include <ControlEngine.hpp>
#include <algorithm>
#include <cmath>

// DSP Header Inclusion
#include <Effects/DistortionEngine.hpp>
#include <Effects/ReverbEngine.hpp>


// Construct Distortion Engine
GuitarDistortionEngine DistortionEngine;
void ControlEngine::setParamDistortion(DistortionParam Param){
    std::cout<<"Debug:"<<std::endl;
    std::cout<<"\tDrive :"<<Param.Drive<<std::endl;
    std::cout<<"\tThreshold:"<<Param.Threshold<<std::endl;
    std::cout<<"\tGain:"<<Param.OutputGain<<std::endl;
    DistortionEngine.setDrive(Param.Drive);
    DistortionEngine.setThreshold(Param.Threshold);
    DistortionEngine.setOutputGain(Param.OutputGain);
}
// Start Distortion engine model
bool ControlEngine::startDistortionEngine(){
    Distortion = true;

    DistortionEngine.start();
    return true;
}
// Stop Distortion engine model
void ControlEngine::stopDistortionEngine(){
    DistortionEngine.stop();
}


// Construct Reverb Engine