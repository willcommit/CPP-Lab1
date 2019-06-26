/* ------------------------------
 * ThrowDiceLib.h
 * Function declarations library
 * William Elfversson, wiel1300
 * 2018-12-18
 * ------------------------------*/

#ifndef ThrowDiceH
#define ThrowDiceH

    #include <iostream>
    #include <string>
    #include <stdio.h> 
    #include <stdlib.h> 
    #include <time.h>
    #include <iomanip>

    int rollDice(int max, int min);
    void countSides(int diceRoll,
                    float &count1,
                    float &count2,
                    float &count3,
                    float &count4,
                    float &count5,
                    float &count6);

    float calcRelative(float count, float sumCount);
    void quitPrompt(bool &exit);
    void throwDice();

#endif