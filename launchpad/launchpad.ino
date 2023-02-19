#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// SD Card reading
#define SDCARD_CS_PIN    10
#define SDCARD_MOSI_PIN  11  // not actually used
#define SDCARD_SCK_PIN   13  // not actually used

AudioControlSGTL5000     audioShield;
AudioPlaySdWav           playWavMusic, playWavMessage;
AudioMixer4              mixer1,mixer2;
AudioOutputI2S           out;
AudioConnection          patchCord1(playWavMusic, 0, mixer1, 0);
AudioConnection          patchCord2(playWavMusic, 1, mixer2, 0);
AudioConnection          patchCord3(playWavMessage, 0, mixer1, 1);
AudioConnection          patchCord4(playWavMessage, 1, mixer2, 1);
AudioConnection          patchCord5(mixer1, 0, out, 0);
AudioConnection          patchCord6(mixer2, 0, out, 1);

void setup() {
  Serial.begin(9600);
  
  // Audio settings
  AudioMemory(10);
  audioShield.enable();
  audioShield.volume(0.5);

  // SD card reading
  SPI.setMOSI(SDCARD_MOSI_PIN);
  SPI.setSCK(SDCARD_SCK_PIN);
  if (!(SD.begin(SDCARD_CS_PIN))) {
    // stop here, but print a message repetitively
    while (1) {
      Serial.println("Unable to access the SD card");
      delay(500);
    }
  }

  // PinModes
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);

  delay(1000);
}

void loop() {
  if (playWavMusic.isPlaying() == false) {
    playWavMusic.play("GOT.WAV");
    delay(10);
  }

  int buttonPressed = digitalRead(0);
  
  if (buttonPressed == HIGH) {
    playWavMessage.play("MESSAGE.WAV");
    delay(10);
  }
}
