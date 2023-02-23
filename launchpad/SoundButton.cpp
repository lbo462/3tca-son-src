#include "SoundButton.h"

SoundButton::SoundButton()
{
    pressed = 0;
}

void SoundButton::configure(char *filename_)
{
    /* WARNING : files should be WAV files with a 16 Bit resolution and a 44100 Hz audio frequency */
    filename = filename_;
}

void SoundButton::update()
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

void SoundButton::play()
{
    /* Use wav player to play the file */
    player.play(filename);
    delay(10); // delay required by the wav player
}

void SoundButton::stop()
{
    /* Stop wav player */
    player.stop();
}

void SoundButton::press()
{
    pressed = 1;
}

void SoundButton::release()
{
    pressed = 0;
}

int SoundButton::isPressed()
{
    return pressed;
}