#ifndef button_teensy_h_
#define button_teensy_h_

#include <Audio.h>

class Button
{
public:
    Button();

    int pressed;           // Button pressed boolean
    int analogValue;       // Arduino analog value
    AudioPlaySdWav player; // is public for patchCord linking only. wav files player

    void configure(char *filename_, int analogValue_); // configure filename and pin

    /* This test if the button is pressed and play the song in that case */
    void update(int analogValueRead);

private:
    /* WARNING : files should be WAV files with a 16 Bit resolution and a 44100 Hz audio frequency */
    char *filename;

    /* These methods should only be called by update() */
    void play(); // play the file
    void stop(); // stop file from playing

    int playing(); // returns true if the player is playing something
};

#endif
