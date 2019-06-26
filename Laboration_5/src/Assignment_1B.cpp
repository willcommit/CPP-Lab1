#include <iostream>
#include <vector>
#include <ctime>
#include <random>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> firstVector;
	const int SIZE = 600;

	//random generator
	default_random_engine generator(static_cast<int>(time(0))); //time as random seed
	uniform_int_distribution<int> random(1, 100); //produces random numbers between 1 and 100

	//assigning random numbers to first vector
	for(int i = 0; i<SIZE; i++)
	{
		firstVector.push_back(random(generator));
	}
	
	//declaring second vector
	vector<int> secondVector;

	//assigning/copy first vector to second
	secondVector = firstVector;

	//sort in vector in ascending order
	sort(secondVector.begin(), secondVector.end());

	//calculate sum
	int sum = 0;
	for (auto number: secondVector)
	{
		sum += number;
	}

	//calculating average, smallest and largest
	int average = sum/secondVector.size();
	int smallest = *(min_element(secondVector.begin(), secondVector.end()));
	int largest =  *(max_element(secondVector.begin(), secondVector.end()));

	cout << "\nSmallest number in vector is: " << smallest << endl;
	cout << "Largest number in vector is: " << largest << endl;
	cout << "Vector average number is: " << average << endl;

	int countOccurrence = 0; //counter used to count how many times number occurs 
	int searchNumber = 0; //search number entered by user

	cout << "please input number to count occurrence: ";
	cin >> searchNumber;
	cin.get();

	//using vector method algorithm to solve occurrence count, very nice
	countOccurrence = count (secondVector.begin(), secondVector.end(), searchNumber);

	cout << searchNumber << " occurred " << countOccurrence << " times in vector!" << endl;

	vector<vector<int>> printVector; //vector of vectors used to store number occurrence
	for(int i = 0; i <= 99; i++)
	{
		for(int j = 0; j < secondVector.size(); j++)
		{
			printVector.push_back(vector<int>()); //push back of new vector to hold number count
			if(secondVector[j] == i)
			{
				cout << secondVector[j] << " "; // printing numbers 
				printVector[i].push_back(secondVector[j]); // saving numbers to vector
			}
		}
		cout << endl;
	}
	
	//finding largest vector size (the number with most occurrences)
	int max = printVector[0].size(); 
	int mostOf = 0; //used to save WHICH number it was most of
	for(int i = 0; i < printVector.size(); i++)
	{
		if (printVector[i].size() > max)
		{
			max = printVector[i].size();
			mostOf = i;
		}
	}

	cout << "Largest collection of numbers is: " << mostOf << " and it consists of " << max << " numbers!" <<  endl;

    return 0;
}

