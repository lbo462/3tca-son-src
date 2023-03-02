#include "TabMgmt.h"

TabMgmt::TabMgmt()
{
    /* Function constructor is moved to the method configure()
        This is not for no reason, please, leave it that way
        It should be called during setup
     */
}

TabMgmt::~TabMgmt()
{
    free(tabs);
}

void TabMgmt::configure()
{
    /* Define tabs here */

    // Tab 1
    tabs[0] = new Tab(soundPins, "Kicks1", kicks);

    // Tab 2
    tabs[1] = new Tab(soundPins, "Kicks2", kicks);

    // Tab 3
    tabs[2] = new Tab(soundPins, "Kicks3", kicks);

    // activate first tab
    currentTabIndex = 0;
    tabs[currentTabIndex]->activate();
}

void TabMgmt::nextTab()
{
    if (currentTabIndex < NUMBER_OF_TABS - 1)
    {
        // deactivate previous tab and activate new one
        tabs[currentTabIndex]->deactivate();
        currentTabIndex++;
        tabs[currentTabIndex]->activate();
    }
    else
    {
        tabs[currentTabIndex]->deactivate();
        currentTabIndex = 0;
        tabs[currentTabIndex]->activate();
    }
}

void TabMgmt::previousTab()
{
    if (currentTabIndex > 0)
    {
        // deactivate previous tab and activate new one
        tabs[currentTabIndex]->deactivate();
        currentTabIndex--;
        tabs[currentTabIndex]->activate();
    }
    else
    {
        tabs[currentTabIndex]->deactivate();
        currentTabIndex = NUMBER_OF_TABS - 1;
        tabs[currentTabIndex]->activate();
    }
}

void TabMgmt::update()
{
    // Swap tab
    if (digitalRead(NEXT_TAB_PIN) && (!swapPrevState || millis() - lastSwap > SWAP_DELAY))
    {
        nextTab();
        lastSwap = millis();
    }

    if (digitalRead(PREV_TAB_PIN) && (!swapPrevState || millis() - lastSwap > SWAP_DELAY))
    {
        previousTab();
        lastSwap = millis();
    }
    swapPrevState = digitalRead(NEXT_TAB_PIN) || digitalRead(PREV_TAB_PIN);

    // Update every tabs
    for (int i = 0; i < NUMBER_OF_TABS; i++)
        tabs[i]->update();
}

int TabMgmt::getTabNumber()
{
    return currentTabIndex + 1;
}

char *TabMgmt::getTabName()
{
    return tabs[currentTabIndex]->name;
}