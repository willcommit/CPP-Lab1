/* ------------------------------
 * RingPlingLib.h
 * Function declarations library
 * William Elfversson, wiel1300
 * 2018-12-18
 * ------------------------------*/

#ifndef RingPlingH
#define RingPlingH

    #include <iostream>
    #include <string>
    #include <sstream>

    int convertHHtoMM(int hours);
    void extractTime (std::string input, int &hours, int &minutes);
    bool testInput(int hh, int mm);
    double calcPrice (int hhStart, int mmStart, int hhStop, int mmStop);
    void wrongInputPrompt();
    void exitPrompt(bool &exit);
    void ringPling();

#endif