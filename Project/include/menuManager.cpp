/* ------------------------------
 * menuManager.cpp
 * Function definitions to menuManager.h
 * William Elfversson, wiel1300
 * 2018-01-06
 * ------------------------------*/

#include "menuManager.h"

int showMainMenu (std::vector<std::string> menuOptions)
{
    int userChoice = 0;
    std::cout << "\n====== MAIN MENU \"DATABASE\" 2.0 ======\n" << std::endl;
    for(auto option: menuOptions)
        std::cout << option << std::endl;
    std::cout << "\nYour choice: ";
    std::cin >> userChoice;
    std::cin.get();
    return userChoice;
}

void programSelector (int userChoice, std::vector<Persons> &personList, bool &programState)
{
    switch(userChoice){
        case Add:
            inputPerson(personList);
            break;
        case Print:
            printPersonList(personList);
            break;
        case Sort:
            sortSelector(showSortMenu(sortMenuOptions), personList);
            break;
        case Search:
            if(checkSorted(personList))
                searchPrompt(personList);
            else{
                sortPerson_Sign(personList);
                searchPrompt(personList);
            }
            break;
        case Remove:
            removeSearchPrompt(personList);
            break;
        case Load:
            clearList(personList); //Not needed, but there for extra safety
            fileRead(personList);
            break;
        case Save:
            fileWrite(personList);
            break;
        case Quit:
            programState = !questionPrompt("Do wish to quit?");
            break;
        default:
            std::cout << "ERROR" << std::endl;
            break;
    }
}

void inputPerson (std::vector<Persons> &personList)
{
    std::string question; //unique question for each case: person found or not

    do{
        Persons newPerson;
        askForData(newPerson);
        addSignature(newPerson);
        if (!checkPerson(newPerson, personList)){
            addPerson(newPerson, personList);
            question = "Do you wish to add more?";
        }
        else{
            std::cout << "Already such an person in list!" << std::endl;
            question = "Do you want to try another input?";
        }
    }
    while(questionPrompt(question));
}

bool questionPrompt (std::string question)
{
    char reply;
    std::cout << question << " [Y/N] ";
    std::cin >> reply;
    std::cin.get();

    return !(reply == 'n' || reply == 'N');
}

int showSortMenu (std::vector<std::string> menuOptions)
{
    int userChoice = 0;
    std::cout << "\n====== SORT OPTIONS ======\n" << std::endl;
    for(auto option: menuOptions)
        std::cout << option << std::endl;
    std::cout << "\nYour choice: ";
    std::cin >> userChoice;
    std::cin.get();
    return userChoice;
}

void sortSelector (int userChoice, std::vector<Persons> &personList)
{
    switch(userChoice){
        case Lastname:
            sortPerson_Name(personList);
            std::cout << "Sorted by last name, ascending order!" << std::endl;
            break;
        case Signature:
            sortPerson_Sign(personList);
            std::cout << "Sorted by Signature, ascending order!" << std::endl;
            break;
        case Length:
            sortPerson_Length(personList);
            std::cout << "Sorted by Length, descending order!" << std::endl;
            break;
        case RandomList:
            randomShuffle(personList);
            std::cout << "List randomly shuffled!" << std::endl;
            break;
        default:
            std::cout << "ERROR" << std::endl;
            break;
    }
}

void searchPrompt (std::vector<Persons> personList)
{
    std::string signature;
    std::cout << "\nPlease enter signature to search for: ";
    std::cin >> signature;
    int result = searchPerson(signature,personList);
    if(result >= 0){
        std::cout << "Person found! Result: " << std::endl;
        printPersonList(personList[result]);
    }
    else if (result == -1)
        std::cout << "No such person in list!" << std::endl;
    else
        std::cout << "OPS!" << std::endl;
}

void removeSearchPrompt(std::vector<Persons> &personList) {
    std::string signature;
    std::cout << "\nPlease enter signature to search for: ";
    std::cin >> signature;
    int result = searchPerson(signature,personList);
    if(result >= 0){
        std::cout << "Person found! Result: " << std::endl;
        printPersonList(personList[result]);
    }
    else if (result == -1)
        std::cout << "No such person in list!" << std::endl;
    else
        std::cout << "OPS!" << std::endl;
    removePrompt(result,personList);
}


void removePrompt(int index, std::vector<Persons> &personList)
{
    char reply;
    std::cout << "\nDo you wish to remove this entry? [Y/N] ";
    std::cin >> reply;
    std::cin.get();

    if(reply=='y' || reply=='Y') {
        removePerson(index, personList);
        std::cout << "Entry removed!" << std::endl;
    }
    else
        std::cout << "NO entry removed!" << std::endl;
}


