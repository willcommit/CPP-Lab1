/* ------------------------------
 * Laboration 4, Assignment_3.cpp
 * Main Menu
 * William Elfversson, wiel1300
 * 2018-12-18
 * ------------------------------*/

//LIBRARIES
#include <iostream>

#include "RingPlingLib.h" // RingPling application library
#include "ThrowDiceLib.h" // ThrowDice application library

// MAIN PROGRAM
int main() {

    int userChoice = 0;
    char userReply = ' ';
    bool quit = false;

    do
    {
        // Print main menu
        std::cout << "=======[ MAIN MENU ]=======\n"
                  << "1. Play Throw Dice \n"
                  << "2. Start RingPling \n"
                  << "3. Quit \n" << std::endl;
        std::cout << "Please enter your choice: ";
        std::cin >> userChoice;
        std::cin.get();

        // Handle user choice
        switch (userChoice)
        {
            case 1:
                throwDice(); // start throwDice game
                break;

            case 2:
                ringPling(); // start ringPling application
                break;

            case 3:
                // Exit prompt
                std::cout << "Are you sure? [Y/N]" << std::endl;
                std::cin >> userReply;
                if (userReply == 'y' || userReply == 'Y')
                    quit = true;
                break;

            default:
                break;
        } 
    }
    while(!quit);

    return 0; 
}

