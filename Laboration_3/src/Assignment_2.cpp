/* ------------------------------
 * Laboration 3, Assignment_2.cpp
 * Sort 3 names
 * William Elfversson, wiel1300
 * Version 1.0 (2018-12-08)
 * Version 1.5 (2019-01-16)
 * ------------------------------*/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//my own toLower solution - proud! ;)
string toLower (string input);

//Outputs "lastname firstname" string for sorting
string createSortName (string firstName, string lastName);

//function that sorts 3 input names
void sort3Strings(string name1, string name2, string name3);

int main() {

    // declaration of program variables 
    string input, firstName1, lastName1, firstName2, lastName2, firstName3, lastName3;
    
    //user input 3 names 
    cout << "Input FIRST full name with space between: ";
    getline(cin,input);
    istringstream iss(input);
    iss >> firstName1 >> lastName1;

    cout << "Input SECOND full name with space between: ";
    getline(cin,input);
    iss.clear();
    iss.str(input);
    iss >> firstName2 >> lastName2;

    cout << "Input THIRD full name with space between: ";
    getline(cin,input);
    iss.clear();
    iss.str(input);
    iss >> firstName3 >> lastName3;
    iss.clear();

    cout << "====== SORTED NAMES ======" << endl;

    sort3Strings(
            createSortName(firstName1,lastName1),
            createSortName(firstName2,lastName2),
            createSortName(firstName3,lastName3));

    return 0;
}


string toLower (string input){

    string output;

    for (int i = 0; i < input.length(); i++){
        if (input[i] < 97)
            output += input[i]+32;
        else
            output += input[i];
    }

    return output;
}

string createSortName (string firstName, string lastName)
{
    string sortName = lastName + " " + firstName;

    return sortName;
}

void sort3Strings(string name1, string name2, string name3){

    if (toLower(name1) < toLower(name2) && toLower(name1) < toLower(name3)){
        cout << name1 << endl;
        if (toLower(name2) < toLower(name3)){
            cout << name2 << endl;
            cout << name3 << endl;
        }
        else{
            cout << name3 << endl;
            cout << name2 << endl;
        }
    }
    else if (toLower(name2) < toLower(name1) && toLower(name2) < toLower(name3)){
        cout << name2 << endl;
        if (toLower(name1) < toLower(name3)){
            cout << name1 << endl;
            cout << name3 << endl;
        }
        else{
            cout << name3 << endl;
            cout << name1 << endl;
        }
    }
    else if (toLower(name3) < toLower(name1) && toLower(name3) < toLower(name2)){
        cout << name3 << endl;
        if (toLower(name1) < toLower(name2)){
            cout << name1 << endl;
            cout << name2 << endl;
        }
        else{
            cout << name2 << endl;
            cout << name1 << endl;
        }
    }
    else
        cout << "ERROR" << endl;
}

