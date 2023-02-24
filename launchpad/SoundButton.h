#ifndef soundbutton_teensy_h_
#define soundbutton_teensy_h_

#include "PlayerMgmt.h"

class SoundButton
{
public:
    SoundButton();
    ~SoundButton();

    void configure(byte pin_, char *filename_); // configure player filename

    /* This test if the button is pressed and play the song in that case */
    void update();

    void press();    // press the button
    void release();  // release it
    int isPressed(); // check if pressed

    // TODO make private
    int playerIndex; // index of the audio player

private:
    char *filename;
    int pin;
    int pressed;     // Button pressed boolean
    int hasPlayer(); // returns true if a player is set
};

#endif
