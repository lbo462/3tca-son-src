#ifndef tab_teensy_h_
#define tab_teensy_h_

#include "SoundButton.h"

#define NUMBER_OF_SOUND_BUTTONS 3

class Tab
{
public:
    Tab(const int pins[NUMBER_OF_SOUND_BUTTONS], const unsigned int *samples[NUMBER_OF_SOUND_BUTTONS]);
    ~Tab();

    void update();

    // tab state
    int isActive();
    void activate();
    void deactivate();

private:
    SoundButton *soundButtons = (SoundButton *)malloc(sizeof(SoundButton) * NUMBER_OF_SOUND_BUTTONS);

    int active;
};

#endif