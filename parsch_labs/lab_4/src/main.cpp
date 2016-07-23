// Lab 4 Assignemnt
// Data Structures and Algorithms
// Written by Anthony Parsch
// Compiled and tested on Ubuntu Linux

#include <iostream>
#include "List.hpp"

using namespace std;

int main()
{
	List<int> toTest(10);

	// Fill our list with values
	for (int i = 0; i < 5; i++)
	{
		DataType<int> dt;
		dt.SetKey('a'+i);
		dt.SetValue(i);

		toTest.insert(dt);
	}
	toTest.showStructure();

	// Test insert replace
	DataType<int> dt;
	dt.SetKey('c');
	dt.SetValue(10);
	toTest.insert(dt);

	cout << "\nReplace test:\n" << endl;
	toTest.showStructure();

	// Remove test
	if (toTest.retrieve('d', dt))
	{
		cout << "\nValue of 'd' is " << dt.GetValue() << endl;
	}
	else
	{
		cout << "\nCould not find 'd'" << endl;
	}

	toTest.remove();
	cout << "Removing 'd'\n" << endl;
	toTest.showStructure();

	// Replace test
	if (toTest.retrieve('e', dt))
	{
		dt.SetValue(100);
		toTest.replace(dt);
		cout << "\nReplacing 'e':\n" << endl;
		toTest.showStructure();
	}
	else
	{
		cout << "\nCould not find 'e'\n" << endl;
	}

	// Inserting 'd'
	dt.SetKey('d');
	dt.SetValue(60);
	toTest.insert(dt);
	cout << "\nInserting 'c':\n" << endl;
	toTest.showStructure();

	return 0;
}