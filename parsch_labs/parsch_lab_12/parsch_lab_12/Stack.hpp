#ifndef PARSCH_STACK_H
#define PARSCH_STACK_H
#define MAX_SIZE 2000

#include <exception>
#include <new>
#include <stdexcept>
#include <stddef.h>

using namespace std;

// The objects for a non-array based stack
template<class DT>
struct stack_object
{
	stack_object<DT>* previous = NULL;
	DT value;
};

template<class DT>
class Stack
{
private:
	stack_object<DT>* top = NULL;
	int size;
	int max_size;
	static const int defMaxStackSize = MAX_SIZE;

protected:

public:
	// Constructor. Creates an empty stack.
	Stack ( int maxNumber = defMaxStackSize ) throw ( bad_alloc );

	// Destructor. Deallocates (frees) the memory used to store a stack.
	~Stack ();

	// Inserts newDataItem onto the top of the stack.
	// Throws when stack is full.
	void push ( const DT &newDataItem ) throw ( logic_error );

	// Removes the most recently added (top) data item from the stack and
	// returns it.
	// Throws when stack is empty.
	DT pop () throw ( logic_error );

	// Removes all the data items in a stack.
	void clear ();

	// Returns true if the stack is empty. Otherwise, returns false.
	bool isEmpty () const;

	// Returns true if the stack is full. Otherwise, returns false.
	bool isFull () const;

	// Outputs the data items in the stack. If the stack is empty, outputs "Empty stack".
	// Note that this operation is intended for testing/debugging purposes only. It
	// only supports stack data items that are one of C++'s predefined data types (int,
	// char, and so forth).
	void showStructure () const;
};

#include "Stack.tpp"

#endif // PARSCH_STACK_H