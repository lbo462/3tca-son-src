#ifndef button_teensy_h_
#define button_teensy_h_

#include <Audio.h>

#define FILENAME_MAX_SIZE 255

class Button
{
public:
    Button();

    int pressed;           // Button pressed ? true / false
    int pin;               // Arduino pin
    AudioPlaySdWav player; // got public for patchCord linking only

    void configure(char *filename_, int pin_); // configure filename and pin

    /* The update method test if the button is pressed and play the song in that case */
    void update();

private:
    char *filename;

    /* This method should only be called by update() */
    void play();
};

#endif
