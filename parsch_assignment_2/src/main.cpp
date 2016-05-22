// Week 2 Assignemnt
// Data Structures and Algorithms
// Written by Anthony Parsch
// Compiled and tested on Ubuntu Linux

#include <iostream>

#include "DoublyLinkedList.hpp"

using namespace std;

int main()
{
	DoublyLinkedList<int> intll;

	// Fill the linked list with values
	for (int i = 0; i < 5; i++) { intll.Insert(i+1); cout << "Adding " << i+1 << " to position " << i << endl; }

	cout << "Testing [0] " << intll[0] << endl;
	cout << "Testing [1] " << intll[1] << endl;
	cout << "Testing [2] " << intll[2] << endl;
	cout << "Testing [3] " << intll[3] << endl;
	cout << "Testing [4] " << intll[4] << endl;

	if (!intll.Delete(intll.Find(2))) cout << "We fucked up on delete" << endl;

	for (int i = 0; i < intll.Length(); i++) cout << "Run " << i << " " << intll[i] << endl;

	return 0;
}
