/* ------------------------------
 * menuManager.h
 * Function declarations library
 * William Elfversson, wiel1300
 * 2018-01-06
 * ------------------------------*/

#ifndef MENU_MANAGER_H
#define MENU_MANAGER_H

#include <iostream>
#include <string>

#include "constants.h"
#include "persons.h"
#include "fileManager.h"

// Takes menOptions string vector and prints main menu, returns userChoice as int
int showMainMenu (std::vector<std::string> menuOptions);
// takes user choice, person list and program state to control program flow
void programSelector (int userChoice, std::vector<Persons> &personList, bool &programState);
// controls input of person to list
void inputPerson (std::vector<Persons> &personList);
// general question prompt, question can be adjusted according to situation with string parameter
bool questionPrompt (std::string question);
// displays sorting menu
int showSortMenu (std::vector<std::string> menuOptions);
// controls sort selection
void sortSelector (int userChoice, std::vector<Persons> &personList);
// displays search prompt
void searchPrompt (std::vector<Persons> personList);
// displays remove search prompt
void removeSearchPrompt (std::vector<Persons> &personList);
// removes person from list prompt
void removePrompt(int index, std::vector<Persons> &personList);

#endif