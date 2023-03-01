#ifndef tabmgmt_teensy_h_
#define tabmgmt_teensy_h_

#include "Tab.h"
#include "Samples.h"

#define NUMBER_OF_TABS 3

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

private:
    int currentTabIndex;
    Tab *tabs[NUMBER_OF_TABS];

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