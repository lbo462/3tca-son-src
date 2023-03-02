# 3TCA Projet SON : Launchpad

Léo BONNAIRE, Léonard PRINCE, Gausse DONGMO

<hr>

## Files disposition

`doc` folder containing archive files used during the creation process.

`launchpad` containing every project files.

`src/LaunchPadLib` is the developed library for this specific project, containing every usefull class.

`include_samples.py` and `line_prepending.py` are simple python scripts used for developement.

<hr>

## Configuration

### Pins

Most pins are defined in `Pins.h`.

Pins for the audio output are defined in `TabMgmt.h:soundPins`.

### Samples

Samples are sets of hex values converted from WAV files (via [wav2sketch](https://github.com/PaulStoffregen/Audio/tree/master/extras/wav2sketch)). Samples are stored inside `Samples`.

Samples sets are defined in `Samples.h`. Their association with tabs are defined in `TabMgmt.cpp:configure`.

<hr>