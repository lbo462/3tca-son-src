#include "Tab.h"

Tab::Tab(byte pins[NUMBER_OF_SOUND_BUTTONS], const unsigned int *samples[NUMBER_OF_SOUND_BUTTONS])
{
    active = 0; // make inactive by default
    /* Configure sound buttons */
    for (int i = 0; i < NUMBER_OF_SOUND_BUTTONS; i++)
        soundButtons[i] = SoundButton(pins[i], samples[i]);
}

Tab::~Tab()
{
    free(soundButtons);
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