#ifndef PARSCH_LIST_HEADER
#define PARSCH_LIST_HEADER

#include <exception>
#include <new>
#include <stdexcept>
#include <stddef.h>

using namespace std;

// This class represents a single item in 
// within a List.
template<class T>
struct DataType
{
	private:
		unsigned char key;
		T value;
	
	protected:
	
	public:
		// Getters and Setters
		void SetKey(char newKey) { key = newKey; }
		const char GetKey() const { return key; }
		
		void SetValue(T newValue) { value = newValue; }
		const T GetValue() const { return value; }
		
		void SetDataItem(const DataType<T> &inItem)
		{
			SetKey(inItem.GetKey());
			SetValue(inItem.GetValue());
		}
};

// The main list class
template<class T>
class List
{
	private:
		static const unsigned short int defMaxListSize = 256; // Max size that characters can allow
		DataType<T>* list = NULL; // The pointer to our array
		unsigned short int size; // The size that we create our list
		unsigned short int activeItems = 0;
		unsigned char cursor = (unsigned char)0;
		List();
		
	protected:
	
	public:
		// Constructor
		// Creates an empty list with a number of elements
		// equal to the number passed in.
		// Can throw a bad_alloc exception
		List ( int maxNumber = defMaxListSize ) throw ( bad_alloc );
		
		// Destructor
		// Frees the memory used to store the list
		~List ();
		
		// Insert
		// Inserts newDataItem in its appropriate position within a list.
		// If a data item with the same key as newDataItem already exists
		// in the list, then updates that data item's nonkey fields with
		// newDataItem's nonkey fields. Moves the cursor to mark newDataItem.
		void insert ( const DataType<T> &newDataItem ) throw ( logic_error );
		
		// Retrieve
		// Searches a list for the data item with key searchKey. If the data item
		// is found, then moves the cursor to the data item, copies it to searchDataItem,
		// and returns true. Otherwise, returns false without moving the cursor and
		// with searchDataItem undefined.
		bool retrieve (char searchKey, DataType<T> &searchDataItem);
		
		// Remove
		// Removes the data item marked by the cursor from a list. If the resulting
		// list is not empty, then moves the cursor to the data item that followed
		// the deleted data item. If the deleted data item was at the end of the list,
		// then moves the cursor to the beginning of the list.
		void remove () throw ( logic_error );
		
		// Replace
		// Replaces the data item marked by the cursor with newDataItem. Note that
		// this entails removing the data item and inserting newDataItem. Moves
		// the cursor to newDataItem.
		void replace ( const DataType<T> &newDataItem ) throw ( logic_error );
		
		// Clear
		// Removes all the data items in a list.
		void clear ();
		
		// IsEmpty
		// Returns true if a list is empty. Otherwise, returns false.
		bool isEmpty () const;
		
		// IsFull
		// Returns true if a list is full. Otherwise, returns false.
		bool isFull () const;
		
		// GotoBeginning
		// Moves the cursor to the data item at the beginning of the list.
		void gotoBeginning () throw ( logic_error );
		
		// GotoEnd
		// Moves the cursor to the data item at the end of the list.
		void gotoEnd () throw ( logic_error );
		
		// GotoNext
		// If the cursor is not at the end of the list, then moves the cursor to the
		// next data item in the list and returns true. Otherwise, returns false.
		bool gotoNext () throw ( logic_error );
		
		// GoToPrior
		// If the cursor is not at the beginning of the list, then moves the cursor
		// to the preceding data item in the list and returns true. Otherwise, returns
		// false.
		bool gotoPrior () throw ( logic_error );
		
		// GetCursor
		// Gets a copy of the data item marked by the cursor.
		DataType<T> getCursor () const throw ( logic_error );
		
		// ShowStructure
		// Outputs the keys of the data items in a list. If the list is empty, outputs
		// "Empty list". Note that this opteration is intended for testing/debug purposes
		// only. It only supports keys that are of C++'s predefined data types
		// (int, char, and so forth)
		void showStructure () const;
};

#include "List.tpp"

#endif // PARSCH_LIST_HEADER