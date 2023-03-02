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
    tabs[0] = new Tab(soundPins, "Kicks", kicks);

    // Tab 2
    tabs[1] = new Tab(soundPins, "Piano", piano);

    // Tab 3
    tabs[2] = new Tab(soundPins, "Guitare", guitar);

    // Tab 4
    tabs[3] = new Tab(soundPins, "Bass1", b1);

    // Tab 5
    tabs[4] = new Tab(soundPins, "Bass2", b2);

    // Tab 6
    tabs[5] = new Tab(soundPins, "Batterie", drums);

    // Tab 7
    tabs[6] = new Tab(soundPins, "Cuivres", brass);

    // Tab 8
    tabs[7] = new Tab(soundPins, "Beep", beep);

    // Tab 9
    tabs[8] = new Tab(soundPins, "Balec", unclassified);

    // Tab 10
    tabs[9] = new Tab(soundPins, "Backgrounds", backgrounds);

    // Tab 11
    tabs[10] = new Tab(soundPins, "Fun", fun);

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