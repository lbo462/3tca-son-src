#ifndef playermgmt_teensy_h_
#define playermgmt_teensy_h_

#include "Player.h"

#define NUMBER_OF_PLAYERS 32 // DO NOT CHANGE WITHOUT PERMISSION

class PlayerMgmt
{
public:
    PlayerMgmt(Player *players);

    Player *p; // array of every available players

    int getPlayer(); // returns the index of an available player. Returns -1 if no player is available
    // even if a player is returned, it's not implied that the player will be used
    // The one who configure the button will take the player as used and block it
};

void setupGain();
extern PlayerMgmt playerMgmt;

#endif