/* ------------------------------
 * main.cpp
 * Project
 * William Elfversson, wiel1300
 * 2018-01-10
 * ------------------------------*/

#include "../include/constants.h"
#include "../include/persons.h"
#include "../include/menuManager.h"


int main() 
{

    std::vector<Persons> personList;
    bool programState = true;

    do{
        programSelector(showMainMenu(mainMenuOptions), personList, programState);
    }
    while(programState);

    return 0;
}
