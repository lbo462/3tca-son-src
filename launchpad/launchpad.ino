#include <LiquidCrystal.h>
#include "src/LaunchPadLib/LaunchPad.h"

// output and audio shield
AudioControlSGTL5000 audioShield;

// Tab manager to manage everything (wow)
TabMgmt tabMgmt = TabMgmt();

// lcd for display
LiquidCrystal lcd(LCD_RS, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

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

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);

  Serial.println("Setup done.");
  lcd.print("Starting ...");

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
  Serial.print(" (");
  Serial.print(tabMgmt.getTabName());
  Serial.print(") ");

  // LCD display
  LCDprint(gain, tabMgmt.getTabNumber(), tabMgmt.getTabName());

  tabMgmt.update(); // update current frame

  Serial.println();

  delay(100); // required because of Serial print
}

void LCDprint(float gain, int tabNumber, char *tabName)
{
  lcd.clear();

  // Volume
  lcd.print("Vol: ");
  lcd.print((int)(gain * 100));
  lcd.print("% ");

  // Tab number and Name
  lcd.setCursor(0, 1);
  lcd.print("Tab ");
  lcd.print("#");
  lcd.print(tabNumber);
  lcd.print(" ");
  lcd.print(tabName);
  lcd.print(" ");
}
