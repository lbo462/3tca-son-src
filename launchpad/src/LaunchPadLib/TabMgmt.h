#ifndef tabmgmt_teensy_h_
#define tabmgmt_teensy_h_

#include "Tab.h"
#include "Samples.h"

#define NUMBER_OF_TABS 3
<<<<<<< HEAD
#define stringify(var) #var // used to get tabNames
    == == ==
    =
#define SWAP_DELAY 1000
        >>>>>>> 740dbbe (add missing includes)

    class TabMgmt
{
public:
    TabMgmt();
    ~TabMgmt();

    void configure();

    void nextTab();     // move between tabs
    void previousTab(); //

    void update(); // update every tabs

    int getTabNumber(); // return current index tab + 1

    char *getTabName(); // return the name of the current tab

private:
    int currentTabIndex;
    Tab *tabs[NUMBER_OF_TABS];
    char *tabNames[NUMBER_OF_TABS];
    int swapPrevState = 0;      // State of tab swapping button at previous frame
    unsigned long lastSwap = 0; // Time of which a tabs were swapped

    const int soundPins[NUMBER_OF_SOUND_BUTTONS] = {
        28,
        29,
        30,
        31,
        32,
        33,
        34,
        35,
        36,
        37,
        38,
        39,
    };
};

#endif