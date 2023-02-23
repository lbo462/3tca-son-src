#include "SoundButtonRow.h"

SoundButtonRow::SoundButtonRow()
{
}

SoundButtonRow::~SoundButtonRow()
{
    delete[] buttons;
}

void SoundButtonRow::configure(int pin_, char *filenames[ROW_LEN])
{
    /*
        Configure every buttons with the filenames to play
    */
    for (int i = 0; i < ROW_LEN; i++)
        buttons[i].configure(filenames[i]);
}

void SoundButtonRow::update()
{
    /*
        Check button presses

        With the following resistances : [320, 450, 230]
        [1, 0, 0] -> 417.1851851851852
        [0, 1, 0] -> 336.2388059701492
        [1, 1, 0] -> 553.4958519463944
        [0, 0, 1] -> 500.62222222222226
        [1, 0, 1] -> 636.7112024665981
        [0, 1, 1] -> 605.2564203871988
        [1, 1, 1] -> 697.1473950000964
    */

    // first release every button
    buttons[0].release();
    buttons[1].release();
    buttons[2].release();

    int analogValue = analogRead(pin);
    // press corresponding buttons
    if (analogValue - DELTA < 417 && 417 < analogValue + DELTA)
    {
        buttons[0].press();
    }
    if (analogValue - DELTA < 336 && 336 < analogValue + DELTA)
    {
        buttons[2].press();
    }
    if (analogValue - DELTA < 553 && 553 < analogValue + DELTA)
    {
        buttons[0].press();
        buttons[1].press();
    }
    if (analogValue - DELTA < 500 && 500 < analogValue + DELTA)
    {
        buttons[2].press();
    }
    if (analogValue - DELTA < 636 && 636 < analogValue + DELTA)
    {
        buttons[0].press();
        buttons[2].press();
    }
    if (analogValue - DELTA < 605 && 605 < analogValue + DELTA)
    {
        buttons[1].press();
        buttons[2].press();
    }
    if (analogValue - DELTA < 697 && 697 < analogValue + DELTA)
    {
        buttons[0].press();
        buttons[1].press();
        buttons[2].press();
    }

    /*
        Update buttons
    */
    for (int i = 0; i < ROW_LEN; i++)
        buttons[i].update();
}
