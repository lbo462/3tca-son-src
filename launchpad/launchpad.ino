#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

#include "InitsAndSetup.h"


/***************************************************************/
void setup()
{
  Serial.begin(9600);

  // Audio settings
  AudioMemory(10);
  setUpShield();

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

  //setup mixers
  setUpMixers();

  // configure buttons with filenames and pins
  buttons[0].configure("GOT.WAV", 0);
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
    {
      buttons[i].pressed = 1;
      Serial.print("Button ");
      Serial.print(i);
      Serial.println(" being pressed !");
    }
    else
      buttons[i].pressed = 0;
  }

  // Update buttons
  for (int i = 0; i < NUMBER_OF_BUTTONS; i++)
  {
    buttons[i].update();
  }

  delay(100); // required because of Serial.println()
}
