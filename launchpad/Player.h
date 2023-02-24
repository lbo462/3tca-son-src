#ifndef player_teensy_h_
#define player_teensy_h_

#include <Audio.h>

class Player
{
public:
    Player();

    AudioPlayMemory memPlayer;

    void configure(int *samples_); // configure and take possesion of player
    void release();                  // release player for someone else

    int isAvailable();
    int isPlaying();

    void play();
    void stop();

private:
    /* WARNING : samples are tables of integers in a cpp file */
    int available;
    int *samples;
};

#endif