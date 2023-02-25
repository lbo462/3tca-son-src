#ifndef player_teensy_h_
#define player_teensy_h_

#include <Audio.h>

class Player
{
public:
    Player();

    AudioPlayMemory memPlayer;

    void configure(const unsigned int *sample_, unsigned int period_); // reset, configure and take possesion of player
    void release();                                                    // release player for someone else

    int isAvailable();
    int isPlaying(); // returns wheter the sound is playing or not
    void update();   // compute whether the sound is over, taking period into account
    /* SHOULD BE CALLED AT EACH FRAME FOR NON-AVAILABLE PLAYERS ! */
    // calm down, buttons take care of it

    void play();
    void stop();

private:
    int available;
    int playing; // boolean telling if sound is playing after applying below delay
    unsigned int *sample;
    unsigned int period;          // frequency at which the song is played (in ms)
    unsigned long startedWaiting; // time at which the above delay was triggered
    // if == 0 the timer didn't start
    // it allows doing things like :
    // if (!startedWaiting) { startedWaiting = millis(); } i.e. update() method
};

#endif