#include "Pins.h"
#include "TabMgmt.h"

TabMgmt::TabMgmt()
{
    /* Define tabs here */

    // Tab 1
    const unsigned int *samples1[NUMBER_OF_SOUND_BUTTONS] = {
        AudioSampleKick,
        AudioSampleKick,
        AudioSampleKick,
    };
    tabs[0] = Tab(soundPins, samples1);

    // Tab 2
    const unsigned int *samples2[NUMBER_OF_SOUND_BUTTONS] = {
        AudioSampleGong,
        AudioSampleGong,
        AudioSampleGong,
    };
    tabs[1] = Tab(soundPins, samples2);
}

TabMgmt::~TabMgmt()
{
    free(tabs);
}

void TabMgmt::nextTab()
{
    if (currentTabIndex < NUMBER_OF_TABS - 1)
    {
        // deactivate previous tab and activate new one
        tabs[currentTabIndex].deactivate();
        currentTabIndex++;
        tabs[currentTabIndex].activate();
    }
}

void TabMgmt::previousTab()
{
    if (currentTabIndex > 0)
    {
        // deactivate previous tab and activate new one
        tabs[currentTabIndex].deactivate();
        currentTabIndex--;
        tabs[currentTabIndex].activate();
    }
}

void TabMgmt::update()
{
    for (int i = 0; i < NUMBER_OF_TABS; i++)
    {
        tabs[i].update();
    }
}

int TabMgmt::getTabNumber()
{
    return currentTabIndex + 1;
}