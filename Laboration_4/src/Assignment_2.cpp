/* ------------------------------
 * Laboration 4, Assignment_2.cpp
 * RingPling
 * William Elfversson, wiel1300
 * 2018-12-17
 * ------------------------------*/

/*
Below pseudo code was made in seperate .txt before final program and differs from end result..

======[PSEUDO CODE]======
Ask user for start time
Test if time input is correct (hh:mm)
Ask user for stop time 
Test if time input is correct (hh:mm)
Calculate total call time
Calculate price according to following parameters:
    * Call time within full price time span 08:00-18:30
    * Call time outside full price time span
    * Call time spans time span in either before or after
    * Call time > 30 mins
Add tax (25%) to final price. 
Display price to user
Ask user to calculate new timespan or quit program
*/

// LIBRARIES
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//FUNCTION DECLARATION
int convertHHtoMM(int hours);
void extractTime (string input, int &hours, int &minutes);
bool testInput(int hh, int mm);
double calcPrice (int hhStart, int mmStart, int hhStop, int mmStop);
void wrongInputPrompt();
void exitPrompt(bool &exit);

// MAIN PROGRAM 
int main() 
{
	bool exit = false; // controls program loop
    string input = " "; // input string initialization
    // Variables for start time
    int hhStart = 0;
	int mmStart = 0;
    // Variables for stop time
    int hhStop = 0;
	int mmStop = 0;

	while (!exit)
	{   
        // Ask user for start time of call  
		do
        {
            cout << "Please enter a start time in following format hh:mm: ";
		    cin >> input;

		    extractTime(input, hhStart, mmStart);

            if (!testInput(hhStart,mmStart)) //checks input
                wrongInputPrompt();
        }
        while (!testInput(hhStart,mmStart)); //checks input

        // Ask user for stop time of call  
        do
        {
            cout << "Please enter a stop time in following format hh:mm: ";
		    cin >> input;

            extractTime(input,hhStop,mmStop);

            if (!testInput(hhStop,mmStop)) //checks input
                wrongInputPrompt();
        }
        while (!testInput(hhStop,mmStop)); //checks input

        //checks if stop time is larger then start time, otherwise new input or quit
        if ((convertHHtoMM(hhStop)+mmStop) <= (convertHHtoMM(hhStart)+mmStart)) 
        {
            wrongInputPrompt();
            exitPrompt(exit);
        }       
        else
        {
            // calculates price
            double price = calcPrice(hhStart, mmStart, hhStop, mmStop);

            // catch error from calculation
            if(price == -1)
            {
                wrongInputPrompt();
                exitPrompt(exit);
            }
            // displays price in kr  
            else 
            {
                cout << "Your price is: " << price << "kr" << endl;
                exitPrompt(exit);
            }
        }     					
	}	
    return 0;
}

// Converts input whole hours to output minutes
int convertHHtoMM(int hours)
{
    constexpr int HOUR_MIN = 60;
	int minutes = hours * HOUR_MIN;
	return minutes;
}

// Extracts whole hours from input string, returns hours as an int
void extractTime (string input, int &hours, int &minutes)
{
    string hh, mm;
    istringstream iss(input);
    getline(iss, hh,':');
    getline(iss, mm);
    hours = stod(hh);
    minutes = stod(mm);
    iss.clear();
}

// Tests if input fulfills following time input req: hh:mm
bool testInput(int hh, int mm)
{
    if (hh >= 0 && hh <= 23 && mm >= 0 && mm <= 59)
        return true;
    else
        return false;
}

