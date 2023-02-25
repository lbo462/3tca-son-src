#ifndef tabmgmt_teensy_h_
#define tabmgmt_teensy_h_

#include "Tab.h"

// include samples
#include "AudioSampleKick.h"
#include "AudioSampleGong.h"

#define NUMBER_OF_TABS 2

class TabMgmt
{
public:
    TabMgmt();
    ~TabMgmt();

    void nextTab();     // move between tabs
    void previousTab(); //

    void update(); // update every tabs

    int getTabNumber(); // return current index tab + 1

    // TODO make priv
    Tab *tabs = (Tab *)malloc(sizeof(Tab) * NUMBER_OF_TABS);

private:
    int currentTabIndex;

    const byte soundPins[NUMBER_OF_SOUND_BUTTONS] = {
        33,
        34,
        35,
    };
};

#endif