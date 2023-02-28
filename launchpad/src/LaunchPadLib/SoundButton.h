#ifndef soundbutton_teensy_h_
#define soundbutton_teensy_h_

#include "Pins.h"
#include "PlayerMgmt.h"

#define MAX_DELAY 2000
#define MIN_DELAY 0

class SoundButton
{
public:
    SoundButton(int pin_, const unsigned int *sample_);
    ~SoundButton();

    /*  Test if the button is pressed and play the song in that case */
    void update();

private:
    const unsigned int *sample;
    int pin;
    int pressed;     // Button pressed boolean
    int playerIndex; // index of the audio player
    int keepPressed; // button should stay pressed even if released

    void press();   // press the button
    void release(); // release it

    int hasPlayer(); // returns true if a player is set
};

#endif
