// Lab 5 Assignemnt
// Data Structures and Algorithms
// Written by Anthony Parsch
// Compiled and tested on Ubuntu Linux

#include <iostream>

#include "Stack.hpp"

using namespace std;

int main ()
{
	Stack<int> toTest (10);

	// Empty test
	cout << "Is it empty? " << toTest.isEmpty() << endl;

	// Push test
	for (int i = 0; i < 10; i++)
	{
		toTest.push(i);
	}

	toTest.showStructure();

	// Can I get the error please
	cout << "\nTesting the error checking:" << endl;
	try
	{
		toTest.push(12);
	}
	catch (logic_error le)
	{
		cout << "We caught the error..." << endl;
	}

	// Clear list
	cout << "\nWe are clearing the list..." << endl;
	toTest.clear();
	if (toTest.isEmpty())
	{
		cout << "It cleared properly..." << endl;
	}
	toTest.showStructure();

	// Pop error test
	cout << "\nChecking if pop spits out an error..." << endl;
	try
	{
		toTest.pop();
	}
	catch (logic_error le)
	{
		cout << "We caught the error..." << endl;
	}

	return 0;
}