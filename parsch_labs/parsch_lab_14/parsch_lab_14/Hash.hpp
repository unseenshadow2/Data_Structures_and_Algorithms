#ifndef HASH_HEADER
#define HASH_HEADER

#include <forward_list>
#include <memory>

using namespace std;

template <class DT>
class Hash
{
public:
	// HashTbl()
	// Constuctor. Creates the empty hash table.
	Hash(int(*hash_function)(DT toHash), int initTableSize = 10) throw (bad_alloc);

	// ~HashTbl()
	// Deconstructor. Deallocates (frees) the memory used to store a list.
	~Hash();

	// insert()
	// Inserts newDataItem into the appropriate list. If a data item with the same key
	// as newDataItem already exists in the list, then updates that data item's nonkey
	// fields with newDataItem's nonkey fields. Otherwise, it inserts
	void insert(const DT &newDataItem) throw (bad_alloc);

	// remove()
	// Searches the hash table for the data item with key searchKey. If the data item is
	// found, then removes the data item and returns true. Otherwise, returns false.
	bool remove(int searchKey);

	// retrieve()
	// Searches the hash table for the data item with key searchKey. If the data item is
	// found, then removes the data item and returns true. Otherwise, returns false.
	bool retrieve(int searchKey, DT &dataItem);

	// clear()
	// Removes all data items in the hash table
	void clear();

	// isEmpty()
	// Returns true if a hash table is empty. Otherwise, returns false.
	bool isEmpty() const;

	// isFull()
	// Returns true if a hash table is full. Otherwise, returns false.
	// A Hash is considered full if there is at least one element in each of the forward_lists.
	bool isFull() const;

	// showStructure()
	// Outputs the data items in a hash table. If the hash table is empty, outputs "Empty hash
	// table". Note that this operation is intended for testing/debugging purposes only. It
	// supports only list data items that are one of C++'s predefined data types (int, char, and
	// so forth)
	void showStructure() const;

protected:
	forward_list<DT>* table;

private:
	int tableSize;
	int(*hash_func)(DT toHash);

	Hash();
};

#include "Hash.tpp"

#endif // HASH_HEADER