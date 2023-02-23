#include "PlayerMgmt.h"

// create players
Player players[NUMBER_OF_PLAYERS];

// Mixers to mix differents audio sources
AudioMixer4 mixer1, mixer2, mixer3, mixer4, mixer5, mixer6, mixer7, mixer8, mixer9, mixer10;

// Create output
AudioOutputI2S out;

// Connect WAV players to mixers and mixers together
AudioConnection patchCord1(players[0].wavPlayer, 0, mixer4, 2);
AudioConnection patchCord2(players[0].wavPlayer, 1, mixer8, 2);
AudioConnection patchCord3(players[1].wavPlayer, 0, mixer4, 3);
AudioConnection patchCord4(players[1].wavPlayer, 1, mixer8, 3);
AudioConnection patchCord5(players[2].wavPlayer, 0, mixer4, 1);
AudioConnection patchCord6(players[2].wavPlayer, 1, mixer8, 1);
AudioConnection patchCord7(players[3].wavPlayer, 0, mixer3, 2);
AudioConnection patchCord8(players[3].wavPlayer, 1, mixer7, 2);
AudioConnection patchCord9(players[4].wavPlayer, 0, mixer4, 0);
AudioConnection patchCord10(players[4].wavPlayer, 1, mixer8, 0);
AudioConnection patchCord11(players[5].wavPlayer, 0, mixer2, 3);
AudioConnection patchCord12(players[5].wavPlayer, 1, mixer6, 3);
AudioConnection patchCord13(players[6].wavPlayer, 0, mixer1, 1);
AudioConnection patchCord14(players[6].wavPlayer, 1, mixer5, 1);
AudioConnection patchCord15(players[7].wavPlayer, 0, mixer3, 3);
AudioConnection patchCord16(players[7].wavPlayer, 1, mixer7, 3);
AudioConnection patchCord17(players[8].wavPlayer, 0, mixer3, 0);
AudioConnection patchCord18(players[8].wavPlayer, 1, mixer7, 0);
AudioConnection patchCord19(players[9].wavPlayer, 0, mixer2, 0);
AudioConnection patchCord20(players[9].wavPlayer, 1, mixer6, 0);
AudioConnection patchCord21(players[10].wavPlayer, 0, mixer2, 2);
AudioConnection patchCord22(players[10].wavPlayer, 1, mixer6, 2);
AudioConnection patchCord23(players[11].wavPlayer, 0, mixer3, 1);
AudioConnection patchCord24(players[11].wavPlayer, 1, mixer7, 1);
AudioConnection patchCord25(players[12].wavPlayer, 0, mixer1, 3);
AudioConnection patchCord26(players[12].wavPlayer, 1, mixer5, 3);
AudioConnection patchCord27(players[13].wavPlayer, 0, mixer2, 1);
AudioConnection patchCord28(players[13].wavPlayer, 1, mixer6, 1);
AudioConnection patchCord29(players[14].wavPlayer, 0, mixer1, 2);
AudioConnection patchCord30(players[14].wavPlayer, 1, mixer5, 2);
AudioConnection patchCord31(players[15].wavPlayer, 0, mixer1, 0);
AudioConnection patchCord32(players[15].wavPlayer, 1, mixer5, 0);

// second layer of connection between mixers
AudioConnection patchCord33(mixer2, 0, mixer9, 1);
AudioConnection patchCord34(mixer3, 0, mixer9, 2);
AudioConnection patchCord35(mixer1, 0, mixer9, 0);
AudioConnection patchCord36(mixer4, 0, mixer9, 3);
AudioConnection patchCord37(mixer5, 0, mixer10, 0);
AudioConnection patchCord38(mixer6, 0, mixer10, 1);
AudioConnection patchCord39(mixer7, 0, mixer10, 2);
AudioConnection patchCord40(mixer8, 0, mixer10, 3);

// Connect mixers to output
AudioConnection patchCord41(mixer9, 0, out, 0);
AudioConnection patchCord42(mixer10, 0, out, 1);

void setupGain()
{
    float gain = 1.0 / NUMBER_OF_PLAYERS;

    // set gain on every mixer outputs
    for (int i = 0; i < 4; i++)
    {
        mixer1.gain(i, gain);
        mixer2.gain(i, gain);
        mixer3.gain(i, gain);
        mixer4.gain(i, gain);
        mixer5.gain(i, gain);
        mixer6.gain(i, gain);
        mixer7.gain(i, gain);
        mixer8.gain(i, gain);
    }

    for (int i = 0; i < 4; i++)
    {
        mixer9.gain(i, 0.25);
        mixer10.gain(i, 0.25);
    }
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