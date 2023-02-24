#include "TabMgmt.h"

TabMgmt::TabMgmt()
{
    // declare pins
    byte pins[NUMBER_OF_SOUND_BUTTONS] = {33, 34, 35};

    // Tab 1
    char *filenames1[NUMBER_OF_SOUND_BUTTONS] = {
        "PUNCH.WAV",
        "PUNCH.WAV",
        "PUNCH.WAV",
    };
    tabs[0].configureSounds(pins, filenames1);

    // Tab 2
    char *filenames2[NUMBER_OF_SOUND_BUTTONS] = {
        "BASS.WAV",
        "BASS.WAV",
        "BASS.WAV",
    };
    tabs[1].configureSounds(pins, filenames2);
}

void TabMgmt::nextTab()
{
    if (currentTabIndex < NUMBER_OF_TABS - 1)
        currentTabIndex++;
}

void TabMgmt::previousTab()
{
    if (currentTabIndex > 0)
        currentTabIndex--;
}

void TabMgmt::update()
{
    tabs[currentTabIndex].update();
}

int TabMgmt::getTabNumber()
{
    return currentTabIndex + 1;
}