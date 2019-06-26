/* ------------------------------
 * Laboration 1, Assignment_2.cpp
 * Code Correction
 * William Elfversson, wiel1300
 * 2018-11-15
 * ------------------------------*/

//FYI correction comments start with SYNTAX or LOGIC depending on type of error

#include <iostream>                                 //SYNTAX missing iostream library
using namespace std;                                //SYNTAX missing which namespace is used in library
                                                    //AND I added the whole namespace

int main() {

// Variables and constants
    float radius, circumference, area = 0;          //SYNTAX(?) good practice to initialize values directly in C/CPP
    //CORR 4 using "int" instead of "float"
    const float PI = 3.14;                          //SYNTAX should be |,| instead of |.|

// Input the circles radius
    cout << "Assign the circle's radius [mm]: ";    //SUGGESTION add units which are use for ex. mm or cm
    cin >> radius;                                  //SYNTAX stream operator |>>| instead of assignment operator |=|

// Algorithm to calculate circumference and area
    circumference = PI * (radius + radius);         //LOGIC wrong formula
    area = PI * (radius*radius);                    //LOGIC wrong formula
                                                    //SYNTAX should be variable |PI| instead of |pi|

// Output of results
    cout << "A circle with the radius "
         << radius << " mm has the " <<             //SYNTAX missing |"|
         "circumference "                           //AND stream operator |>>| after string
         << circumference << " mm and area "
         << area <<" mm2"<<endl;

// Validate x
    cout << "Please input number for evaluation: "; //SYNTAX missing prompt for user to continue program..
    int x;
    cin >> x;
    if (x == 100)                                   //SYNTAX comparision operator |==| instead of assignment |=|
        cout << "x is equal to 100" << endl;
    if (x > 0)                                      //SYNTAX remove semicolon |;|
        cout << "x is larger than zero" << endl;    //SYNTAX indentation should be here for readability

    switch (x) {
        case 5:
            cout << "x is equal to 5 " << endl;
        case 10:
            cout << "x is equal to 10" << endl;
        default :
            cout << "x is neither 5 nor 10" << endl;
            return 0;
    }

} // End main                                       //SYNTAX missing closing bracket |}|
