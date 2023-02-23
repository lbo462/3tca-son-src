#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

#include "InitsAndSetup.h"

void setup()
{
  Serial.begin(9600);

  // Audio settings
  AudioMemory(10);
  setUpShield();

  // SD card reading
  SPI.setMOSI(SDCARD_MOSI_PIN);
  SPI.setSCK(SDCARD_SCK_PIN);
  if (SD.begin(SDCARD_CS_PIN))
  {
    // stop here, but print a message repetitively
    while (1)
    {
      Serial.println("Unable to access the SD card");
      delay(500);
    }
  }

  // setup mixers
  setUpMixers();

  // configure buttons with filenames and pins
  char *filenames[ROW_LEN] = {"MESSAGE.WAV", "MESSAGE.WAV", "MESSAGE.WAV"};
  soundButtonRow.configure(A0, filenames);
}

void loop()
{
  // Read inputs
  Serial.print(analogRead(A0));

  soundButtonRow.update();

  Serial.print(" ");
  Serial.print(soundButtonRow.buttons[0].isPressed());
  Serial.print(soundButtonRow.buttons[1].isPressed());
  Serial.print(soundButtonRow.buttons[2].isPressed());

  Serial.println();
  delay(100); // required because of Serial.println()
}
