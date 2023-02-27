#ifndef lcd_teensy_h
#define lcd_teensy_h

#include <LiquidCrystal.h>
#include "Pins.h"

class LCD
{
public:
    LCD();

    void update();

    void setData(float gain_, int tab_);

private:
    LiquidCrystal lcd(LCD_RS, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

    float gain;

    int tab;
}

#endif