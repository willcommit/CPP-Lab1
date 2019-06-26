#include <iostream>
#include <iomanip>
#include <ctime>
#include <random>

using namespace std;


int main() 
{
	const size_t SIZE = 600; //first array size according to instruction
	int firstArray[SIZE] {0}; 
	int num {0}; 

	//random generator
	default_random_engine generator(static_cast<int>(time(0))); //time as random seed
	uniform_int_distribution<int> random(1,100); //produces random numbers between 1 and 100	

	//assigning random numbers to first array
	for(int i = 0; i < SIZE; i++)
	{
		firstArray[i] = random(generator);		
	}
	
	//declaring second array, same size as first
	int secondArray[SIZE] {0};
	
	//assign first array to second	
	for(int i = 0; i<SIZE; i++)
	{
		secondArray[i] = firstArray[i];
	}

	int sum = 0; //declaring int to save sum, for average calculation

	//calculate average
	for(int i = 0; i<SIZE; i++)
	{
		sum += secondArray[i];
	}
	
	int	average = sum/SIZE; //calculating average number
	
	//bubble sort algorithm
	for(auto i=0; i < SIZE-1; i++)
		for(auto j=0; j<SIZE-1; j++)
			if(secondArray[j] > secondArray[j+1])
			{
				int tmp = secondArray[j];
				secondArray[j] = secondArray[j+1];
				secondArray[j+1] = tmp;
			}

	//printing to console results
	cout << "AVERAGE = " << average << endl;
	cout << "SMALLEST = " << secondArray[0] << endl;
	cout << "LARGEST = " << secondArray[599] << endl;
	

	//printing sorted array
	for(int i = 1; i <= 100; i++)
	{	
		for(int j = 0; j < SIZE; j++)
		{
			if(secondArray[j] == i)
				cout <<  secondArray[j] << " ";
		}
		cout << endl;
	}


	int counter = 0; //counter used to count how many time number occurs
	int searchNumber = 0; //search number entered by user
	cout << "Please enter a number to see how many time it occurs" << endl; 
	cin >> searchNumber;
	cin.get();
	
	//search array for search number and counting hits
	for(int i=0; i < SIZE; i++)
	{
		if(searchNumber == secondArray[i])
		{
			counter++;
		}
	}

	cout << searchNumber << " occurred " << counter << " times" << endl;
	
	//find which number occurs most was more complicated than expected..
	const int SIZE_SMALL {100}; //size for new array holding number of numbers...
	int countArray[SIZE_SMALL] {0}; // counting number of numbers array

	for(int i=1; i <= SIZE_SMALL; i++)
	{
		counter = 0;
		//searching for each number in array and counting it
		for(int j=0; j<SIZE; j++)
		{
			if(i == secondArray[j])
			{
				counter++;
			}

		}
		countArray[i] = counter; //adding occurrences to array
	}

	//finding largest number i number of numbers array
	int max = countArray[0];
	int mostOf = 0; //used to save WHICH number it was most of
	
	for(int i = 0; i<SIZE_SMALL; i++)
	{
		if(countArray[i] > max)
		{
			max = countArray[i];
			mostOf = i;
		}
	}

	cout <<"There is most of following number: " << mostOf << " and it consists of:  "<< max <<" numbers" << endl;

    return 0;
}

