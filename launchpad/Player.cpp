#include "Player.h"

Player::Player()
{
    available = 1;
}

void Player::configure(int *samples_)
{
    samples = samples_;
    available = 0;
}

void Player::release()
{
    if (isPlaying())
        stop();
    available = 1;
}

int Player::isAvailable()
{
    return available;
}

void Player::play()
{
    memPlayer.play(samples);
}

void Player::stop()
{
    memPlayer.stop();
}

int Player::isPlaying()
{
    return memPlayer.isPlaying();
}