/* ------------------------------
 * Laboration 2, Assignment_1.cpp
 * Pythagorean triangles
 * William Elfversson, wiel1300
 * 2018-11-24
 * ------------------------------*/

#include <iostream>
#include <iomanip>
using namespace std;

bool testEven100 (int num){
    const int TEST_100 = 100;
    return num%TEST_100 == 0;
}

int main() {

    int a = 0; //side a
    int b = 0; //side b
    int c = 0; //hypotenuse
    const int MAX = 500; 
    int counter = 0; //counting triangles

        for (a = 1; a <= MAX; a++ ){
            for (b = a; b <= MAX; b++){
                for(c = 1; c <= MAX; c++ ){
                    if (a*a + b*b == c*c){
                        if (testEven100(c)){ //sorting out all hypotenuse: evenly dividable by 100
                            cout << a << "^2" << " + " << b << "^2" << " = " << c << "^2" << endl;
                        }    
                        counter++;
                    }
                }
            }
        }

    cout << counter << " triangles" << endl;
    return 0;
}

