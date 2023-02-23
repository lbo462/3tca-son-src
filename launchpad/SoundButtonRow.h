#ifndef soundbuttonrow_teensy_h_
#define soundbuttonrow_teensy_h_

#include <map>

#include "SoundButton.h"

#define ROW_LEN 3 // number of buttons per row /!\ THIS SHOULD NOT BE CHANGED /!\!
#define DELTA 30  // trust interval for analog reading

class SoundButtonRow
{
public:
    SoundButtonRow();
    ~SoundButtonRow();

    void configure(int pin_, char *filenames[ROW_LEN]);
    void update();

    SoundButton buttons[ROW_LEN];

private:
    int pin;
};

#endif
