/* ------------------------------
 * persons.cpp
 * Function definitions to persons.h
 * William Elfversson, wiel1300
 * 2018-01-06
 * ------------------------------*/

#include "persons.h"

void askForData (Persons &person)
{
    std::cout << "\nPlease input your personal data (we will store it safely..)!" << std::endl;
    
    std::cout << "FIRST NAME: ";
    std::getline(std::cin, person.firstName);

    std::cout << "LAST NAME: ";
    std::getline(std::cin,person.lastName);
    
    std::cout << "LENGTH: ";
    std::cin >> person.length;
    std::cin.get();
}

void addSignature (Persons &person)
{
    std::string substring1 = toLower(person.firstName.substr(0,3));
    std::string substring2 = toLower(person.lastName.substr(0,3));

    person.sign =insertX(substring1 + substring2);
}

std::string toLower (std::string input)
{
    std::string output;

    for (char i : input) {
        if (i < 97)
            output += i +32;
        else
            output += i;
    }

    return output;
}

std::string insertX (std::string input)
{
    std::string output;

    for (char i : input) {
        if (i == '@')
            output += 'x';
        else
            output += i;
    }

    return output;
}

bool checkPerson(Persons &person, std::vector<Persons> &personList)
{
    auto locate = std::find(personList.begin(), personList.end(), person);

    if (locate != personList.end())
        return true;
    else
        return false;
}

void addPerson (Persons &person, std::vector<Persons> &personList)
{
    personList.push_back(person);
}

void printPersonList (std::vector<Persons> &personList)
{
    int counter = 0;

    std::cout << std::endl << "Nr  Sign       Name               Length [m]" << std::endl;

    for(auto i=0; i<personList.size(); i++){

        if (counter == PAGE_SIZE){
            counter = 0;
            std::cout << "\nPress \"ENTER\" to print 20 posts more\n";
            std::cin.ignore();
        }

        std::cout << std::fixed << std::setprecision(2)
                  << std::setfill(' ');

        std::cout << std::left << std::setw(4) << std::to_string(i+1) + "."
                  << std::setw(11) << personList[i].sign;

        std::cout << std::left << std::setw(20) << personList[i].getFirstName();

        std::cout << std::right << std::setw(5) << personList[i].length << std::endl;

        counter++;
    }
    std::cout << std::endl;
}

void printPersonList (Persons person)
{

    std::cout << std::endl << "Sign       Name               Length [m]" << std::endl;

    std::cout << std::fixed << std::setprecision(2)
              << std::setfill(' ');

    std::cout << std::left << std::setw(11) << person.sign;

    std::cout << std::left << std::setw(20) << person.getFirstName();

    std::cout << std::right << std::setw(5) << person.length << std::endl;

    std::cout << std::endl;
}

//=========== SORTING FUNCTIONS ==============

void sortPerson_Sign (std::vector<Persons> &personList)
{
    std::sort(personList.begin(), personList.end(),
              [](Persons p1, Persons p2) { return p1.getSign() < p2.getSign(); });
}

void sortPerson_Name (std::vector<Persons> &personList)
{
    std::sort(personList.begin(), personList.end(),
              [](Persons p1, Persons p2) { return p1.getFirstName() < p2.getFirstName(); });
    std::stable_sort(personList.begin(), personList.end(),
              [](Persons p1, Persons p2) { return p1.getLastName() < p2.getLastName(); });
}

void sortPerson_Length (std::vector<Persons> &personList)
{
    std::sort(personList.begin(), personList.end(),
              [](Persons p1, Persons p2) { return p1.getLength() > p2.getLength(); }); // Note ">", descending order
}

void randomShuffle (std::vector<Persons> &personList)
{
    std::random_shuffle(personList.begin(), personList.end());
}

bool checkSorted (std::vector<Persons> &personList)
{
	return std::is_sorted(personList.begin(), personList.end(),
              [](Persons p1, Persons p2) { return p1.getSign() < p2.getSign(); });
}

//Used binary search to show that I can handle it better than in last assignment :)
int searchPerson(std::string signature, std::vector<Persons> personList)
{
    int first = 0;
    int last = personList.size() - 1;

    while (first <= last){

        int mid = (first + last) / 2;
        if (signature > personList[mid].sign)
            first = mid + 1;
        else if (signature < personList[mid].sign)
            last = mid - 1;
        else
            return mid;
    }
    return -1;
}

void removePerson (int index, std::vector<Persons> &personList)
{
    if (questionPrompt("Are you sure?")){}
        personList.erase(begin(personList) + index);
}

void clearList (std::vector<Persons> &personList)
{
    if (questionPrompt("Current list will be removed! Are you sure?"))
        personList.clear();
}
