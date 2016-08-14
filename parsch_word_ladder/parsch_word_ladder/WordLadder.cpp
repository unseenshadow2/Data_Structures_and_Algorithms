#include "WordLadder.h"
#include <cctype>
#include <algorithm>
#include <string>

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
	string endString = end;
	unsigned int currentCost = 0;

	// Make sure that everything is lowercase
	transform(currentString.begin(), currentString.end(), currentString.begin(), tolower);
	transform(endString.begin(), endString.end(), endString.begin(), tolower);

	// Resize so that we meet our end goal
	currentCost = resizingString(currentString, endString);

	// Calculate the remaining cost
	for (int i = 0; i < currentString.size(); i++)
	{
		if (currentString[i] != endString[i])
		{
			currentString[i] = endString[i];
			currentCost += substitutionCost;
		}
	}

	return currentCost;
}

unsigned int WordLadder::calculateCost(const char* start, const char* end)
{
	string strStart = start;
	string strEnd = end;

	return calculateCost(strStart, strEnd);
}

// resizeString()
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
			// Find our position in the bigger string
			position = findBestPos(end, currentString);

			// Add to the back
			for (int i = position + currentString.size() ; i < end.size(); i++)
			{
				currentString += end[i];
				cost += addRemoveCost;
			}

			// Add to the front
			for (int i = position; i > 0; i--)
			{
				currentString = end[i-1] + currentString;
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

// findBestPos()
// Finds the best starting position for making the word from.
size_t WordLadder::findBestPos(const string larger, const string smaller)
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