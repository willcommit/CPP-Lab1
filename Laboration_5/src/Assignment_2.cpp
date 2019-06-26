/* -------------------------------
 * Laboration 5, Assignment_2.cpp
 * Binary Search Algorithm
 * William Elfversson, wiel1300
 * 2019-01-03
 * -------------------------------*/

#include <iostream>
#include <random>
#include <ctime>

using namespace std;

// Takes array and "array size" and fill array with random numbers
void fillArray  (int array[], int size);
// Takes array and "array size" and sorts array, ascending order
void bubbleSort (int array[], int size);
// Takes array and "array size" and prints elements to console
void printArray(int array[], int size);
// Takes search number, array and "array size" and returns element index of search number if found.
// If not found returns -1/
int binarySearch(int searchNumber, int array[], int size);


int main()
{
	const size_t SIZE {200}; // constant int used to size array
	int theArray[SIZE] {0}; // array initialised with SIZE and 0s.

	//assigning random numbers to first array
	fillArray(theArray,SIZE);

	//bubble sort of array, required for a binary search to work!
	bubbleSort(theArray,SIZE);

	//printing array to check visually check that sort and search algorithm is working
	printArray(theArray, SIZE);

	int searchNumber {0};
	cout << "Enter number to search for: ";
	cin >> searchNumber;
	cin.get();

	int result = binarySearch(searchNumber, theArray, SIZE);

	if (result == -1)
		cout << "Number not found!";
	else
		cout << "Your number is at index: " << result << " and it's: " << theArray[result] << endl;

    return 0;
}

void fillArray  (int array[], int size)
{
	//random generator
	default_random_engine generator(static_cast<unsigned>(time(0))); //time as random seed
	uniform_int_distribution<int> random(1,100); //produces random numbers between 1 and

	for(int i = 0; i < size; i++){
		array[i] = random(generator);
	}
}

void bubbleSort (int array[], int size)
{
	for(auto i=0; i < size-1; i++)
		for(auto j=0; j<size-1; j++)
			if(array[j] > array[j+1]){
				int tmp = array[j];
				array[j] = array[j+1];
				array[j+1] = tmp;
			}
}

void printArray(int array[], int size)
{
	for(auto i=0; i<size; i++){
		cout << "Index " << i << " inside " << array[i] << endl;
	}
}

int binarySearch(int searchNumber, int array[], int size)
{
    // binary search divides search sector in TWO (binary) halves and searches new half for the target number,
    // this i done as follows:
	int first {0}; // int initialized to first index in search sector (whole array).
	int last = size; // int initialized to last index in search sector (last index in array initially)
	int mid {0}; // middle of current "search sector", when the value att this index equals our search number
	// we have found the right index!

	while (first <= last){
		mid = (first + last) / 2; // determine middle of new search sector with the current values of first and last
		if (searchNumber > array[mid])
			first = mid + 1; // IF search number is larger than value at current index mid,
			//the new search sector is above this number, therefore FIRST number will be mid + 1
		else if (searchNumber < array[mid])
			last = mid - 1;// IF search number is smaller than value at current index mid,
            //the new search sector is below this number, therefore FIRST number will be mid - 1
		else
			return mid; // value and index mid is equal to search number.
	}
	return -1; // if search number NOT found the function will return -1
}



