// Lab 12 Assignemnt
// Data Structures and Algorithms
// Written by Anthony Parsch
// Compiled and tested on Windows 10
//		in Microsoft Visual Studio Community 2015

#include <iostream>

#include "ExprTree.hpp"

using namespace std;

int main()
{
	ExprTree tree;

	// Test showStructure()
	cout << "Testing showStructure:" << endl;
	tree.showStructure();
	cout << endl;

	// Test build()
	try
	{
		cout << "Testing build:" << endl;
		tree.build();
		tree.showStructure();
		cout << endl;
	}
	catch (bad_alloc ba)
	{
		cout << "Bad build..." << endl;
	}

	// Test expression()
	cout << "Testing expression:" << endl;
	tree.expression();
	cout << endl;

	// Test evaluate()
	cout << "Testing expression:" << endl;
	printf("Evaluated value: %.2f\n", tree.evaluate());
	cout << endl;

	// Test clear()
	cout << "Testing clear:" << endl;
	tree.clear();
	tree.showStructure();
	cout << endl;

	system("pause");

	return 0;
}