// Calculates price based on input of start and stop hours and minutes. 
// Returns price as double int. 
// I know there may be a smarter/more elegant way to calculate specific timespan prices, but needed to rush this unfortunately. 
double calcPrice (int hhStart, int mmStart, int hhStop, int mmStop)
{
    
    constexpr int FULL_PRICE = 4; // 4 kr/min
    constexpr double REDUCED_PRICE_OFFHOUR = 4.0 * 0.35; // 65% discount on 4 kr/min
    constexpr double REDUCED_PRICE_TIME = 0.85; // 15% discount on calls > 30 min
    constexpr double TAX = 1.25; // 25% tax
    constexpr int HOUR_MIN = 60; // constant for one hour in minutes
    constexpr int HALFHOUR_MIN = 30; // constant for half hour in minutes
    constexpr int START_TIME_FULL_PRICE = 480; // 08:00 in minutes
    constexpr int STOP_TIME_FULL_PRICE = 1110; // 18:30 in minutes
    constexpr int DELTA_TIME_FULL_PRICE =  STOP_TIME_FULL_PRICE-START_TIME_FULL_PRICE;

    int totalMinStart = convertHHtoMM(hhStart) + mmStart; // converts start time to minutes
    int totalMinStop = convertHHtoMM(hhStop) + mmStop; // converts stop time to minutes
    int deltaTime = totalMinStop - totalMinStart; // calculates call time

    // Tests if timespan is within 08:00-18:30
    if (totalMinStart >= START_TIME_FULL_PRICE && totalMinStop <= STOP_TIME_FULL_PRICE)
    {
        if (deltaTime > HALFHOUR_MIN) // test if talk time is more than 30 min
            return (deltaTime * FULL_PRICE * TAX) * REDUCED_PRICE_TIME;
        else
            return deltaTime * FULL_PRICE * TAX;
    }

    // Tests if timespan is starting before 08:00 but ending after    
    else if (totalMinStart <= START_TIME_FULL_PRICE && totalMinStop <= STOP_TIME_FULL_PRICE && totalMinStop >= START_TIME_FULL_PRICE)
    {
        int deltaFullPrice = totalMinStop-START_TIME_FULL_PRICE;
        int deltaReducePrice = deltaTime - deltaFullPrice;

        if (deltaTime > HALFHOUR_MIN)
            return (((deltaReducePrice * REDUCED_PRICE_OFFHOUR) + (deltaFullPrice * FULL_PRICE)) * REDUCED_PRICE_TIME) * TAX; 
        else
            return ((deltaReducePrice * REDUCED_PRICE_OFFHOUR) + (deltaFullPrice * FULL_PRICE)) * TAX;
    }
    // Tests if timespan is starting before 18:30 but ending after   
    else if (totalMinStart >= START_TIME_FULL_PRICE && totalMinStart <= STOP_TIME_FULL_PRICE && totalMinStop >= STOP_TIME_FULL_PRICE)
    {
        int deltaFullPrice = STOP_TIME_FULL_PRICE - totalMinStart;
        int deltaReducePrice = deltaTime - deltaFullPrice;

        if (deltaTime > HALFHOUR_MIN)
            return (((deltaReducePrice * REDUCED_PRICE_OFFHOUR) + (deltaFullPrice * FULL_PRICE)) * REDUCED_PRICE_TIME) * TAX; 
        else
            return ((deltaReducePrice * REDUCED_PRICE_OFFHOUR) + (deltaFullPrice * FULL_PRICE)) * TAX; 
    }
    // Tests none of above but outside of 08:00 - 18:30. 
    // PROBLEM if talktime start before 08:00 and ends after 18:30, below statement will ALSO run..   
    else if (totalMinStart <= START_TIME_FULL_PRICE && totalMinStop >= STOP_TIME_FULL_PRICE)
    {
        if (deltaTime > HALFHOUR_MIN)
            return (((deltaTime-DELTA_TIME_FULL_PRICE) * REDUCED_PRICE_OFFHOUR) + (DELTA_TIME_FULL_PRICE * FULL_PRICE)) * REDUCED_PRICE_TIME  * TAX;
        else
            return ((deltaTime* REDUCED_PRICE_OFFHOUR)  * TAX);
    }
    else 
        return -1.0;
}
// Displays text if user makes bad input, void function.
void wrongInputPrompt()
{
    cout << "Wrong input.." << endl;
}

// Ask if user wants to calculate again, input bool that controls program loop.
void exitPrompt(bool &exit)
{
	char userReply = ' ';
	cout << "Do you want to calculate again: [Y/N] ";
	cin >> userReply;
	if (userReply == 'n' || userReply == 'N')
		exit = true;
}