#include "SoundButton.h"

SoundButton::SoundButton()
{
    pressed = 0;
    playerIndex = -1; // index -1 implies that no player is set
}

SoundButton::~SoundButton()
{
    if (hasPlayer())
        playerMgmt.p[playerIndex].release();
}

void SoundButton::configure(char *filename_)
{
    filename = filename_;
}

void SoundButton::update()
{
    /*
        /!\ Should be called at each frame /!\
        Play file if button is pressed
    */
    if (pressed && hasPlayer())
    {
        if (!playerMgmt.p[playerIndex].isPlaying())
            playerMgmt.p[playerIndex].play();
    }
}

void SoundButton::press()
{
    if (!pressed) // do not press the button if already pressed ^^
    {
        pressed = 1;
        // Get and configure a player
        playerIndex = playerMgmt.getPlayer();
        if (hasPlayer())
            playerMgmt.p[playerIndex].configure(filename);
        // else, no player is set and the button won't play anything
    }
}

void SoundButton::release()
{
    if (pressed) // do not release the button if already released ^^
    {
        pressed = 0;
        // Free the player
        if (hasPlayer())
            playerMgmt.p[playerIndex].release();
    }
}

int SoundButton::hasPlayer()
{
    return playerIndex != -1;
}

int SoundButton::isPressed()
{
    return pressed;
}