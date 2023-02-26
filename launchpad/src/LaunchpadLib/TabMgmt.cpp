#include "TabMgmt.h"

TabMgmt::TabMgmt()
{
    /* Define tabs here */

    // Tab 1
    tabs[0] = Tab(soundPins, generators);

    // Tab 2
    tabs[1] = Tab(soundPins, soundeffects);
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