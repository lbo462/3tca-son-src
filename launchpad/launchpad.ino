#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

#include "Tab.h"

// SD Card reading
#define SDCARD_CS_PIN 10
#define SDCARD_MOSI_PIN 11 // not actually used
#define SDCARD_SCK_PIN 13  // not actually used

// output and audio shield
AudioControlSGTL5000 audioShield;

Tab tab1;

// configure buttons with filenames and pins
byte pins[NUMBER_OF_SOUND_BUTTONS] = {0, 1, 2};
char *filenames[NUMBER_OF_SOUND_BUTTONS] = {"PUNCH.WAV", "BASS.WAV", "MESSAGE.WAV"};

void setup()
{
  Serial.begin(9600);

  while (!(SD.begin(SDCARD_CS_PIN)))
  {
    Serial.println("Unable to access the SD card");
    delay(1000);
  }

  // SD card reading
  SPI.setMOSI(SDCARD_MOSI_PIN);
  SPI.setSCK(SDCARD_SCK_PIN);

  Serial.println("Able to access SD Card.");

  // Audio settings
  Serial.println("Configuring audio shield ...");
  AudioMemory(50);
  audioShield.enable();
  audioShield.volume(1);

  setupGain();

  tab1.configureSounds(pins, filenames);

  Serial.println("Setup done.");

  delay(500);
}

void loop()
{
  // Read inputs

  tab1.update();

  Serial.print(tab1.soundButtons[0].isPressed());
  Serial.print(tab1.soundButtons[1].isPressed());
  Serial.print(tab1.soundButtons[2].isPressed());
  Serial.print(" ");
  Serial.print(tab1.soundButtons[0].playerIndex);
  Serial.print(tab1.soundButtons[1].playerIndex);
  Serial.print(tab1.soundButtons[2].playerIndex);
  Serial.print(" ");
  Serial.print(playerMgmt.p[0].isAvailable());

  Serial.println();
  delay(100); // required because of Serial.println()
}
