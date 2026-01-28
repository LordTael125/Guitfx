#include <iostream>
#include <Effects/DistortionEngine.hpp>
#include <algorithm>
#include <cmath>


GuitarDistortionEngine::GuitarDistortionEngine()
    :   stream_(nullptr),
        drive_(10.0f),
        threshold_(0.6f),
        outputGain_(0.3f),
        running_(false)
    {
        PaError err = Pa_Initialize();
        if (err != paNoError){
            std::cout << "PortAudio Init Error : " << Pa_GetErrorText(err) << std::endl;
        }
    }


GuitarDistortionEngine::~GuitarDistortionEngine() {
    stop();
    Pa_Terminate();
}

bool GuitarDistortionEngine::start() {
    if (running_) return true;

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
    if (inParam.device == paNoDevice){
        std::cerr << "No Default Input Device found";
    }

    inParam.channelCount = 1;
    inParam.sampleFormat = paFloat32;
    inParam.suggestedLatency = Pa_GetDeviceInfo(inParam.device) -> defaultLowInputLatency;
    inParam.hostApiSpecificStreamInfo = nullptr;

    outParam.device = Pa_GetDefaultOutputDevice();
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
        &GuitarDistortionEngine::audioCallBack,
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

    running_ = true;
    return true;

}

void GuitarDistortionEngine::stop() {
    if (!running_) return;
    if (stream_){
        Pa_StopStream(stream_);
        Pa_CloseStream(stream_);
        stream_ = nullptr;
    }
    running_ = false;
}



int GuitarDistortionEngine::audioCallBack(
    const void* inputBuffer,
    void* outputBuffer,
    unsigned long framesPerBuffer,
    const PaStreamCallbackTimeInfo* timeInfo,
    PaStreamCallbackFlags statusFlag,
    void* userdata)
{
    auto* engine = static_cast<GuitarDistortionEngine*>(userdata);
    const float* in =  static_cast<const float*>(inputBuffer);
    float* out = static_cast<float*>(outputBuffer);
    return engine -> process(in, out, framesPerBuffer);
}

void GuitarDistortionEngine::applyDistortionToBuffer(
    const float* input,
    float* output,
    std::size_t numSamples,
    float drive,
    float outputGain){
        
    };

int GuitarDistortionEngine::process(
    const float* in, float* out, unsigned long framesPerBuffer)
{
    if (!out) return paAbort;

    if(!in){
        std::fill(out, out + framesPerBuffer, 0.0f);
        return paContinue;
    }

    for (unsigned long i = 0;i < framesPerBuffer; ++i){
        float x = in[i] * drive_;

        float y = std::tanh(x);

        out[i]= y*outputGain_;
    }
    return paContinue;
}
