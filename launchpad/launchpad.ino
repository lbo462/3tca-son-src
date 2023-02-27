#include "src/LaunchPadLib/LaunchPad.h"

// output and audio shield
AudioControlSGTL5000 audioShield;

// Tab manager to manage everything (wow)
TabMgmt tabMgmt = TabMgmt();

void setup()
{
  Serial.begin(9600);

  // Audio settings
  Serial.println("Configuring audio shield ...");
  AudioMemory(10);
  audioShield.enable();
  audioShield.volume(1);

  tabMgmt.configure();

  playerMgmt.setGain(0.5);

  Serial.println("Setup done.");

  delay(500);
}

void loop()
{
  // Compute and set gain
  float gain = map((float)analogRead(GAIN_PIN), 0, 1023, 0, 1);
  playerMgmt.setGain(gain);

  // Print current volume to console
  Serial.print(gain * 100);
  Serial.print("% ");

  // Print current tab to console
  Serial.print("#");
  Serial.print(tabMgmt.getTabNumber());
  Serial.print(" ");

  tabMgmt.update(); // update current frame

  Serial.println();

  delay(100); // required because of Serial.println() and tab swapping !!
}
