#include "WordLadder.h"

// Constructors

// WordLadder()
// Constructor. Assigns the costs of the WordLadder.
WordLadder::WordLadder(unsigned int subCost, unsigned int addRemCost) 
	: substitutionCost(subCost), addRemoveCost(addRemCost)
{

}

// Calculation Functions

// calculateCost()
// Calculates the best path from the word in start to the word in end.
// Returns the cost as an unsigned int.
unsigned int WordLadder::calculateCost(const string start, const string end)
{
	string currentString = start;
	unsigned int currentCost = 0;

	currentCost = resizingString(currentString, end);

	return currentCost;
}

unsigned int WordLadder::calculateCost(const char* start, const char* end)
{
	string strStart = start;
	string strEnd = end;

	return calculateCost(strStart, strEnd);
}

// resize()String()
// Resize()s the current string to the size() of the end word.
// Returns the number of points used.
size_t WordLadder::resizingString(string& currentString, const string end)
{
	size_t toReturn;
	size_t position;
	size_t cost = 0;

	// If the size()s aren't the same, make them so.
	if (currentString.size() != end.size())
	{
		if (currentString.size() < end.size()) // When end is bigger
		{
			position = findBestPos(end, currentString);
		}
		else
		{
			position = findBestPos(currentString, end);
		}
	}

	return cost;
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