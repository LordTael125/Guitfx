#include <iostream>
#include <Effects/DistortionEngine.hpp>
#include <algorithm>
#include <cmath>

DistortionEngine::DistortionEngine() : stream_(nullptr), drive_(10.0f), threshold_(0.6f), outputGain_(0.3f),running_(false){ }

DistortionEngine::~DistortionEngine() {stop();}

int DistortionEngine::start(Audio::audioBuffer streamBuffer) 
{
  running_ = true;
  return this->double_filterDistort(streamBuffer);
}

void DistortionEngine::stop() { running_ = false; }

int DistortionEngine::simple_tanhDistort(Audio::audioBuffer streamBuffer) {
  if (!streamBuffer.out)
    return paAbort;

  if (!streamBuffer.in) {
    std::fill(streamBuffer.out, streamBuffer.out + streamBuffer.framesPerBuffer,
              0.0f);
    return paContinue;
  }

  for (unsigned long i = 0; i < streamBuffer.framesPerBuffer; ++i) {
    float x = streamBuffer.in[i] * drive_;

    float y = std::tanh(x);

    streamBuffer.out[i] = y * outputGain_;
  }
  return paContinue;
}

int DistortionEngine::double_filterDistort(Audio::audioBuffer streamBuffer) {
  if (!streamBuffer.out)
    return paAbort;

  if (!streamBuffer.in) {
    std::fill(streamBuffer.out, streamBuffer.out + streamBuffer.framesPerBuffer,
              0.0f);
    return paContinue;
  }

  for (int i = 0; i < streamBuffer.framesPerBuffer; i++) {
    float x = streamBuffer.in[i] * drive_;
    float y;

    if (x > 0) {
      y = std::tanh(x);
    } else {
      y = -std::tanh(x * 1.5) / 1.5;
    }

    streamBuffer.out[i] = y * outputGain_;
    prev_lf_input = x;
  };

  return paContinue;
};

float DistortionEngine::low_pass_filter(float x) {
  return 0.0f;
};

float DistortionEngine::high_pass_filter(float x) {
  return 0.0f;
};
