#ifndef tab_teensy_h_
#define tab_teensy_h_

#include "SoundButtonRow.h"

#define NUMBER_OF_SOUND_ROWS 1

class Tab
{
public:
    Tab();
    void configureSounds(byte pins[NUMBER_OF_SOUND_ROWS], char *filenames[NUMBER_OF_SOUND_ROWS][ROW_LEN]);

    void update();

    // TODO make private
    SoundButtonRow soundRows[NUMBER_OF_SOUND_ROWS];

private:
};

#endif