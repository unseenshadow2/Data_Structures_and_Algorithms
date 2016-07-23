// Week 2 Assignemnt
// Data Structures and Algorithms
// Written by Anthony Parsch
// Compiled and tested on Ubuntu Linux

#include <iostream>
#include <random>
#include <chrono>
#include <ctime>

#include "DoublyLinkedList.hpp"

using namespace std;

void original_main();
int compare(int i1, int i2);

int main()
{
	// Our linked list
	DoublyLinkedList<int> intll;
	
	// Our random number generators (for building the array)
	mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
	uniform_int_distribution<int> uni(1,1000);
	
	// What is the input of our user?
	int input = 0;
	
	// Time values
	int sortStart;
	int sortEnd;
	
	// Enter... The Menu
	cout << "\nPlease enter a number of integers to be sorted: ";
	cin >> input;
	
	if (input > 0)
	{
		for (int i = 0; i < input; i++)
		{
			intll.Insert(uni(rng));
		}
		
		// Run the sort and see how long it takes
		sortStart = clock();
		intll.Sort(compare);
		sortEnd = clock();
		
		// Display our values if there are less than or equal to 100
		if (input <= 100)
		{
			cout << "\n";
			
			// The value to be iterated over for the display
			DoublyNode<int>* value = intll.GetFirst();
			
			for (int i = 0; i < input; i++)
			{
				cout << value->key << endl;
				value = value->next;
			}
		}
		
		// Get the time the run took
		int sortTime = sortEnd - sortStart;
		cout << "\nThe run took " << sortTime << " ticks and " << ((float)sortTime)/CLOCKS_PER_SEC << " seconds." << endl;
	}
	else
	{
		cout << "ERROR: Incorrect input. Halting program." << endl;
	}
	
	cin.ignore();
	cin.get();

	return 0;
}

void original_main()
{
	DoublyLinkedList<int> intll;
	DoublyLinkedList<char> chrll;
	DoublyNode<int>* node;

	// Fill the linked lists with values
	cout << "Filling linked lists..." << endl;
	for (int i = 0; i < 5; i++) { intll.Insert(i+1); cout << "Adding " << i+1 << " to position " << i << endl; }
	cout << endl;
	for (int i = 0; i < 6; i++) { chrll.Insert((char)(i+97)); cout << "Adding " << (char)(i+97) << " to position " << i << endl; }

	// Attempting a delete
	cout << "Attempting to delete the value '2'" << endl;
	if (!intll.Delete(intll.Find(2))) cout << "Bad delete guys..." << endl;

	cout << endl;
	
	// Display intll
	for (int i = 0; i < intll.Length(); i++) cout << "Run " << i << " " << intll[i] << endl;
	cout << endl;
	
	// Display chrll
	for (int i = 0; i < chrll.Length(); i++) cout << "Run " << i << " " << chrll[i] << endl;
	cout << endl;
	
	// Find 4
	cout << "Searching for 4..." << endl;
	node = intll.Find(4);
	cout << "Found at address \"" << node << "\" with value " << node->key << endl;
}

// Our sorts's compare
int compare(int i1, int i2)
{
	if (i1 == i2) return 0;
	else if (i1 < i2) return 1;
	else return -1;
}