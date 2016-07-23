// Lab 6 Assignemnt
// Data Structures and Algorithms
// Written by Anthony Parsch
// Compiled and tested on Ubuntu Linux

#include <iostream>

#include "Queue.hpp"

using namespace std;

int main ()
{
	Queue<int> toTest (10);

	// Enqueue test
	cout << "Testing insert:" << endl;
	for (int i = 0; i < 10; i++)
	{
		toTest.enqueue(i*2+1);
	}
	toTest.showStructure();

	// Enqueue error test
	cout << "\nTesting insert error catching:" << endl;
	try
	{
		toTest.enqueue(3900); // OOPS
	}
	catch (logic_error le)
	{
		cout << "The error happened properly..." << endl;
	}

	// Dequeue test
	cout << "\nTesting dequeue (should be 1): " << toTest.dequeue() << endl;
	toTest.showStructure();

	// Clear test
	cout << "\nTesting clear:" << endl;
	toTest.clear();
	toTest.showStructure();

	// Dequeue error test
	cout << "\nTesting dequeue error catching:" << endl;
	try
	{
		toTest.dequeue();
	}
	catch (logic_error le)
	{
		cout << "The error happend properly..." << endl;
	}

	return 0;
}