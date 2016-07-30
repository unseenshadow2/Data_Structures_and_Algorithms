// Lab 14 Assignemnt
// Data Structures and Algorithms
// Written by Anthony Parsch
// Compiled and tested on Windows 10
//		in Microsoft Visual Studio Community 2015

#include <iostream>
#include <iterator>
#include "Hash.hpp"

using namespace std;

int hasher(char value);
int hasher_two(int value);

int main()
{
	Hash<char> toTest (hasher, 10);

	// isEmpty() test
	cout << "\nisEmpty() Test" << endl;
	cout << "isEmpty(): " << toTest.isEmpty() << endl;
	cout << "isFull(): " << toTest.isFull() << endl;
	toTest.showStructure();

	// insert() test
	cout << "\ninsert() Test" << endl;

	for (char c = '0'; c <= 'z'; c++)
	{
		toTest.insert(c);
	}

	toTest.showStructure();

	// isFull() test
	cout << "\nisFull() Test" << endl;
	cout << "isEmpty(): " << toTest.isEmpty() << endl;
	cout << "isFull(): " << toTest.isFull() << endl;

	// remove() and retrieve() test
	cout << "\nremove() and retrieve() Test" << endl;
	char rtest = ' ';
	cout << "remove(3): " << toTest.remove(3) << endl;
	bool rreturn = toTest.retrieve(3, rtest);
	cout << "retrieve(3, rtest): " << rreturn << " | rtest = " << rtest << endl;
	toTest.showStructure();

	// clear() test
	cout << "\nclear() Test" << endl;
	toTest.clear();
	toTest.showStructure();

	// isEmpty() test
	cout << "\nisEmpty() Test" << endl;
	cout << "isEmpty(): " << toTest.isEmpty() << endl;
	cout << "isFull(): " << toTest.isFull() << endl;
	toTest.showStructure();

	// Int test version
	Hash<int> testTwo(hasher_two, 20);
	cout << "\n\nTesting with ints:" << endl;

	// insert() test
	cout << "\ninsert() Test" << endl;

	for (int i = 1; i <= 115; i++)
	{
		testTwo.insert(i);
	}

	testTwo.showStructure();

	// isFull() test
	cout << "\nisFull() Test" << endl;
	cout << "isEmpty(): " << testTwo.isEmpty() << endl;
	cout << "isFull(): " << testTwo.isFull() << endl;

	// remove() and retrieve() test
	cout << "\nremove() and retrieve() Test" << endl;
	cout << "remove(3): " << testTwo.remove(3) << endl;
	int itest;
	bool ireturn = testTwo.retrieve(3, itest);
	cout << "retrieve(3, rtest): " << ireturn << " | rtest = " << itest << endl;
	testTwo.showStructure();

	// clear() test
	cout << "\nclear() Test" << endl;
	testTwo.clear();
	testTwo.showStructure();

	system("pause");
}

int hasher(char value)
{
	return (int)value % 10;
}

int hasher_two(int value)
{
	return value % 20;
}