/* ------------------------------
 * Laboration 3, Assignment_1.cpp
 * Replace words in strings
 * William Elfversson, wiel1300
 * 2018-12-06
 * ------------------------------*/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//function that capitalizes first letter of input string
string capitalize(string input){
    string output;
    for(int i = 0; i < input.length(); i++){
        if (i == 0)
            output += input[i]-32;
        else
            output += input[i];
    }
    return output;
} 

int main() {
    //constant strings to work with
    string const inText1 = "Foten är en kroppsdel som förekommer mycket i våra uttryck.";
    string const inText2 = "På stående fot betyder omedelbart, utan förberedelse.";
    string const inText3 = "Försätta på fri fot betyder att ge någon friheten."; 
    string const inText4 = "Sätta foten i munnen betyder att göra bort sig.";
    string const inText5 = "Få om bakfoten betyder att missuppfatta något.";
    string const inText6 = "Skrapa med foten betyder att visa sig underdånig eller ödmjuk.";
    string const inText7 = "Stryka på foten betyder att tvingas ge upp.";
    string const inText8 = "Leva på stor fot betyder att föra ett dyrbart eller slösaktigt leverne.";
    string const inText9 = "Varför fick du foten???";

    //declaration of formating strings
    string word, replaceWord, capWord, capReplaceWord;

    //concatenating strings to one
    string text = inText1 + " " + inText2 + " " + inText3 + " " + inText4 + " " + inText5 + 
    " " + inText6 + " " + inText7 + " " + inText8 + " " + inText9;
    
    //user input
    cout << "Please enter word to replace in text: ";
    cin >> word;
    capWord = capitalize(word);
    cout << "Please enter word to replace WITH: ";
    cin >> replaceWord;
    capReplaceWord = capitalize(replaceWord);

   
    //parse algorithm
    for(int i = 0; i < text.length(); i++){
        if (text.substr(i,3) == capWord)
            text.replace(i,3,capReplaceWord);
        else if (text.substr(i,3) == word)
            text.replace(i,3,replaceWord); 
        else if (text[i] == '.'){
            text.insert(i+1, "\n"); //TODO not working as expected, white space after newline..
        }                               
    }

    //print result
    cout << "====== FORMATED TEXT ======" <<endl;
    cout << text << endl;
    cout << "========== END ==========" << endl;

    return 0;
}