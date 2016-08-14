// Word Ladder Assignment (Shortest path algorithm)
// Data Structures and Algorithms
// Written by Anthony Parsch
// Compiled and tested on Windows 10
//		in Microsoft Visual Studio Community 2015

#include <iostream>

#include "WordLadder.h"

using namespace std;

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
			cout << "Pos: " << i << " | Pos smaller: " << j << " | Pos total: " << i + j << " | Characters: " << larger[i + j] << " " << smaller[j] << endl;
		}

		if (matchingChars > bestMatchingChars) // We are the new best match
		{
			bestPos = i;
			bestMatchingChars = matchingChars;
		}
	}

	return bestPos;
}

int main()
{
	cout << "cat in Matt: " << findBestPos("Matt", "cat") << endl;
	cout << "cat in Matt cat: " << findBestPos("Matt cat", "cat") << endl;
	cout << "cat in typanicle: " << findBestPos("typanicle", "cat") << endl;

	system("pause");
}