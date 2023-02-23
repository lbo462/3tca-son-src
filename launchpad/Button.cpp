#include "Button.h"

Button::Button()
{
    pressed = 0;
}

void Button::configure(char *filename_)
{
    /* WARNING : files should be WAV files with a 16 Bit resolution and a 44100 Hz audio frequency */
    filename = filename_;
}

void Button::update()
{
    /*
        /!\ Should be called at each frame /!\
        Play file if button is pressed
    */
    int filePlaying = player.isPlaying();

    if (pressed && !filePlaying)
        play();
    else if (!pressed && filePlaying)
        stop();
}

void Button::play()
{
    /* Use wav player to play the file */
    player.play(filename);
    delay(10); // delay required by the wav player
}

void Button::stop()
{
    /* Stop wav player */
    player.stop();
}

void Button::press()
{
    pressed = 1;
}

void Button::release()
{
    pressed = 0;
}

int Button::isPressed()
{
    return pressed;
}