#include <stddef.h>

#include <iostream>
using namespace std;

// Default constructor
template <class T>
DoublyLinkedList<T>::DoublyLinkedList() : first(NULL), last(NULL), current(NULL), _length(0)
{

}

// Constructor
// Create a DoublyLinkedList with a initial key with the value given
template <class T>
DoublyLinkedList<T>::DoublyLinkedList(T firstValue) : first(NULL), last(NULL), current(NULL), _length(0)
{
	insert(firstValue);
}

// Destructor
template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	current = first;
	DoublyNode<T>* toDelete;

	while (current)
	{
		toDelete = current;
		current = current->next;

		toDelete->next = NULL;
		toDelete->previous = NULL;
		delete toDelete;
	}
}

// Find
// Find the DoublyNode where the key == dataToFind
// This will rely upon the == operator
template <class T>
DoublyNode<T>* DoublyLinkedList<T>::Find(T dataToFind)
{
	DoublyNode<T>* toReturn = first;

	while ((toReturn != last) && (toReturn->key != dataToFind))
	{
		toReturn = toReturn->next;
	}

	return toReturn;
}

// Sort
// Sorts the entire list using a merge sort and the compare function
// provided. The compare function should return:
// 1 - item1 goes before item2 [i1, i2]
// 0 - item1 is equal to item2
// -1 - item1 goes after item2 [i2, i1]
template <class T>
void DoublyLinkedList<T>::Sort(int (*Compare) (T item1, T item2))
{
	if ((_length > 1) && first && last)
	{
		T* array = new T[_length];
		DoublyNode<T>* curr_node = first;

		// Copy our values into an array
		for (int i = 0; i < _length; i++)
		{
			array[i] = curr_node->key;
			curr_node = curr_node->next;
		}

		// Run our actual sort
		InnerSort(Compare, array, _length);
		curr_node = first;

		// Move our values back into our linked list
		for (int i = 0; i < _length; i++)
		{
			curr_node->key = array[i];
			curr_node = curr_node->next;
		}

		delete[] array;
	}
}

// InnerSort
// The actual recursive merge sort of Sort.
template <class T>
T* DoublyLinkedList<T>::InnerSort(int (*Compare) (T item1, T item2), T* outerArray, int size)
{
	if (size > 1)
	{
		// Determine the sizes that we will need;
		unsigned int array1Size = size / 2;
		unsigned int array2Size = size - array1Size;
		
		// Create the arrays needed to be split down the line
		T* array1 = new T[array1Size];
		T* array2 = new T[array2Size];
		
		// Ensure that our smaller arrays contain the data needed
		for (int i = 0; i < size; i++)
		{
			if (i < array1Size)
			{
				array1[i] = outerArray[i];
			}
			else
			{
				array2[i-array1Size] = outerArray[i];
			}
		}
		
		// Ensure that the arrays below are sorted
		InnerSort(Compare, array1, array1Size);
		InnerSort(Compare, array2, array2Size);
		
		// Add them back into the outerArray
		for (int i = 0, a1pos = 0, a2pos = 0; i < size; i++)
		{
			// When we haven't reached any ends
			if ((a1pos < array1Size) && (a2pos < array2Size))
			{
				// Check who goes first
				int result = Compare(array1[a1pos], array2[a2pos]);
				
				switch (result)
				{
					case 0:
						outerArray[i] = array1[a1pos];
						++a1pos;
						break;
					
					case 1:
						outerArray[i] = array1[a1pos];
						++a1pos;
						break;
						
					case -1:
						outerArray[i] = array2[a2pos];
						++a2pos;
						break;
				}
			}
			// If array1 still has elements, but array2 doesn't
			else if ((a1pos < array1Size) && (a2pos >= array2Size))
			{
				outerArray[i] = array1[a1pos];
				++a1pos;
			}
			// If array2 still has elements, but array1 doesn't
			else if ((a1pos >= array1Size) && (a2pos < array2Size))
			{
				outerArray[i] = array2[a2pos];
				++a2pos;
			}
		}
		
		// Preform cleanup and return
		delete[] array1;
		delete[] array2;
		return outerArray;
	}
	else // Return when we have less than or equal to 1
	{
		return outerArray;
	}
}

// Insert
// Inserts the new key value into a DoublyNode
// at the position given, starting from 0. If a
// negative value is passed, the value is placed
// at the end of the DoublyLinkedList. Uses the
// = operator.
// Returns whether the operation was successful.
template <class T>
bool DoublyLinkedList<T>::Insert(T newData, int position)
{
	// Ensure that we are not beyond our length
	if (position >= _length) return false;

	// Create the new node
	DoublyNode<T>* tmp = new DoublyNode<T>();
	tmp->next = NULL;
	tmp->previous = NULL;
	tmp->key = newData;

	// Add the new node to the linked list
	if ((first == NULL) && (last == NULL))
	{
		// We are now the current, first, and last...
		current = tmp;
		first = tmp;
		last = tmp;
	}
	else if (position < 0)
	{
		// We are now the last
		tmp->previous = last;
		last->next = tmp;
		last = tmp;
	}
	else if (position == 0)
	{
		// We are now the first
		tmp->next = first;
		first->previous = tmp;
		first = tmp;
	}
	else
	{
		DoublyNode<T>* toTake;

		// Make sure that we start from the right end
		if (position < (_length / 2))
		{
			toTake = first;

			// Find our toTake
			for (int i = 0; i < position; i++)
			{
				toTake = toTake->next;
			}
		}
		else
		{
			toTake = last;

			// Find our toTake
			for (int i = (_length - 1); i > position; i--)
			{
				toTake = toTake->previous;
			}
		}

		// Set up our past
		tmp->previous = toTake->previous;
		toTake->previous = tmp;

		// Set up out next
		tmp->next = toTake;
	}

	++_length;

	return true;
}

