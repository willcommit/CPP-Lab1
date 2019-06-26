/* ------------------------------
 * fileManager.h
 * Function declarations library
 * William Elfversson, wiel1300
 * 2018-01-06
 * ------------------------------*/

#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>

#include "constants.h"

// function that takes the person list as a parameter and writes it to a text file
void fileWrite (std::vector<Persons> &personList);
// function that takes the person list as a parameter and reads a text file to it
void fileRead (std::vector<Persons> &personList);

#endif