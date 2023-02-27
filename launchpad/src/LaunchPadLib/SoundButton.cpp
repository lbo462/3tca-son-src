#include "SoundButton.h"

#define MAX_DELAY 10000
#define MIN_DELAY 100

SoundButton::SoundButton(int pin_, const unsigned int *sample_)
{
    pin = pin_;
    sample = sample_;
    pressed = 0;
    playerIndex = -1; // index -1 implies that no player is set
    keepPressed = 0;
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
        Keep playing if register button was pushed
    */
    if (digitalRead(pin))
        press();
    else
        release();

    if (digitalRead(REGISTER_PIN) && pressed)
        keepPressed = 1;

    if ((pressed || keepPressed) && hasPlayer())
    {
        playerMgmt.p[playerIndex].update(); // update timer
        if (!playerMgmt.p[playerIndex].isPlaying())
            playerMgmt.p[playerIndex].play();
    }
}

void SoundButton::press()
{
    // stop keeping press if button was pressed again
    if (keepPressed && !pressed)
        keepPressed = 0;

    pressed = 1;

    // Get and configure a player
    if (!hasPlayer())
    {
        playerIndex = playerMgmt.getPlayer();
        if (hasPlayer())
        { // verify if a player was found
            // Retrieve current delay
            int analogReadFromPot = analogRead(SET_FREQ_PIN);
            unsigned int period = map(analogReadFromPot, 0, 1023, MIN_DELAY, MAX_DELAY);
            playerMgmt.p[playerIndex].configure(sample, period);
        }
        // else, no player is set and the button won't play anything

        Serial.print("Player #");
        Serial.print(playerIndex);
        Serial.print(" in use ");
    }
}

void SoundButton::release()
{
    pressed = 0;

    // Free the player
    if (hasPlayer() && !keepPressed)
    {
        playerMgmt.p[playerIndex].release();

        Serial.print("Player #");
        Serial.print(playerIndex);
        Serial.print(" released ");

        playerIndex = -1;
    }
}

int SoundButton::hasPlayer()
{
    return playerIndex != -1;
}