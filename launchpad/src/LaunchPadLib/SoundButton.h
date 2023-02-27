#ifndef soundbutton_teensy_h_
#define soundbutton_teensy_h_

#include "Pins.h"
#include "PlayerMgmt.h"

class SoundButton
{
public:
    SoundButton(int pin_, const unsigned int *sample_);
    ~SoundButton();

    /*  Test if the button is pressed and play the song in that case */
    void update();

    void press();    // press the button
    void release();  // release it
    int isPressed(); // check if pressed

    int getPlayerIndex(); // return the player index given to the button to play

private:
    const unsigned int *sample;
    int pin;
    int pressed;     // Button pressed boolean
    int playerIndex; // index of the audio player
    int keepPressed; // button should stay pressed even if released

    int hasPlayer(); // returns true if a player is set
};

#endif
