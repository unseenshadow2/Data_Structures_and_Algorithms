// Word Ladder Assignment (Shortest path algorithm)
// Data Structures and Algorithms
// Written by Anthony Parsch
// Compiled and tested on Windows 10
//		in Microsoft Visual Studio Community 2015

#include <iostream>
#include <string>

#include "WordLadder.h"

using namespace std;

void menu(WordLadder ladder);
size_t findBestPos(const string larger, const string smaller);
size_t resizingString(string& currentString, const string end);

// This function was retrieved from http://stackoverflow.com/questions/4654636/how-to-determine-if-a-string-is-a-number-with-c
bool is_number(const std::string& s);

int main()
{
	// Testing findBestPos()
	cout << "Testing findBestPos():" << endl;
	cout << "cat in Matt: " << findBestPos("Matt", "cat") << endl;
	cout << "cat in Matt cat: " << findBestPos("Matt cat", "cat") << endl;
	cout << "cat in typanicle: " << findBestPos("typanicle", "cat") << endl;

	// Testing resizingString()
	cout << "\nTesting resizingString():" << endl;
	string bigger = "ThisIsBiggerThanYou";
	string smaller = "IsSmaller";
	string bigger1 = "ThisIsAFullString";
	string smaller1 = "IsANot";
	int cost;

	cout << "Test one: " << bigger << " | " << smaller << endl;
	cost = resizingString(smaller, bigger);
	cout << smaller << " costs " << cost << endl;

	cout << "Test two: " << smaller1 << " | " << bigger1 << endl;
	cost = resizingString(bigger1, smaller1);
	cout << bigger1 << " costs " << cost << endl;

	// Testing WordLadder
	WordLadder ladder;
	menu(ladder);

	system("pause");
}

// menu()
// Run the menu for the assignment
void menu(WordLadder ladder)
{
	// Get the pice of adds and removes
	for (bool isGood = false; !isGood; )
	{
		string input;
		cout << "\n\nPlease input the price of an add or remove action: ";
		cin >> input;

		if (is_number(input))
		{
			isGood = true;
			ladder.setAddRemoveCost(atoi(input.c_str()));
		}
		else
		{
			cout << "ERROR: Please input a positive integer" << endl;
		}
	}

	// Run the actual menu
	for (bool isRunning = true; isRunning; )
	{
		string toChange;
		string endpoint;
		string input;
		int price;

		cout << "\n\nPlease input the word to change: ";
		cin >> toChange;
		cout << "Please input the word for the previous word to become: ";
		cin >> endpoint;

		price = ladder.calculateCost(toChange, endpoint);

		cout << "\nThe price to convert " << toChange << " to " << endpoint << " is " << price << endl;

		cout << "Would you like to do another conversion (y or n): ";
		cin >> input;

		if (!((input[0] == 'y') || (input[0] == 'Y'))) { isRunning = false; }
	}
}

// findBestPos()
// Finds the best starting position for making the word from.
size_t findBestPos(const string larger, const string smaller)
{
	size_t bestPos = 0;
	size_t bestMatchingChars = 0;

	for (int i = 0; i < (larger.size() - smaller.size() + 1); i++)
	{
		size_t matchingChars = 0;

		for (int j = 0; j < smaller.size(); j++) // Check the number of matching characters
		{
			if (larger[i + j] == smaller[j]) ++matchingChars;
		}

		if (matchingChars > bestMatchingChars) // We are the new best match
		{
			bestPos = i;
			bestMatchingChars = matchingChars;
		}
	}

	return bestPos;
}

// resizeString()
// Resize()s the current string to the size() of the end word.
// Returns the number of points used.
size_t resizingString(string& currentString, const string end)
{
	size_t toReturn;
	size_t position;
	size_t cost = 0;
	size_t addRemoveCost = 5;

	// If the size()s aren't the same, make them so.
	if (currentString.size() != end.size())
	{
		if (currentString.size() < end.size()) // When end is bigger
		{
			// Find our position in the bigger string
			position = findBestPos(end, currentString);

			// Add to the back
			for (int i = position + currentString.size() + 1; i < end.size(); i++)
			{
				currentString += end[i];
				cost += addRemoveCost;
			}

			// Add to the front
			for (int i = position; i >= 0; i--)
			{
				currentString = end[i] + currentString;
				cost += addRemoveCost;
			}
		}
		else // When current is bigger
		{
			position = findBestPos(currentString, end);

			cost = (currentString.size() - end.size()) * 5;

			currentString = currentString.substr(position, end.size());
		}
	}

	return cost;
}

// This function was retrieved from http://stackoverflow.com/questions/4654636/how-to-determine-if-a-string-is-a-number-with-c
bool is_number(const std::string& s)
{
	return(strspn(s.c_str(), "0123456789") == s.size());
}