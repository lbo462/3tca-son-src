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
}

void loop()
{
  // Read inputs
  int analogValueRead = analogRead(A7);
  int digitalValueRead = digitalRead(0);

  Serial.println(analogValueRead);

  delay(100); // required because of Serial.println()
}
