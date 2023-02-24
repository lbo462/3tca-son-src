#include "Tab.h"

Tab::Tab()
{
}

void Tab::configureSounds(byte pins[NUMBER_OF_SOUND_ROWS], char *filenames[NUMBER_OF_SOUND_ROWS][ROW_LEN])
{
    for (int i = 0; i < NUMBER_OF_SOUND_ROWS; i++)
        soundRows[i].configure(pins[i], filenames[i]);
}

void Tab::update()
{
    for (int i = 0; i < NUMBER_OF_SOUND_ROWS; i++)
        soundRows[i].update();
}