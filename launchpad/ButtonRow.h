#ifndef buttonrow_teensy_h_
#define buttonrow_teensy_h_

#include <map>

#include "Button.h"

#define ROW_LEN 3 // number of buttons per row /!\ THIS SHOULD NOT BE CHANGED /!\!
#define DELTA 30  // trust interval for analog reading

class ButtonRow
{
public:
    ButtonRow();
    ~ButtonRow();

    void configure(int pin_, char *filenames[ROW_LEN]);
    void update();

    Button buttons[ROW_LEN];

private:
    int pin;
};

#endif
