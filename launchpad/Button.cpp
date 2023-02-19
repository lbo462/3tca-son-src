#include "Button.h"

Button::Button()
{
    pin = 0;
    pressed = 0;
}

void Button::configure(char *filename_, int pin_)
{
    filename = filename_;
    pin = pin_;
}

void Button::update()
{
    if (pressed)
        play();
}

void Button::play()
{
    player.play(filename);
    delay(10);
}