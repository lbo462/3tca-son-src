#include "Tab.h"

Tab::Tab(const int pins[NUMBER_OF_SOUND_BUTTONS], char *name_, const unsigned int *samples[NUMBER_OF_SOUND_BUTTONS])
{
    active = 0; // make inactive by default
    name = name_;
    /* Configure sound buttons */
    for (int i = 0; i < NUMBER_OF_SOUND_BUTTONS; i++)
        soundButtons[i] = SoundButton((int)pins[i], samples[i]);
}

Tab::~Tab()
{
    free(soundButtons);
}

void Tab::update()
{
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
    for (int i = 0; i < NUMBER_OF_SOUND_BUTTONS; i++)
        soundButtons[i].activate();
}

void Tab::deactivate()
{
    active = 0;
    for (int i = 0; i < NUMBER_OF_SOUND_BUTTONS; i++)
        soundButtons[i].deactivate();
}