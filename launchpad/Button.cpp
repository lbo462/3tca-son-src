#include "Button.h"

Button::Button()
{
    pressed = 0;
}

void Button::configure(char *filename_, int pin_)
{
    /* WARNING : files should be WAV files with a 16 Bit resolution and a 44100 Hz audio frequency */
    filename = filename_;
    pin = pin_;
}

void Button::update()
{
    /*
        /!\ Should be called at each frame /!\
        Play file if button is pressed
        -> Button pressed is updated inside the Arduino loop
    */

    if (pressed)
        play();
}

void Button::play()
{
    /* Use wav player to play the file */
    player.play(filename);
    delay(10); // delay required by the wav player
}