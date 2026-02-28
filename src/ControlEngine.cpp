#include <iostream>
#include <ControlEngine.hpp>
#include <algorithm>
#include <cmath>

// DSP Header Inclusion
#include <Effects/DistortionEngine.hpp>
#include <Effects/ReverbEngine.hpp>





// 
//  Audio Engine Class
// 
audioEngine::audioEngine(){
    {
        PaError err = Pa_Initialize();
        if (err != paNoError){
            std::cout << "PortAudio Init Error : " << Pa_GetErrorText(err) << std::endl;        // Debug Comment
        }
    }
}

audioEngine::~audioEngine(){
    stop_stream();
    Pa_Terminate();
}

bool audioEngine::start_stream(){
    if (pa_stream_status) return true;

    PaDeviceIndex inDev  = Pa_GetDefaultInputDevice();
    PaDeviceIndex outDev = Pa_GetDefaultOutputDevice();

    if (inDev == paNoDevice) {
        std::cerr << "No default input device found!\n";
        Pa_Terminate();
        return 1;
    }
    if (outDev == paNoDevice) {
        std::cerr << "No default output device found!\n";
        Pa_Terminate();
        return 1;
    }

    PaStreamParameters inParam;
    PaStreamParameters outParam;

    inParam.device = Pa_GetDefaultInputDevice();
    std::cout<<Pa_GetDeviceInfo(inParam.device) ->name << std::endl;        // Debug Comment
    
    if (inParam.device == paNoDevice){
        std::cerr << "No Default Input Device found";
    }

    inParam.channelCount = 1;
    inParam.sampleFormat = paFloat32;
    inParam.suggestedLatency = Pa_GetDeviceInfo(inParam.device) -> defaultLowInputLatency;
    inParam.hostApiSpecificStreamInfo = nullptr;

    outParam.device = Pa_GetDefaultOutputDevice();
    std::cout<<Pa_GetDeviceInfo(outParam.device) -> name << std::endl;      // Debug Comment
    if (outParam.device == paNoDevice){
        std::cerr << "No Default Output Device found";
    } 

    outParam.channelCount = 1;
    outParam.sampleFormat = paFloat32;
    outParam.suggestedLatency = Pa_GetDeviceInfo(outParam.device)->defaultLowOutputLatency;
    outParam.hostApiSpecificStreamInfo = nullptr;

    PaError err = Pa_OpenStream(
        &stream_,
        &inParam,
        &outParam,
        44100,
        256,
        paClipOff,
        &audioEngine::audioCallBack,
        this
        
    );

    if (err != paNoError){
        std::cerr << "OpenStream error : " << Pa_GetErrorText(err) << "\n";
        stream_ = nullptr;
        return false;
    }

    err = Pa_StartStream(stream_);
    if (err != paNoError){
        std::cerr << "StartStream error : " << Pa_GetErrorText(err) << "\n";
        Pa_CloseStream(stream_);
        stream_ = nullptr;
        return false;
    }

    pa_stream_status = true;
    return true;
}

void audioEngine::stop_stream(){
    if(!pa_stream_status) return;
    if (stream_){
        Pa_StopStream(stream_);
        Pa_CloseStream(stream_);
    }
}

int audioEngine::audioCallBack(
    const void* inputBuffer,
    void* outputBuffer,
    unsigned long framesPerBuffer,
    const PaStreamCallbackTimeInfo* timeInfo,
    PaStreamCallbackFlags statusFlag,
    void* userdata)
{

    Audio::audioBuffer streamBuffer;
    streamBuffer.framesPerBuffer = framesPerBuffer;

    auto* engine = static_cast<audioEngine*>(userdata);
    streamBuffer.in =  static_cast<const float*>(inputBuffer);
    streamBuffer.out = static_cast<float*>(outputBuffer);

    return engine -> applyEffects(streamBuffer);
}


ControlEngine::ControlEngine(){

}
ControlEngine::~ControlEngine(){
    stop_stream();
}


bool ControlEngine::startEngine(){
    bool status = start_stream();
    if (!status){
        std::cout << "Failed to start audio stream";
        return false;
    }
    return true;
}
void ControlEngine::stopEngine(){
    stop_stream();
};


int ControlEngine::applyEffects(Audio::audioBuffer streamBuffer){

    if(Distortion){
        setDistortionParam();
        DistEngine.start(streamBuffer);
    }

    if(Delay){

    }
    return 0;
}


void ControlEngine::setDistortionParam(){
    DistEngine.updateParam(DistortionValue);
}

// Construct Reverb Engine
ReverbEngine RevEngine;
void ControlEngine::setReverbParam(){
}

void ControlEngine::setDelayMode(Delay::DelayMode mode){

}