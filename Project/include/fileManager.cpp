/* ------------------------------
 * fileManager.cpp
 * Function definitions to fileManager.h
 * William Elfversson, wiel1300
 * 2018-01-06
 * ------------------------------*/

#include "fileManager.h"

void fileWrite (std::vector<Persons> &personList)
{
    std::string filename;
    std::cout << "Please enter a filename to save to: ";
    std::getline(std::cin,filename);

    std::ofstream outFile{filename, std::ios::trunc};

    if(!outFile){
        std::cerr <<"ERROR creating file!" << std::endl;
    }
    for(auto element:personList){
        outFile << element.firstName << DELIM << element.lastName
                << DELIM << element.sign << DELIM << element.length << std::endl;
    }

    outFile.close();
}

void fileRead (std::vector<Persons> &personList)
{
    std::string filename;
    std::cout << "Please enter a filename to load: ";
    std::getline(std::cin,filename);

    std::ifstream inFile;
    std::string line;
    std::vector<std::string> tmpVector;
    std::string holdFloat;

    inFile.open(filename);

    if(inFile.is_open()){

        while(std::getline(inFile, line)){
            std::istringstream iss(line);
            Persons newPerson;
            std::getline(iss,newPerson.firstName,DELIM);
            std::getline(iss,newPerson.lastName,DELIM);
            std::getline(iss,newPerson.sign,DELIM);
            std::getline(iss,holdFloat);
            newPerson.length = std::stod (holdFloat);
            personList.push_back(newPerson);
        }
        std::cout << "File loaded sucessfully" << std::endl;
        inFile.close();
    }
    else
        std::cerr <<"ERROR opening file!" << std::endl;
}
