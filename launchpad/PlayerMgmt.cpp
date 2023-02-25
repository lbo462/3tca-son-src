#include "PlayerMgmt.h"

// create players
Player players[NUMBER_OF_PLAYERS];

// Mixers to mix differents audio sources
AudioMixer4 mixer1, mixer2, mixer3, mixer4, mixer5, mixer6, mixer7, mixer8, mixer9, mixer10, mixer11;

// Create output
AudioOutputI2S out;

// Connect WAV players to mixers and mixers together
AudioConnection patchCord1(players[0].memPlayer, 0, mixer8, 0);
AudioConnection patchCord2(players[1].memPlayer, 0, mixer7, 0);
AudioConnection patchCord3(players[2].memPlayer, 0, mixer8, 1);
AudioConnection patchCord4(players[3].memPlayer, 0, mixer8, 3);
AudioConnection patchCord5(players[4].memPlayer, 0, mixer7, 1);
AudioConnection patchCord6(players[5].memPlayer, 0, mixer6, 0);
AudioConnection patchCord7(players[6].memPlayer, 0, mixer7, 3);
AudioConnection patchCord8(players[7].memPlayer, 0, mixer5, 0);
AudioConnection patchCord9(players[8].memPlayer, 0, mixer8, 2);
AudioConnection patchCord10(players[9].memPlayer, 0, mixer7, 2);
AudioConnection patchCord11(players[10].memPlayer, 0, mixer4, 0);
AudioConnection patchCord12(players[11].memPlayer, 0, mixer6, 1);
AudioConnection patchCord13(players[12].memPlayer, 0, mixer3, 0);
AudioConnection patchCord14(players[13].memPlayer, 0, mixer6, 3);
AudioConnection patchCord15(players[14].memPlayer, 0, mixer5, 1);
AudioConnection patchCord16(players[15].memPlayer, 0, mixer5, 3);
AudioConnection patchCord17(players[16].memPlayer, 0, mixer4, 1);
AudioConnection patchCord18(players[17].memPlayer, 0, mixer6, 2);
AudioConnection patchCord19(players[18].memPlayer, 0, mixer4, 3);
AudioConnection patchCord20(players[19].memPlayer, 0, mixer3, 1);
AudioConnection patchCord21(players[20].memPlayer, 0, mixer5, 2);
AudioConnection patchCord22(players[21].memPlayer, 0, mixer2, 0);
AudioConnection patchCord23(players[22].memPlayer, 0, mixer3, 3);
AudioConnection patchCord24(players[23].memPlayer, 0, mixer1, 0);
AudioConnection patchCord25(players[24].memPlayer, 0, mixer4, 2);
AudioConnection patchCord26(players[25].memPlayer, 0, mixer3, 2);
AudioConnection patchCord27(players[26].memPlayer, 0, mixer2, 1);
AudioConnection patchCord28(players[27].memPlayer, 0, mixer2, 3);
AudioConnection patchCord29(players[28].memPlayer, 0, mixer1, 1);
AudioConnection patchCord30(players[29].memPlayer, 0, mixer1, 3);
AudioConnection patchCord31(players[30].memPlayer, 0, mixer2, 2);
AudioConnection patchCord32(players[31].memPlayer, 0, mixer1, 2);

// second layer of connection between mixers
AudioConnection patchCord33(mixer8, 0, mixer10, 3);
AudioConnection patchCord34(mixer6, 0, mixer10, 1);
AudioConnection patchCord35(mixer4, 0, mixer9, 3);
AudioConnection patchCord36(mixer2, 0, mixer9, 1);
AudioConnection patchCord37(mixer7, 0, mixer10, 2);
AudioConnection patchCord38(mixer5, 0, mixer10, 0);
AudioConnection patchCord39(mixer3, 0, mixer9, 2);
AudioConnection patchCord40(mixer1, 0, mixer9, 0);
AudioConnection patchCord41(mixer9, 0, mixer11, 0);
AudioConnection patchCord42(mixer10, 0, mixer11, 1);

// Connect last mixer to output
AudioConnection patchCord43(mixer11, 0, out, 0);
AudioConnection patchCord44(mixer11, 0, out, 1);

void setupGain()
{
    // set gain to 1 on every mixer outputs
    for (int i = 0; i < 4; i++)
    {
        mixer1.gain(i, 1);
        mixer2.gain(i, 1);
        mixer3.gain(i, 1);
        mixer4.gain(i, 1);
        mixer5.gain(i, 1);
        mixer6.gain(i, 1);
        mixer7.gain(i, 1);
        mixer8.gain(i, 1);
        mixer9.gain(i, 1);
        mixer10.gain(i, 1);
    }

    // maybe will change
    mixer11.gain(0, 1);
    mixer11.gain(1, 1);
}

// define PlayerMgmt methods
PlayerMgmt::PlayerMgmt(Player *players)
{
    p = players;
}

int PlayerMgmt::getPlayer()
{
    for (int i = 0; i < NUMBER_OF_PLAYERS; i++)
    {
        if (p[i].isAvailable())
            return i;
    }
    return -1;
}

// PlayerMgmt object
PlayerMgmt playerMgmt(players); // pass the linked players