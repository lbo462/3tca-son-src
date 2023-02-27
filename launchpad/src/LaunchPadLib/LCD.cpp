#include "LCD.h"

LCD::LCD()
{
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
}

LCD::update()
{
    // volume
    lcd.print("vol: ");
    lcd.print(gain * 100);
    lcd.print("% ");

    // tab
    lcd.setCursor(0, 1);
    lcd.print("Tab");
    lcd.print("#");
    lcd.print(tab);
    lcd.print(" ");
}

LCD::setData(float gain_, int tab_)
{
    gain = gain_;
    tab = tab_;
}