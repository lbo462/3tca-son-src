#include <Audio.h>
#include "MyDsp.h"

MyDsp myDsp;
AudioOutputI2S out;
AudioControlSGTL5000 audioShield;
AudioConnection patchCord0(myDsp,0,out,0);
AudioConnection patchCord1(myDsp,0,out,1);

void setup() {
  Serial.begin(9600);
  AudioMemory(2);
  audioShield.enable();
  audioShield.volume(0.5);
}

void loop() {
  int value = analogRead(A0);
  
  Serial.print(value);
  displayBiquadCoeff();

  myDsp.resonlp(value, 3, 1);
  
  delay(100);
}

void displayBiquadCoeff() {
  Serial.print(" a1 : ");
  Serial.print(myDsp.biquadFilter.a1);
  Serial.print(" a2 : ");
  Serial.print(myDsp.biquadFilter.a2);
  Serial.print(" b0 : ");
  Serial.print(myDsp.biquadFilter.b0);
  Serial.print(" b1 : ");
  Serial.print(myDsp.biquadFilter.b1);
  Serial.print(" b2 : ");
  Serial.println(myDsp.biquadFilter.b2);
}
