#pragma once
#include <iostream>

using namespace std;

// WordLadder
// Calculates out a best path cost for transforming one word
// into another.
class WordLadder
{
public:
	// Constructors

	// WordLadder()
	// Constructor. Assigns the costs of the WordLadder.
	WordLadder(unsigned int subCost=1, unsigned int addRemCost=5);

	// Calculation Functions

	// calculateCost()
	// Calculates the best path from the word in start to the word in end.
	// Returns the cost as an unsigned int.
	unsigned int calculateCost(const string start, const string end);
	unsigned int calculateCost(const char* start, const char* end);

	// Getters and Setters
	unsigned int getSubstitutionCost() { return substitutionCost; }
	unsigned int setSubstitutionCost(unsigned int subCost) { substitutionCost = subCost; return substitutionCost; }

	unsigned int getAddRemoveCost() { return addRemoveCost; }
	unsigned int setAddRemoveCost(unsigned int addRemCost) { addRemoveCost = addRemCost; return addRemoveCost; }

protected:
	// resize()String()
	// Resize()s the current string to the size() of the end word.
	// Returns the number of points used.
	size_t resizingString(string& currentString, const string end);

	// findBestPos()
	// Finds the best starting position for making the word from.
	size_t findBestPos(const string larger, const string smaller);

private:
	unsigned int substitutionCost;
	unsigned int addRemoveCost;
};