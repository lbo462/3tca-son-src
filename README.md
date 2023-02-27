# 3TCA Projet SON : Launchpad

Léo BONNAIRE, Léonard PRINCE, Gausse DONGMO

<hr>

## How to

1/ Build below electrical circuit

2/ Compile and upload `launchpad.ino` to a Teensy 4.1.

<hr>

## Configuration

### Pins

Most pins are defined in `Pins.h`.

Pins for the audio output are defined in `TabMgmt.h:soundPins`.

### Samples

Samples are sets of hex values converted from WAV files. Samples are stored inside `Samples`.

Samples sets are defined in `Samples.h`. Their association with tabs are defined in `TabMgmt.cpp:configure`.

<hr>

## Electrical circuit

Current circuit is three buttons linked to digital pins 33, 34 and 35.

Register button is plugged to pin 32.

Next and previous tab are plugged to pins 29 and 30.

// TODO ADD NICE PICTURES