// Delete
// Removes the DoublyNode at the given pointer.
// Returns wether the operation was successful.
template <class T>
bool DoublyLinkedList<T>::Delete(DoublyNode<T>* toDelete)
{
	// Check that we have values to delete
	if ( !(first && last) ) return false;
	else if (!toDelete) return false;

	// If we have the same first and last, there is only one value
	if (first == last)
	{
		delete current;
		current = NULL;
		first = NULL;
		last = NULL;
		_length = 0;
	}
	else
	{
		// If toDelete is a thing, clear it out
		if (toDelete)
		{
			toDelete->previous->next = toDelete->next;
			toDelete->next->previous = toDelete->previous;

			// Ensure that first and last are set properly
			if (first == toDelete) first = toDelete->next;
			if (last == toDelete) last = toDelete->previous;

			toDelete->previous = NULL;
			toDelete->next = NULL;
			delete toDelete;
			_length -= 1;
		}
	}

	return true;
}

// MoveForward
// Move along the DoublyLinkedList in a forward
// direction a number of positions given. Returns
// the new current node.
template <class T>
DoublyNode<T>* DoublyLinkedList<T>::MoveForward(int numToMove)
{
	for (int i = 0; (i < numToMove) && (current != last); i++)
	{
		if (current->next)
		{
			current = current->next;
		}
		else
		{
			return current;
		}
	}

	return current;
}

// MoveBackward
// Move along the DoublyLinkedList in a backward
// direction a number of positions given. Returns
// the new current node.
template <class T>
DoublyNode<T>* DoublyLinkedList<T>::MoveBackward(int numToMove)
{
	for (int i = 0; (i < numToMove) && (current != first); i--)
	{
		if (current->previous)
		{
			current = current->previous;
		}
		else
		{
			return current;
		}
	}

	return current;
}

// Length
// Returns the number of nodes in the list
template <class T>
int DoublyLinkedList<T>::Length()
{
	return _length;
}

// Minimum
// Returns the minimum key value. Uses the < operator.
template <class T>
T DoublyLinkedList<T>::Minimum()
{
	T toReturn = first->key;

	for (DoublyNode<T>* i = first; i != last; )
	{
		toReturn  = (i->key < toReturn) ? i->key : toReturn;
		i = i->next;
	}

	return toReturn;
}

// Maximum
// Returns the maximum key value. Uses the < operator.
template <class T>
T DoublyLinkedList<T>::Maximum()
{
	T toReturn = first->key;

	for (DoublyNode<T>* i = first; i != last; )
	{
		toReturn  = (i->key > toReturn) ? i->key : toReturn;
		i = i->next;
	}

	return toReturn;
}

// GetCurrent
// Returns a pointer to the current DoublyNode.
template <class T>
DoublyNode<T>* DoublyLinkedList<T>::GetCurrent()
{
	return current;
}

template <class T>
DoublyNode<T>* DoublyLinkedList<T>::GetFirst()
{
	return first;
}

template <class T>
DoublyNode<T>* DoublyLinkedList<T>::GetLast()
{
	return last;
}

// operator++
// Moves the current position in the DoublyLinkedList
// in the forward direction by 1. Returns the new
// current pointer.
template <class T>
DoublyNode<T>* DoublyLinkedList<T>::operator++() // Prefix
{
	if (current->next) current = current->next;
	return current;
}

template <class T>
DoublyNode<T>* DoublyLinkedList<T>::operator++(int) // Postfix
{
	DoublyNode<T>* toReturn = current;
	++(*this);
	return toReturn;
}

// operator--
// Moves the current position in the DoublyLinkedList
// in the backward direction by 1. Returns the new
// current pointer.
template <class T>
DoublyNode<T>* DoublyLinkedList<T>::operator--() // Prefix
{
	if (current->previous) current = current->previous;
	return current;
}

template <class T>
DoublyNode<T>* DoublyLinkedList<T>::operator--(int) // Postfix
{
	DoublyNode<T>* toReturn = current;
	--(*this);
	return toReturn;
}

// operator[]
// Provides the key value at the position given.
// Starts from the first and may be a slow operation.
template <class T>
T& DoublyLinkedList<T>::operator[](unsigned int index)
{
	DoublyNode<T>* toStart;

	if (index < (_length/2))
	{
		toStart = first;
		for (int i = 0; i < index; i++)
		{
			toStart = toStart->next;
		}
	}
	else
	{
		toStart = last;
		for (int i = _length; i > (index+1); i--)
		{
			toStart = toStart->previous;
		}
	}

	return toStart->key;
}

template <class T>
const T DoublyLinkedList<T>::operator[](unsigned int index) const
{
	return (*this)[index];
}

// operator()
// Returns the key value at the current pointer's position.
template <class T>
T& DoublyLinkedList<T>::operator()()
{
	return current->key;
}

// operator==
// Returns whether the key values of the current pointers
// are equivilent to each other. Uses the == on the key
// values.
template <class T>
bool DoublyLinkedList<T>::operator==(const DoublyLinkedList<T> other)
{
	return (this->current->key == other.current->key);
}
