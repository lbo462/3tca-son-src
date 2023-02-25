#ifndef player_teensy_h_
#define player_teensy_h_

#include <Audio.h>

class Player
{
public:
    Player();

    AudioPlayMemory memPlayer;

    void configure(const unsigned int *sample_); // configure and take possesion of player
    void release();                              // release player for someone else

    int isAvailable();
    int isPlaying();

    void play();
    void stop();

private:
    int available;
    unsigned int *sample;
};

#endif