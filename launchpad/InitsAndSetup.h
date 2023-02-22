#ifndef inits_teensy_h_
#define inits_teensy_h_

#include <Audio.h>
#include "Button.h"

#define NUMBER_OF_BUTTONS 16

// SD Card reading
#define SDCARD_CS_PIN 10
#define SDCARD_MOSI_PIN 11 // not actually used
#define SDCARD_SCK_PIN 13  // not actually used

extern Button buttons[NUMBER_OF_BUTTONS];

void setUpMixers();

void setUpShield();

#endif
