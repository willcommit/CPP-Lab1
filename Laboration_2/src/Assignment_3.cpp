/* ------------------------------
 * Laboration 2, Assignment_3.cpp
 * Palindrome
 * William Elfversson, wiel1300
 * 2018-11-26
 * ------------------------------*/

#include <iostream>
using namespace std;

//counts digits in number input
int digitCounter (int input){

    int digits = 0;

    do{
        input = input/10;
        digits++;
    }
    while(input >= 1);

    return digits;
}

//checks if input is a five digit number!
void digitCheck (int digits){

    int input;
    do{
    if (digits != 5){
        cout << "Please enter a five digit number: ";
        cin >> input;
        digits = digitCounter(input);
    }
    else 
        cout << "You have entered a five digit number!" << endl;
    }
    while (digits != 5);
}

//extracts a digit with a number input and digit pos to be extracted.
//NOT happy with this algorithm, not so elegant, but it works (sort off, some memory problems when looping?), don't have more time for this :(
int digitExtract (int input, int pos){
   
    int digit = 0;
    int decimal = 1;

    for(int i = 0; i < (pos-1); i++)
        decimal *= 10;
    
    if (pos == 5)
        digit = (input - input%decimal)/decimal;
    else if (pos > 1 && pos < 5)
        digit = (input%(decimal*10) - input%decimal)/decimal;
    else if (pos == 1)
        digit = input%10;  //Not so nice solution.. Brain not working atm..
    
    return digit;
}
//prompt user to test a new number OR exit program
bool testAgain (){
    
    char answer;

    cout << "Do you want to test a new number? y/n" << endl;
    cin >> answer;

    if (answer == 'n' || answer == 'N'){
        cout << "Bye!" << endl;
        return true;
    }
    else 
        return false;
}

int main() {

    int input = 0; //number input
    bool exit = false; //bool control program state

    while (!exit){

        cout << "Please enter a five digit number: ";
        cin >> input;

        int digits = digitCounter(input); // saving digit count in int variable

        digitCheck (digits); //testing digit count

        //Extraction of each number
        int tenThousand = digitExtract (input, 5);
        int thousand= digitExtract (input, 4);
        int hundred = digitExtract (input, 3);
        int ten = digitExtract (input, 2);
        int one = digitExtract (input, 1);

        cout << "Number reversed: " << one << ten << hundred << thousand << tenThousand << endl;

        if (tenThousand == one){
            if (thousand == ten){
                cout << "It's a PALINDROME!!!!"<<endl;
            }
        }
        else 
            cout << "no palindrome :(" << endl;

        exit = testAgain(); //prompt user to test a new number OR exit program
    }
    return 0;
}

