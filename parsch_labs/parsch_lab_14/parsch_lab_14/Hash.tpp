#ifndef HASH_SOURCE
#define HASH_SOURCE

#include "Hash.hpp"

template <class DT>
Hash<DT>::Hash()
{

}

// HashTbl()
// Constuctor. Creates the empty hash table.
template <class DT>
Hash<DT>::Hash(int(*hash_function)(DT toHash), int initTableSize) throw (bad_alloc) 
	: tableSize(initTableSize)
{
	hash_func = hash_function;
	table = new forward_list<DT>[initTableSize]();
}

// ~HashTbl()
// Deconstructor. Deallocates (frees) the memory used to store a list.
template <class DT>
Hash<DT>::~Hash()
{
	clear();
}

// insert()
// Inserts newDataItem into the appropriate list. If a data item with the same key
// as newDataItem already exists in the list, then updates that data item's nonkey
// fields with newDataItem's nonkey fields. Otherwise, it inserts
template <class DT>
void Hash<DT>::insert(const DT &newDataItem) throw (bad_alloc)
{
	table[hash_func(newDataItem)].push_front(newDataItem);
}

// remove()
// Searches the hash table for the data item with key searchKey. If the data item is
// found, then removes the data item and returns true. Otherwise, returns false.
template <class DT>
bool Hash<DT>::remove(int searchKey)
{
	if ((searchKey < tableSize) && !table[searchKey].empty())
	{
		table[searchKey].pop_front();
		return true;
	}

	return false;
}

// retrieve()
// Searches the hash table for the data item with key searchKey. If the data item is
// found, then removes the data item and returns true. Otherwise, returns false.
template <class DT>
bool Hash<DT>::retrieve(int searchKey, DT &dataItem)
{
	if ((searchKey < tableSize) && !table[searchKey].empty())
	{
		dataItem = table[searchKey].front();
		table[searchKey].pop_front();
		return true;
	}

	return false;
}

// clear()
// Removes all data items in the hash table
template <class DT>
void Hash<DT>::clear()
{
	for (int i = 0; i < tableSize; i++)
	{
		table[i].clear();
	}
}

// isEmpty()
// Returns true if a hash table is empty. Otherwise, returns false.
template <class DT>
bool Hash<DT>::isEmpty() const
{
	for (int i = 0; i < tableSize; i++)
	{
		if (!table[i].empty()) { return false; }
	}

	return true;
}

// isFull()
// Returns true if a hash table is full. Otherwise, returns false.
// A Hash is considered full if there is at least one element in each of the forward_lists.
template <class DT>
bool Hash<DT>::isFull() const
{
	for (int i = 0; i < tableSize; i++)
	{
		if (table[i].empty()) { return false; }
	}

	return true;
}

// showStructure()
// Outputs the data items in a hash table. If the hash table is empty, outputs "Empty hash
// table". Note that this operation is intended for testing/debugging purposes only. It
// supports only list data items that are one of C++'s predefined data types (int, char, and
// so forth)
template <class DT>
void Hash<DT>::showStructure() const
{
	if (isEmpty())
	{ 
		cout << "Empty hash table" << endl; 
	}
	else
	{
		for (int i = 0; i < tableSize; i++) // Our array
		{
			if (!table[i].empty()) { for (DT& x : table[i]) { cout << x << " "; } }

			cout << endl;
		}
	}
}

#endif // !HASH_SOURCE