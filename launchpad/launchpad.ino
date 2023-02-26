#include "src/LaunchpadLib/LaunchPad.h"

// output and audio shield
AudioControlSGTL5000 audioShield;

// Tab manager to manage everything (wow)
TabMgmt tabMgmt;

void setup()
{
  Serial.begin(9600);

  // Audio settings
  Serial.println("Configuring audio shield ...");
  AudioMemory(10);
  audioShield.enable();
  audioShield.volume(1);

  playerMgmt.setGain(0.5);

  Serial.println("Setup done.");

  delay(500);
}

void loop()
{
  // Compute and set gain
  int gain = map(analogRead(GAIN_PIN), 0, 1023, 0, 1);
  playerMgmt.setGain(gain);

  // Print current volume to console
  Serial.print("Volume ");
  Serial.print(gain * 100);
  Serial.print("% ");

  // Check tab swap
  if (digitalRead(NEXT_TAB_PIN))
    tabMgmt.nextTab();
  if (digitalRead(PREV_TAB_PIN))
    tabMgmt.previousTab();

  // Print current tab to console
  Serial.print("Tab #");
  Serial.print(tabMgmt.getTabNumber());
  Serial.print(" ");

  tabMgmt.update(); // update current frame

  // Debug output
  Serial.print(tabMgmt.tabs[tabMgmt.getTabNumber() - 1].soundButtons[0].isPressed());
  Serial.print(tabMgmt.tabs[tabMgmt.getTabNumber() - 1].soundButtons[1].isPressed());
  Serial.print(tabMgmt.tabs[tabMgmt.getTabNumber() - 1].soundButtons[2].isPressed());
  Serial.print(" ");
  Serial.print(tabMgmt.tabs[tabMgmt.getTabNumber() - 1].soundButtons[0].getPlayerIndex());
  Serial.print(tabMgmt.tabs[tabMgmt.getTabNumber() - 1].soundButtons[1].getPlayerIndex());
  Serial.print(tabMgmt.tabs[tabMgmt.getTabNumber() - 1].soundButtons[2].getPlayerIndex());

  Serial.println();

  // debugging without hardware from the serial monitor
  String command;
  if (Serial.available())
  {
    command = Serial.readStringUntil('\n');
    if (command.indexOf("dw") >= 0)
    {
      digitalWrite(command[2], HIGH);
    }
    else if (command.indexOf("aw") >= 0)
    {
      analogWrite(command[2], command.substring(3, command.length()).toInt());
    }
    else
    {
      Serial.println("Invalid command");
    }
  }

  delay(100); // required because of Serial.println() and tab swapping !!
}
