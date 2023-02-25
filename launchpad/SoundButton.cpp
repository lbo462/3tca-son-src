#include "Pins.h"
#include "SoundButton.h"

SoundButton::SoundButton(byte pin_, const unsigned int *sample_)
{
    pin = pin_;
    sample = sample_;
    pressed = 0;
    playerIndex = -1; // index -1 implies that no player is set
}

SoundButton::~SoundButton()
{
    if (hasPlayer())
        playerMgmt.p[playerIndex].release();
}

void SoundButton::update()
{
    /*
        /!\ Should be called at each frame /!\
        Play sound if button is pressed
    */
    if (digitalRead(pin) && !pressed)
        press();
    else if (pressed)
        release();

    if (pressed && hasPlayer())
    {
        playerMgmt.p[playerIndex].update(); // update timer
        if (!playerMgmt.p[playerIndex].isPlaying())
            playerMgmt.p[playerIndex].play();
    }
}

void SoundButton::press()
{
    pressed = 1;

    // Retrieve current delay
    int analogReadFromPot = analogRead(SET_FREQ_PIN);
    unsigned int period = 1000;

    // Get and configure a player
    if (!hasPlayer())
        playerIndex = playerMgmt.getPlayer();
    if (hasPlayer()) // verify if a player was found
        playerMgmt.p[playerIndex].configure(sample, period);
    // else, no player is set and the button won't play anything
}

void SoundButton::release()
{
    pressed = 0;
    // Free the player
    if (hasPlayer())
    {
        playerMgmt.p[playerIndex].release();
        playerIndex = -1;
    }
}

int SoundButton::getPlayerIndex()
{
    return playerIndex;
}

int SoundButton::hasPlayer()
{
    return playerIndex != -1;
}

int SoundButton::isPressed()
{
    return pressed;
}