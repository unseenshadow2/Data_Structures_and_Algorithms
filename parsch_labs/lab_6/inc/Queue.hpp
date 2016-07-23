#ifndef PARSCH_QUEUE_HPP
#define PARSCH_QUEUE_HPP
#define MAX_SIZE 2000

#include <exception>
#include <new>
#include <stdexcept>
#include <stddef.h>

using namespace std;

template <class DT>
struct queue_element
{
	queue_element<DT>* next = NULL;

	DT value;
};

template <class DT>
class Queue
{
private:
	static const int defMaxQueueSize = MAX_SIZE;
	queue_element<DT>* front = NULL;
	queue_element<DT>* back = NULL;

	int size = 0;
	int max_size;

	Queue();

protected:

public:
	// Constructor. Creates an empty queue.
	Queue ( int maxNumber = defMaxQueueSize ) throw ( bad_alloc );

	// Destructor. Deallocates (frees) the memory used to store a queue.
	~Queue ();
	
	// Inserts newDataItem at the rear of a queue.
	void enqueue ( const DT &newDataItem ) throw ( logic_error );

	// Removes the least recently added (front) data item from the queue and returns it.
	DT dequeue () throw ( logic_error );

	// Removes all the data items in a queue.
	void clear ();

	// Returns true if a queue is empty. Otherwise, returns false.
	bool isEmpty () const;

	// Returns true if a queue is full. Otherwise, returns false.
	bool isFull () const;

	// Outputs the data items in a queue. If the queue is empty, outputs "Empty queue".
	// Note that this operation is intended for testing/debugging purposes only. It only
	// supports queue data items that are one of C++'s predefined data types (int, char,
	// and so forth)
	void showStructure () const;
};

#include "Queue.tpp"

#endif // PARSCH_QUEUE_HPP