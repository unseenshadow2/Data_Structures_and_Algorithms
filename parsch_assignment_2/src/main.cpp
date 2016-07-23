// Week 2 Assignemnt
// Data Structures and Algorithms
// Written by Anthony Parsch
// Compiled and tested on Ubuntu Linux

#include <iostream>
#include <random>

#include "DoublyLinkedList.hpp"

using namespace std;

void original_main();

int main()
{
	// Our linked list
	DoublyLinkedList<int> intll;

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