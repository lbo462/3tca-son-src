#include "Tab.h"

Tab::Tab()
{
    active = 0;
}

void Tab::configureSounds(byte pins[NUMBER_OF_SOUND_BUTTONS], char *filenames[NUMBER_OF_SOUND_BUTTONS])
{
    for (int i = 0; i < NUMBER_OF_SOUND_BUTTONS; i++)
        soundButtons[i].configure(pins[i], filenames[i]);
}

void Tab::update()
{
    if (active)
        for (int i = 0; i < NUMBER_OF_SOUND_BUTTONS; i++)
            soundButtons[i].update();
}

int Tab::isActive()
{
    return active;
}

void Tab::activate()
{
    active = 1;
}

void Tab::deactivate()
{
    active = 0;
}