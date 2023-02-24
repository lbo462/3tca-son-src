#include "TabMgmt.h"

TabMgmt::TabMgmt()
{
    // declare useful var
    byte pins[NUMBER_OF_SOUND_BUTTONS] = {33, 34, 35};
    char *filenames[NUMBER_OF_SOUND_BUTTONS] = {
        "PUNCH.WAV",
        "PUNCH.WAV",
        "PUNCH.WAV",
    };

    // Tab 1
    tabs[0].configureSounds(pins, filenames);

    // Tab 2
    tabs[1].configureSounds(pins, filenames);
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