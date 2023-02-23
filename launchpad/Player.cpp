#include "Player.h"

Player::Player()
{
    available = 1;
}

void Player::configure(char *filename_)
{
    filename = filename_;
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
    wavPlayer.play(filename);
    delay(10);
}

void Player::stop()
{
    wavPlayer.stop();
}

int Player::isPlaying()
{
    return wavPlayer.isPlaying();
}