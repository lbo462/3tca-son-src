#ifndef tabmgmt_teensy_h_
#define tabmgmt_teensy_h_

#include "Tab.h"

#define NUMBER_OF_TABS 2

class TabMgmt
{
public:
    TabMgmt();

    void nextTab();     // move between tabs
    void previousTab(); //

    void update(); // update every tabs

    int getTabNumber(); // return current index tab + 1

    // TODO make priv
    Tab tabs[NUMBER_OF_TABS];

private:
    int currentTabIndex;
};

#endif