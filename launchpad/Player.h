#ifndef player_teensy_h_
#define player_teensy_h_

#include <Audio.h>

class Player
{
public:
    AudioPlaySdWav wavPlayer;

    void configure(char *filename_); // configure and take possesion of player
    void release();                  // release player for someone else

    int isAvailable();
    int isPlaying();

    void play();
    void stop();

private:
    /* WARNING : files should be WAV files with a 16 Bit resolution and a 44100 Hz audio frequency */
    char *filename;
    int available;
};

#endif