/* ------------------------------
 * Laboration 3, Assignment_3.cpp
 * Encryption
 * William Elfversson, wiel1300
 * 2018-12-09
 * ------------------------------*/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {

    string input, encrypted, decrypted; 
    int counter = 0; //counter used for indexing in strings
    const int ROT7 = 7; // encryption key 1 
    const int ROT13 = 13; // encryption key 2 
    bool switchFlag = true; // flag for switch between encryption keys

    //user input
    cout << "Enter a text to be encrypted: ";
    getline(cin, input);

    //encrypt
    while (counter < input.length()){
        // ROT 13 encryption key added
        while (switchFlag){ 

            encrypted += input[counter]+ROT13; 
            counter++;

            if (counter == input.length()){
                break;
            }
            else if (counter%5 == 0){
                switchFlag = false;
                break;
            }          
                
        }
        // ROT 7 encryption key added
        while (!switchFlag){

            encrypted += input[counter]+ROT7;
            counter++;

            if (counter == input.length()){
                break;
            }
            else if (counter%5 == 0){
                switchFlag = true;
                break;
            }            
        }
    }

    counter = 0; // reset counter
    switchFlag = true; // reset flag

    //decrypt
    while (counter < encrypted.length()){
        // ROT 13 encryption key removed
        while (switchFlag){

            decrypted += encrypted[counter]-ROT13;
            counter++;

            if (counter == encrypted.length()){
                break;
            }
            else if (counter%5 == 0){
                switchFlag = false;
                break;
            }          
                
        }
        // ROT 7 encryption key removed
        while (!switchFlag){

            decrypted += encrypted[counter]-ROT7;
            counter++;

            if (counter == encrypted.length()){
                break;
            }
            else if (counter%5 == 0){
                switchFlag = true;
                break;
            }            
        }
    }
    //user output
    cout << "\n+++++ ENCRYPTED +++++" << endl;
    cout << encrypted << endl;
    cout << "++++++++ END ++++++++\n" << endl;
    cout << "----- DECRYPTED -----" << endl;
    cout << decrypted << endl;
    cout << "-------- END --------\n" << endl;

    return 0;
}