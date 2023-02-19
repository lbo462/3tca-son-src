#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

#include "Button.h"

#define NUMBER_OF_BUTTONS 2

// SD Card reading
#define SDCARD_CS_PIN 10
#define SDCARD_MOSI_PIN 11 // not actually used
#define SDCARD_SCK_PIN 13  // not actually used

AudioControlSGTL5000 audioShield;
AudioOutputI2S out;

Button buttons[NUMBER_OF_BUTTONS];

/**** TODO find a way to nicely implement these connections ****/

// Mixers to mix differents audio sources
AudioMixer4 mixer1, mixer2;

// Connect WAV players to mixers
AudioConnection patchCord1(buttons[0].player, 0, mixer1, 0);
AudioConnection patchCord2(buttons[0].player, 1, mixer2, 0);
AudioConnection patchCord3(buttons[1].player, 0, mixer1, 1);
AudioConnection patchCord4(buttons[1].player, 1, mixer2, 1);

// Connect mixers to output
AudioConnection patchCord5(mixer1, 0, out, 0);
AudioConnection patchCord6(mixer2, 0, out, 1);

/***************************************************************/

void setup()
{
  Serial.begin(9600);

  // Audio settings
  AudioMemory(10);
  audioShield.enable();
  audioShield.volume(0.5);

  // SD card reading
  SPI.setMOSI(SDCARD_MOSI_PIN);
  SPI.setSCK(SDCARD_SCK_PIN);
  if (!(SD.begin(SDCARD_CS_PIN)))
  {
    // stop here, but print a message repetitively
    while (1)
    {
      Serial.println("Unable to access the SD card");
      delay(500);
    }
  }

  // configure buttons with filenames and pins
  buttons[0].configure("MESSAGE.WAV", 0);
  buttons[1].configure("MESSAGE.WAV", 1);

  // configure pin modes
  for (int i = 0; i < NUMBER_OF_BUTTONS; i++)
  {
    pinMode(buttons[i].pin, INPUT_PULLUP);
  }
}

void loop()
{

  // Read digital inputs
  for (int i = 0; i < NUMBER_OF_BUTTONS; i++)
  {
    int buttonPressed = digitalRead(buttons[i].pin);
    if (buttonPressed == HIGH)
      buttons[i].pressed = 1;
    else
      buttons[i].pressed = 0;
  }

  // Update buttons
  for (int i = 0; i < NUMBER_OF_BUTTONS; i++)
  {
    buttons[i].update();
  }
}
