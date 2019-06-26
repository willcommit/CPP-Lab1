/* -------------------------------
 * Laboration 1, Assignment_1.cpp
 * Fuel Consumption
 * William Elfversson, wiel1300
 * 2018-11-15
 * -------------------------------*/
//header
#include <iostream>
#include <iomanip>
using namespace std;
//------------------------------------------------------------------

int main() {

    //input variable declarations
    double trip0, trip1, tripDelta = 0;  //trip distance variables
    double refuel;                       //fuel filled up
    const double fuelPrice = 16;         //fuel cost skr/liters

    //output variable declarations
    double fuelConsum, fuelCost = 0;     //fuel consumption (liters/km) and cost (skr/litres)

    //program control variables
    bool exit = false;
    char answer;

    do{
        //welcome banner
        cout << "-------------------------\n"
                "FUEL CONSUMPTION AND COST\n"
                "-------------------------" << endl;

        //assignment of input variables
        cout << "Please enter start trip meter distance [km]: ";
        cin >> trip0;
        cout << "Please enter current trip meter distance [km]: ";
        cin >> trip1;
        tripDelta = trip1 - trip0;
        cout << "Traveled distance is: " << tripDelta << " km" << endl;
        cout << "Enter how many liters you refueled: ";
        cin >> refuel;

        cout << "\n=========RESULT=========" << endl;
        //calculation of consumption
        fuelConsum = refuel/tripDelta;
		cout << fixed << setprecision(2);
		cout << right;
		cout << setfill(' ');
        cout << "Your fuel consumption is  : " << setw(5) <<  fuelConsum*10 << " lt/10km" << endl;

        //calculation of fuel cost skr/km
        fuelCost = fuelPrice*fuelConsum;
        cout << "Your fuel cost is         : " << setw(5) << fuelCost*10 << " kr/10km" << endl;
        cout << "===========END==========\n" << endl;

        //test program state
        cout << "Do you want to make new calculation Y/N? ";
        cin >> answer;
        if (answer == 'n' || answer == 'N'){
            exit = true; //break out of loop
        }
    } while (!exit);

    return 0;
}
