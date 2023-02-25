#ifndef tab_teensy_h_
#define tab_teensy_h_

#include "SoundButton.h"

#define NUMBER_OF_SOUND_BUTTONS 3

class Tab
{
public:
    Tab();
    void configureSounds(byte pins[NUMBER_OF_SOUND_BUTTONS], char *filenames[NUMBER_OF_SOUND_BUTTONS]);

    void update();

    // tab state
    int isActive();
    void activate();
    void deactivate();

    // TODO make private
    SoundButton soundButtons[NUMBER_OF_SOUND_BUTTONS];

private:
    int active;
};

#endif