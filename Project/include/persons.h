/* ------------------------------
 * persons.h
 * Function declarations library
 * William Elfversson, wiel1300
 * 2018-01-06
 * ------------------------------*/

#ifndef PERSONS_H
#define PERSONS_H

#include <iostream>
#include <string>
#include <vector> 
#include <iomanip>
#include <locale>
#include <algorithm>

#include "constants.h"
#include "menuManager.h"

//Ask user for data and create a person object
void askForData (Persons &person);
//Creates signature from person name
void addSignature (Persons &person);
//Brings letters to lower case
std::string toLower (std::string input);
//Inserts X into signature
std::string insertX (std::string input);
//Checks if person already exist in list
bool checkPerson(Persons &person, std::vector<Persons> &personList);
//Adds person to list
void addPerson (Persons &person, std::vector<Persons> &personList);
//print list of person to console
void printPersonList (std::vector<Persons> &personList);
//overload of printPerson used to print single person to console
void printPersonList (Persons person);

//======SORTING FUNCTIONS=======
//sorting person list by signature
void sortPerson_Sign (std::vector<Persons> &personList);
//sorting person list by name
void sortPerson_Name (std::vector<Persons> &personList);
//sorting person list by length
void sortPerson_Length (std::vector<Persons> &personList);
//shuffle list randomly
void randomShuffle (std::vector<Persons> &personList);
//shuffle list randomly
bool checkSorted (std::vector<Persons> &personList);

//search person by signature
int searchPerson(std::string signature, std::vector<Persons>personList);
//search for person to remove
void removeSearchPrompt (std::vector<Persons> &personList);
//remove person by index
void removePerson (int index, std::vector<Persons> &personList);

//clear/delete person list
void clearList (std::vector<Persons> &personList);

#endif