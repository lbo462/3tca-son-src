#ifndef faust_teensy_h_
#define faust_teensy_h_

#include "Arduino.h"
#include "AudioStream.h"
#include "Audio.h"

#include "Noise.h"
#include "BiquadFilter.h"

class MyDsp : public AudioStream
{
  public:
    MyDsp();
    ~MyDsp();
    
    virtual void update(void);
    void resonlp(float fc, float Q, float gain);
    void resonbp(float fc, float Q, float gain);

  private:
    Noise noise;
    BiquadFilter biquadFilter;
    
};

#endif
