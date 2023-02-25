#include "Tab.h"

Tab::Tab()
{
    active = 0;
}

void Tab::configureSounds(byte pins[NUMBER_OF_SOUND_BUTTONS], const unsigned int *samples[NUMBER_OF_SOUND_BUTTONS])
{
    for (int i = 0; i < NUMBER_OF_SOUND_BUTTONS; i++)
        soundButtons[i].configure(pins[i], samples[i]);
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