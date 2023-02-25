#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

#include "TabMgmt.h"

// Define pins for tab swapping
#define NEXT_TAB_PIN 0
#define PREV_TAB_PIN 1

// SD Card reading
#define SDCARD_CS_PIN BUILTIN_SDCARD
#define SDCARD_MOSI_PIN 11 // not actually used
#define SDCARD_SCK_PIN 13  // not actually used

// output and audio shield
AudioControlSGTL5000 audioShield;

TabMgmt tabMgmt;

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

  Serial.println("Setup done.");

  delay(500);
}

void loop()
{
  if (digitalRead(NEXT_TAB_PIN))
    tabMgmt.nextTab();
  if (digitalRead(PREV_TAB_PIN))
    tabMgmt.previousTab();

  tabMgmt.update();

  Serial.print("Tab #");
  Serial.print(tabMgmt.getTabNumber());
  Serial.print(" ");

  Serial.print(tabMgmt.tabs[tabMgmt.currentTabIndex].soundButtons[0].isPressed());
  Serial.print(tabMgmt.tabs[tabMgmt.currentTabIndex].soundButtons[1].isPressed());
  Serial.print(tabMgmt.tabs[tabMgmt.currentTabIndex].soundButtons[2].isPressed());
  Serial.print(" ");
  Serial.print(tabMgmt.tabs[tabMgmt.currentTabIndex].soundButtons[0].getPlayerIndex());
  Serial.print(tabMgmt.tabs[tabMgmt.currentTabIndex].soundButtons[1].getPlayerIndex());
  Serial.print(tabMgmt.tabs[tabMgmt.currentTabIndex].soundButtons[2].getPlayerIndex());

  Serial.println();
  delay(100); // required because of Serial.println()
}
