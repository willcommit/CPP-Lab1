/* ------------------------------
 * Laboration 2, Assignment_2.cpp
 * ASCII-table
 * William Elfversson, wiel1300
 * 2018-11-24
 * ------------------------------*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    //Cell variables
    const int START = 32; //start value of ASCII table
    int cellData = 0;
    const int DELTA = 32; //delta between columns in ASCII "standard" table.
    //Table variables 
    int nrRows = 31;
    int nrCols = 6;

        for (int row=0; row <= nrRows; row++){
            cellData = START + row; //calculation of column start value
            for(int col =0; col <= nrCols; col++){
                cout << setw(4) << cellData << ": " << static_cast<char> (cellData); //Printing celldata and converting int to char, showing ASCII
                cellData += DELTA;
        }
        cout << endl;
    }
    return 0;
}

