#ifndef PARSCH_STACK_TPP
#define PARSCH_STACK_TPP

#include <iostream>

#include "Stack.hpp"

using namespace std;

template<class DT>
Stack<DT>::Stack () {}

// Constructor. Creates an empty stack.
template<class DT>
Stack<DT>::Stack ( int maxNumber ) throw ( bad_alloc ) : max_size (maxNumber), size (0)
{

}

// Destructor. Deallocates (frees) the memory used to store a stack.
template<class DT>
Stack<DT>::~Stack ()
{
	clear();
}

// Inserts newDataItem onto the top of the stack.
// Throws when stack is full.
template<class DT>
void Stack<DT>::push ( const DT &newDataItem ) throw ( logic_error )
{
	if (isFull()) { throw logic_error ( "Stack is full." ); }

	stack_object<DT>* newObject = new stack_object<DT>;
	newObject->value = newDataItem;
	newObject->previous = top;
	top = newObject;

	size++;
}

// Removes the most recently added (top) data item from the stack and
// returns it.
// Throws when stack is empty.
template<class DT>
DT Stack<DT>::pop () throw ( logic_error )
{
	if (isEmpty()) { throw logic_error("Stack is empty..."); }

	stack_object<DT>* current;
	DT toReturn;

	current = top;
	top = current->previous;
	current->previous = NULL;
	toReturn = current->value; // Get our return value
	delete current;

	size--;

	return toReturn;
}

// Removes all the data items in a stack.
template<class DT>
void Stack<DT>::clear ()
{
	while (top != NULL)
	{
		pop();
	}
}

// Returns true if the stack is empty. Otherwise, returns false.
template<class DT>
bool Stack<DT>::isEmpty () const
{
	return size <= 0;
}

// Returns true if the stack is full. Otherwise, returns false.
template<class DT>
bool Stack<DT>::isFull () const
{
	return size >= max_size;
}

// Outputs the data items in the stack. If the stack is empty, outputs "Empty stack".
// Note that this operation is intended for testing/debugging purposes only. It
// only supports stack data items that are one of C++'s predefined data types (int,
// char, and so forth).
template<class DT>
void Stack<DT>::showStructure () const
{
	if (isEmpty())
	{
		cout << "Empty stack" << endl;
	}
	else
	{
		stack_object<DT>* current = top;

		cout << "Top: ";
		while (current != NULL)
		{
			cout << current->value << endl;
			current = current->previous;
		}
	}
}

#endif // PARSCH_STACK_TPP