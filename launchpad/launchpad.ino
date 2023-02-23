#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

#include "SoundButtonRow.h"

// SD Card reading
#define SDCARD_CS_PIN 10
#define SDCARD_MOSI_PIN 11 // not actually used
#define SDCARD_SCK_PIN 13  // not actually used

// output and audio shield
AudioControlSGTL5000 audioShield;

SoundButtonRow soundButtonRow;

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
  AudioMemory(10);
  audioShield.enable();
  audioShield.volume(1);

  setupGain();

  // configure buttons with filenames and pins
  char *filenames[ROW_LEN] = {"MESSAGE.WAV", "MESSAGE.WAV", "MESSAGE.WAV"};
  soundButtonRow.configure(A0, filenames);

  Serial.println("Setup done.");

  delay(500);
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
  Serial.print(" ");
  Serial.print(soundButtonRow.buttons[0].playerIndex);
  Serial.print(soundButtonRow.buttons[1].playerIndex);
  Serial.print(soundButtonRow.buttons[2].playerIndex);

  Serial.println();
  delay(100); // required because of Serial.println()
}
