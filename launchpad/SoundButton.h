#ifndef soundbutton_teensy_h_
#define soundbutton_teensy_h_

#include "PlayerMgmt.h"

class SoundButton
{
public:
    SoundButton();
    ~SoundButton();

    void configure(byte pin_, char *filename_); // configure player filename

    /*  Test if the button is pressed and play the song in that case */
    void update();

    void press();    // press the button
    void release();  // release it
    int isPressed(); // check if pressed

    int getPlayerIndex(); // return the player index given to the button to play

private:
    char *filename;
    int pin;
    int pressed;     // Button pressed boolean
    int playerIndex; // index of the audio player
    int hasPlayer(); // returns true if a player is set
};

#endif
