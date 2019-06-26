/* ------------------------------
 * constants.h
 * William Elfversson, wiel1300
 * 2018-01-06
 * ------------------------------*/

#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <iostream>
#include <string>
#include <vector>

    // struct that holds Person object
    struct Persons
    {
        std::string firstName;
        std::string lastName;
        std::string sign;
        float length = 0.0; // initialize for safety

        bool operator==(const Persons &rhs) const{         //bool operator used to in find function
            return(this->firstName == rhs.firstName &&     //to determine if person already is in list.
            this-> lastName == rhs.lastName &&
            this-> length == rhs.length);
        }

        //get methods used to provide sort data
        std::string getSign() { return sign; }
        std::string getFirstName() { return firstName + " " + lastName; }
        std::string getLastName() { return lastName + " " + firstName; }
        float getLength() { return length;}
    };

    constexpr int PAGE_SIZE = 20; //size of list printed at once.
    constexpr char DELIM = '_'; //used as spacer in read/write to files, see fileManager header.

    // vector holding main menu options
    const std::vector<std::string> mainMenuOptions{
            "1. Add person to list",
            "2. Print list",
            "3. Sort list",
            "4. Search list",
            "5. Remove entry",
            "6. Load",
            "7. Save",
            "8. Quit"
    };

    // vector holding sort menu options
    const std::vector<std::string> sortMenuOptions{
            "1. Sort by last name <",
            "2. Sort by signature <",
            "3. Sort by length >",
            "4. Random order"
    };

    // enum helping with identifying options
    enum MainMenuOptions{
        Add = 1,
        Print,
        Sort,
        Search,
        Remove,
        Load,
        Save,
        Quit
    };
    
    enum SortMenuOption{
        Lastname = 1,
        Signature,
        Length,
        RandomList
    };

#endif