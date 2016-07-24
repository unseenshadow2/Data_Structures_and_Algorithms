#ifndef PARSCH_QUEUE_TPP
#define PARSCH_QUEUE_TPP

#include <iostream>

#include "Queue.hpp"

template <class DT>
Queue<DT>::Queue ()
{

}

// Constructor. Creates an empty queue.
template <class DT>
Queue<DT>::Queue ( int maxNumber ) throw ( bad_alloc ) : max_size (maxNumber)
{

}

// Destructor. Deallocates (frees) the memory used to store a queue.
template <class DT>
Queue<DT>::~Queue ()
{
	clear();
}

// Inserts newDataItem at the rear of a queue.
template <class DT>
void Queue<DT>::enqueue ( const DT &newDataItem ) throw ( logic_error )
{
	if (isFull()) { throw logic_error("The list is full..."); }

	queue_element<DT>* element = new queue_element<DT>;
	element->value = newDataItem;

	if (isEmpty())
	{
		front = element;
		back = element;
	}
	else
	{
		back->next = element;
		back = element;
	}

	++size;
}

// Removes the least recently added (front) data item from the queue and returns it.
template <class DT>
DT Queue<DT>::dequeue () throw ( logic_error )
{
	if (isEmpty()) { throw logic_error("The list is empty..."); }

	DT toReturn = front->value;

	queue_element<DT>* toRemove = front;
	front = toRemove->next;
	toRemove->next = NULL;
	delete toRemove;

	--size;

	if (size <= 0)
	{
		front = NULL;
		back = NULL;
	}

	return toReturn;
}

// Removes all the data items in a queue.
template <class DT>
void Queue<DT>::clear ()
{
	while (!isEmpty())
	{
		dequeue();
	}
}

// Returns true if a queue is empty. Otherwise, returns false.
template <class DT>
bool Queue<DT>::isEmpty () const
{
	return size <= 0;
}

// Returns true if a queue is full. Otherwise, returns false.
template <class DT>
bool Queue<DT>::isFull () const
{
	return size >= max_size;
}

// Outputs the data items in a queue. If the queue is empty, outputs "Empty queue".
// Note that this operation is intended for testing/debugging purposes only. It only
// supports queue data items that are one of C++'s predefined data types (int, char,
// and so forth)
template <class DT>
void Queue<DT>::showStructure () const
{
	if (isEmpty())
	{
		cout << "Empty queue" << endl;
	}
	else
	{
		queue_element<DT>* current = front;

		cout << "\nFront:";

		while (current != NULL)
		{
			cout << current->value << endl;
			current = current->next;
		}
	}
}

#endif // PARSCH_QUEUE_TPP