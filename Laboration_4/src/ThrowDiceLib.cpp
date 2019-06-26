/* ------------------------------
 * ThrowDiceLib.cpp
 * Function definitions to ThrowDiceLib.h
 * William Elfversson, wiel1300
 * 2018-12-18
 * ------------------------------*/


#include "ThrowDiceLib.h"

void throwDice() 
{

	const int DICEMAX = 6;
	const int DICEMIN = 1;
	bool exit = false;

	while (!exit) 
    {

		// variable declaration
		float count1 = 0.0,
			  count2 = 0.0,
			  count3 = 0.0,
			  count4 = 0.0,
			  count5 = 0.0,
			  count6 = 0.0;
		float throws = 0.0;
		int diceRoll = 0;
		float sumCount = 0.0;

		// seeds the random with current timestamp
		srand(time(0));

		// User input
		std::cout << "Enter a how many times to throw dice: ";
		std::cin >> throws;
		std::cin.get();

		// Loops throws and counts results (sides) 
		for (int i = 0; i < throws; i++) 
        {
			diceRoll = rollDice(DICEMAX, DICEMIN);
			countSides(diceRoll, count1, count2, count3, count4, count5, count6);
		}

		std::cout.precision(2);
		// Displays results in console
		std::cout << "[1] = " << count1 << " times " << calcRelative(count1, throws) << "%" << std::endl
			 << "[2] = " << count2 << " times " << calcRelative(count2, throws) << "%" << std::endl
			 << "[3] = " << count3 << " times " << calcRelative(count3, throws) << "%" << std::endl
			 << "[4] = " << count4 << " times " << calcRelative(count4, throws) << "%" << std::endl
			 << "[5] = " << count5 << " times " << calcRelative(count5, throws) << "%" << std::endl
			 << "[6] = " << count6 << " times " << calcRelative(count6, throws) << "%" << std::endl;

		// ask user to throw again or quit
		quitPrompt(exit);
	}
}

// rolls random number based on max number & min number input
int rollDice(int max, int min) 
{
	int dice;
	return dice = rand() % max + min;
}

// counts sides of dices based in dice roll, saves side count into float for each side
void countSides(int diceRoll, 
				float &count1, 
				float &count2, 
				float &count3, 
				float &count4,
				float &count5,
				float &count6) 
{

	switch (diceRoll)
	{
	case 1:
		count1++;
		break;
	case 2:
		count2++;
		break;
	case 3:
		 count3++;
		 break;
	case 4:
		count4++;
		break;
	case 5:
		count5++;
		break;
	case 6:
		count6++;
		break;
	default:
		break;
	}
}

// calculates relative % side count of total throws
float calcRelative(float count, float throws) 
{
	return (count / throws) * 100;
}

// quit program prompt 
void quitPrompt(bool &exit) 
{
	char reply;
	std::cout << "Do you wan to throw again? [Y/N]" << std::endl;
	std::cin >> reply;
	if (reply == 'n' || reply == 'N')
		exit = true;
}
