// Lab 11 Assignemnt
// Data Structures and Algorithms
// Written by Anthony Parsch
// Compiled and tested on Ubuntu Linux

#include <iostream>
#include <unistd.h>
#include "BST.hpp"

using namespace std;

int main()
{
	BSTree<int> toTest;

	// Insert test
	cout << "Inserting test..." << endl;
	for (int i = 0; i < 20; i+=2) // Evens
	{
		leaf<int> toInsert;
		toInsert.setKey(i);
		toInsert.setValue((char)((int)'a' + i));
		toTest.insert(toInsert);
	}
	for (int i = 1; i < 19; i+=2) // Odds
	{
		leaf<int> toInsert;
		toInsert.setKey(i);
		toInsert.setValue((char)((int)'a' + i));
		toTest.insert(toInsert);
	}
	for (int i = 0; i > -20; i-=2) // Negative evens
	{
		leaf<int> toInsert;
		toInsert.setKey(i);
		toInsert.setValue((char)((int)'a' + i));
		toTest.insert(toInsert);
	}
	for (int i = -1; i > -19; i-=2) // Negative odds
	{
		leaf<int> toInsert;
		toInsert.setKey(i);
		toInsert.setValue((char)((int)'a' + i));
		toTest.insert(toInsert);
	}
	toTest.writeKeys();

	// Clear test
	cout << "\nClear test..." << endl;
	toTest.clear();
	toTest.writeKeys();
	toTest.showStructure();

	// Refill
	cout << "\nRefilling..." << endl;
	for (int i = 0; i < 20; i+=2) // Evens
	{
		leaf<int> toInsert;
		toInsert.setKey(i);
		toInsert.setValue((char)((int)'a' + i));
		toTest.insert(toInsert);
	}
	for (int i = 1; i < 19; i+=2) // Odds
	{
		leaf<int> toInsert;
		toInsert.setKey(i);
		toInsert.setValue((char)((int)'a' + i));
		toTest.insert(toInsert);
	}
	for (int i = 0; i > -20; i-=2) // Negative evens
	{
		leaf<int> toInsert;
		toInsert.setKey(i);
		toInsert.setValue((char)((int)'a' + i));
		toTest.insert(toInsert);
	}
	for (int i = -1; i > -19; i-=2) // Negative odds
	{
		leaf<int> toInsert;
		toInsert.setKey(i);
		toInsert.setValue((char)((int)'a' + i));
		toTest.insert(toInsert);
	}
	toTest.showStructure();

	// Retrieve Test
	leaf<int> t1; // 5
	leaf<int> t2; // 0
	leaf<int> t3; // -5

	cout << "\nRetrieve test (5, 0, -5)..." << endl;
	toTest.retrieve(5, t1);
	toTest.retrieve(0, t2);
	toTest.retrieve(-5, t3);

	cout << "Test 1 | Key: " << t1.getKey() << " | Value: " << t1.getValue() << endl;
	cout << "Test 2 | Key: " << t2.getKey() << " | Value: " << t2.getValue() << endl;
	cout << "Test 3 | Key: " << t3.getKey() << " | Value: " << t3.getValue() << endl;

	// Delete Test
	cout << "\nDelete test (18, 15, 0)..." << endl;
	toTest.remove(18);
	toTest.remove(15);
	toTest.remove(0);
	toTest.showStructure();

	return 0;
}