#include "Tab.h"

Tab::Tab()
{
}

void Tab::configureSounds(byte pins[NUMBER_OF_SOUND_BUTTONS], char *filenames[NUMBER_OF_SOUND_BUTTONS])
{
    for (int i = 0; i < NUMBER_OF_SOUND_BUTTONS; i++)
        soundButtons[i].configure(pins[i], filenames[i]);
}

void Tab::update()
{
    for (int i = 0; i < NUMBER_OF_SOUND_BUTTONS; i++)
        soundButtons[i].update();
}