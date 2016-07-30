#include <iostream>

#include "List.hpp"

// Default Constructor
// Private and unused
template<class T>
List<T>::List ()
{
	
}

// Constructor
// Creates an empty list with a number of elements
// equal to the number passed in.
// Can throw a bad_alloc exception
template<class T>
List<T>::List ( int maxNumber ) throw ( bad_alloc ) : size ( maxNumber )
{
	try
	{
		list = new DataType<T>[maxNumber];
	}
	catch (bad_alloc m)
	{
		throw m;
	}
}

// Destructor
// Frees the memory used to store the list
template<class T>
List<T>::~List ()
{
	delete[] list;
}

// Insert
// Inserts newDataItem in its appropriate position within a list.
// If a data item with the same key as newDataItem already exists
// in the list, then updates that data item's nonkey fields with
// newDataItem's nonkey fields. Moves the cursor to mark newDataItem.
template<class T>
void List<T>::insert ( const DataType<T> &newDataItem ) throw ( logic_error )
{
	int goodpos = 0;
	
	// If full, spit out an error
	if (isFull())
	{
		logic_error err ("List is full...");
		throw err;
	}
	
	// Find the appropriate position
	if (activeItems > 0)
	{
		bool foundItem = false;
		bool replaceItem = false;

		for (int i = 0; i < activeItems; i++)
		{
			// Check if we are less than the item we are at
			if (list[i].GetKey() > newDataItem.GetKey())
			{
				DataType<T> temp;
				DataType<T> trans;

				foundItem = true;
				
				// Shift all the items up one
				for (int j = i; j < activeItems+1; j++)
				{
					if (i != j)
					{
						trans.SetDataItem(list[j]);
						list[j].SetDataItem(temp);
						temp.SetDataItem(trans);
					}
					else
					{
						temp.SetDataItem(list[j]);
						list[j].SetDataItem(newDataItem);
					}
				}
			}
			else if (list[i].GetKey() == newDataItem.GetKey())
			{
				list[i].SetValue(newDataItem.GetValue());
				replaceItem = true;
				break;
			}
		}

		if (!foundItem && !replaceItem)
		{
			list[activeItems].SetDataItem(newDataItem);
		}

		if (!replaceItem) { ++activeItems; }
	}
	else
	{
		list[goodpos].SetDataItem(newDataItem);
		++activeItems;
	}
	
	if ((activeItems == 1) && (cursor != (unsigned char)0))
	{
		cursor = (unsigned char)0;
	}
	else
	{
		cursor = (char)goodpos;
	}
}

// Retrieve
// Searches a list for the data item with key searchKey. If the data item
// is found, then moves the cursor to the data item, copies it to searchDataItem,
// and returns true. Otherwise, returns false without moving the cursor and
// with searchDataItem undefined.
template<class T>
bool List<T>::retrieve (char searchKey, DataType<T> &searchDataItem)
{
	bool foundObject = false;
	int position = 0;
	
	// Binary search
	// i - Lesser bound
	// j - greater bound
	// m - center point
	for (int i = 0, j = activeItems, m = j/2; !((i == j) || foundObject);)
	{
		cout << "From " << list[i].GetKey() << " to " << list[j].GetKey() << endl;

		if (list[i].GetKey() == searchKey)
		{
			foundObject = true;
			position = i;
		}
		else if (list[j].GetKey() == searchKey)
		{
			foundObject = true;
			position = j;
		}
		else if (list[m].GetKey() == searchKey)
		{
			foundObject = true;
			position = m;
		}
		else if (list[m].GetKey() > searchKey) // searchKey is smaller
		{
			j = m;
			m = i + ((j-i)/2);
		}
		else // searchKey is larger
		{
			i = m;
			m = i + ((j-i)/2);
		}
	}
	
	// Reaction if object is found
	if (foundObject)
	{
		searchDataItem.SetDataItem(list[position]);
		cursor = position;
		return true;
	}
	else
	{
		return false;
	}
}

// Remove
// Removes the data item marked by the cursor from a list. If the resulting
// list is not empty, then moves the cursor to the data item that followed
// the deleted data item. If the deleted data item was at the end of the list,
// then moves the cursor to the beginning of the list.
template<class T>
void List<T>::remove () throw ( logic_error )
{
	if (activeItems <= 0)
	{
		throw logic_error("List empty");
	}

	--activeItems;

	for (int i = cursor; i < activeItems; i++)
	{
		list[i].SetDataItem(list[i+1]);
	}
}

// Replace
// Replaces the data item marked by the cursor with newDataItem. Note that
// this entails removing the data item and inserting newDataItem. Moves
// the cursor to newDataItem.
template<class T>
void List<T>::replace ( const DataType<T> &newDataItem ) throw ( logic_error )
{
	if (activeItems <= 0)
	{
		throw logic_error("List empty");
	}

	remove();
	insert(newDataItem);
}

// Clear
// Removes all the data items in a list.
template<class T>
void List<T>::clear ()
{
	cursor = 0;
	activeItems = 0;
}

// IsEmpty
// Returns true if a list is empty. Otherwise, returns false.
template<class T>
bool List<T>::isEmpty () const
{
	return activeItems <= 0;
}

// IsFull
// Returns true if a list is full. Otherwise, returns false.
template<class T>
bool List<T>::isFull () const
{
	return activeItems >= size;
}

// GotoBeginning
// Moves the cursor to the data item at the beginning of the list.
template<class T>
void List<T>::gotoBeginning () throw ( logic_error )
{
	cursor = (unsigned char)0;
}

// GotoEnd
// Moves the cursor to the data item at the end of the list.
template<class T>
void List<T>::gotoEnd () throw ( logic_error )
{
	cursor = (unsigned char)(activeItems - 1);
}

// GotoNext
// If the cursor is not at the end of the list, then moves the cursor to the
// next data item in the list and returns true. Otherwise, returns false.
template<class T>
bool List<T>::gotoNext () throw ( logic_error )
{
	if (cursor > activeItems)
	{
		++cursor;
	}
	else
	{
		throw logic_error("Attempting to go beyond bounds of current elements.");
	}
}

// GoToPrior
// If the cursor is not at the beginning of the list, then moves the cursor
// to the preceding data item in the list and returns true. Otherwise, returns
// false.
template<class T>
bool List<T>::gotoPrior () throw ( logic_error )
{
	if (cursor > 0)
	{
		--cursor;
	}
	else
	{
		throw logic_error("Attempting to move cursor to a position less than 0.");
	}
}

// GetCursor
// Gets a copy of the data item marked by the cursor.
template<class T>
DataType<T> List<T>::getCursor () const throw ( logic_error )
{
	if (activeItems <= 0)
	{
		throw logic_error("No elements exist.");
	}
	else if (cursor > (activeItems - 1))
	{
		cursor = (unsigned char)0;
		throw logic_error("Cursor is beyond exsisting elements. Cursor position changed to 0.");
	}
}

// ShowStructure
// Outputs the keys of the data items in a list. If the list is empty, outputs
// "Empty list". Note that this opteration is intended for testing/debug purposes
// only. It only supports keys that are of C++'s predefined data types
// (int, char, and so forth)
template<class T>
void List<T>::showStructure () const
{
	if (activeItems == 0)
	{
		cout << "Empty list" << endl;
	}
	else
	{
		for (int i = 0; i < activeItems; i++)
		{
			cout << "Item " << i << "\n\tKey: " << list[i].GetKey() << "\n\tValue: " << list[i].GetValue() << endl;
		}
	}
	
	cout << endl;
}