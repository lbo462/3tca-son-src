#include "Player.h"

Player::Player()
{
    available = 1;
    playing = 0;
    period = 1000;
    startedWaiting = 0; // 0 means the timer did not start
}

void Player::configure(const unsigned int *sample_, unsigned int period_)
{
    // Reset
    if (isPlaying())
        stop();
    startedWaiting = 0;

    // Configure
    sample = (unsigned int *)sample_;
    period = period_;

    // Take possession
    available = 0;

    Serial.print("delay = ");
    Serial.print(period);
    Serial.print(" ");
}

void Player::release()
{
    if (isPlaying())
        stop();
    available = 1; // make available
}

int Player::isAvailable()
{
    return available;
}

void Player::play()
{
    memPlayer.play(sample);
    playing = 1;
}

void Player::stop()
{
    memPlayer.stop();
    playing = 0;
    startedWaiting = 0;
}

int Player::isPlaying()
{
    return playing;
}

void Player::update()
{
    if (memPlayer.isPlaying())
        playing = 1;
    else if (playing)
    {
        if (startedWaiting)
        {
            if (millis() - startedWaiting > period)
            {
                playing = 0;
                startedWaiting = 0;
            }
        }
        else
            startedWaiting = millis();
    }
}