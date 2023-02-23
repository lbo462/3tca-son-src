#ifndef soundbutton_teensy_h_
#define soundbutton_teensy_h_

#include <Audio.h>

class SoundButton
{
public:
    SoundButton();

    AudioPlaySdWav player; // is public for patchCord linking only. wav files player

    void configure(char *filename_); // configure filename and pin

    /* This test if the button is pressed and play the song in that case */
    void update();

    void press();    // press the button
    void release();  // release it
    int isPressed(); // check if pressed

private:
    /* WARNING : files should be WAV files with a 16 Bit resolution and a 44100 Hz audio frequency */
    char *filename;

    /* These methods should only be called by update() */
    void play(); // play the file
    void stop(); // stop file from playing

    int pressed; // Button pressed boolean
};

#endif
