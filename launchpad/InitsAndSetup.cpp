#include "InitsAndSetup.h"

//output, shield and buttons
AudioControlSGTL5000 audioShield;
AudioOutputI2S out;
Button buttons[NUMBER_OF_BUTTONS];

// Mixers to mix differents audio sources
AudioMixer4              mixer1, mixer2, mixer3, mixer4, mixer5, mixer6, mixer7, mixer8, mixer9, mixer10;

// Connect WAV players to mixers and mixers together
AudioConnection          patchCord1(buttons[0].player, 0, mixer4, 2);
AudioConnection          patchCord2(buttons[0].player, 1, mixer8, 2);
AudioConnection          patchCord3(buttons[1].player, 0, mixer4, 3);
AudioConnection          patchCord4(buttons[1].player, 1, mixer8, 3);
AudioConnection          patchCord5(buttons[2].player, 0, mixer4, 1);
AudioConnection          patchCord6(buttons[2].player, 1, mixer8, 1);
AudioConnection          patchCord7(buttons[3].player, 0, mixer3, 2);
AudioConnection          patchCord8(buttons[3].player, 1, mixer7, 2);
AudioConnection          patchCord9(buttons[4].player, 0, mixer4, 0);
AudioConnection          patchCord10(buttons[4].player, 1, mixer8, 0);
AudioConnection          patchCord11(buttons[5].player, 0, mixer2, 3);
AudioConnection          patchCord12(buttons[5].player, 1, mixer6, 3);
AudioConnection          patchCord13(buttons[6].player, 0, mixer1, 1);
AudioConnection          patchCord14(buttons[6].player, 1, mixer5, 1);
AudioConnection          patchCord15(buttons[7].player, 0, mixer3, 3);
AudioConnection          patchCord16(buttons[7].player, 1, mixer7, 3);
AudioConnection          patchCord17(buttons[8].player, 0, mixer3, 0);
AudioConnection          patchCord18(buttons[8].player, 1, mixer7, 0);
AudioConnection          patchCord19(buttons[9].player, 0, mixer2, 0);
AudioConnection          patchCord20(buttons[9].player, 1, mixer6, 0);
AudioConnection          patchCord21(buttons[10].player, 0, mixer2, 2);
AudioConnection          patchCord22(buttons[10].player, 1, mixer6, 2);
AudioConnection          patchCord23(buttons[11].player, 0, mixer3, 1);
AudioConnection          patchCord24(buttons[11].player, 1, mixer7, 1);
AudioConnection          patchCord25(buttons[12].player, 0, mixer1, 3);
AudioConnection          patchCord26(buttons[12].player, 1, mixer5, 3);
AudioConnection          patchCord27(buttons[13].player, 0, mixer2, 1);
AudioConnection          patchCord28(buttons[13].player, 1, mixer6, 1);
AudioConnection          patchCord29(buttons[14].player, 0, mixer1, 2);
AudioConnection          patchCord30(buttons[14].player, 1, mixer5, 2);
AudioConnection          patchCord31(buttons[15].player, 0, mixer1, 0);
AudioConnection          patchCord32(buttons[15].player, 1, mixer5, 0);
AudioConnection          patchCord33(mixer2, 0, mixer9, 1);
AudioConnection          patchCord34(mixer3, 0, mixer9, 2);
AudioConnection          patchCord35(mixer1, 0, mixer9, 0);
AudioConnection          patchCord36(mixer4, 0, mixer9, 3);
AudioConnection          patchCord37(mixer5, 0, mixer10, 0);
AudioConnection          patchCord38(mixer6, 0, mixer10, 1);
AudioConnection          patchCord39(mixer7, 0, mixer10, 2);
AudioConnection          patchCord40(mixer8, 0, mixer10, 3);

// Connect mixers to output
AudioConnection          patchCord41(mixer9, 0, out, 0);
AudioConnection          patchCord42(mixer10, 0, out, 1);

//used to set up the gain of mixers
void setUpMixers(){
    float gain = 1.0 / NUMBER_OF_BUTTONS;
    for (int i = 0; i < 4; i++) {
        mixer1.gain(i, gain);
        mixer2.gain(i, gain);
        mixer3.gain(i, gain);
        mixer4.gain(i, gain);
        mixer5.gain(i, gain);
        mixer6.gain(i, gain);
        mixer7.gain(i, gain);
        mixer8.gain(i, gain);
    }

    gain = 1.0 / 4;
    for (int i = 0; i < 4; i++) {
        mixer9.gain(i, gain);
        mixer10.gain(i, gain);
    }
}

//used to init audioshield
void setUpShield(){
    audioShield.enable();
    audioShield.volume(1);
}
