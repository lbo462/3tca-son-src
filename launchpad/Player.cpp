#include "Player.h"

void Player::configure(char *filename_)
{
    filename = filename_;
    available = 1;
}

void Player::release()
{
    if (isPlaying())
        stop();
    available = 0;
}

int Player::isAvailable()
{
    return 1; // TODO should return available and definitly not 1
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