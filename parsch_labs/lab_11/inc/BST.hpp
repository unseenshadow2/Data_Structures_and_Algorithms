#ifndef PARSCH_BINARY_SEARCH_TREE_HPP
#define PARSCH_BINARY_SEARCH_TREE_HPP
#define MAX_SIZE 2000

#include <exception>
#include <new>
#include <stdexcept>
#include <stddef.h>

using namespace std;

// A single leaf on the BST
template <class DT>
struct leaf
{
private:
	DT key;
	char value;
	leaf<DT>* right = NULL; // higher
	leaf<DT>* left = NULL; // lower

public:
	DT getKey() const { return key; }
	void setKey(DT newKey) { key = newKey; }

	char getValue() const { return value; }
	void setValue(char newValue) { value = newValue; }

	leaf<DT>* getRight() const { return right; }
	void setRight(leaf<DT>* newRight) { right = newRight; }
	
	leaf<DT>* getLeft() const { return left; }
	void setLeft(leaf<DT>* newLeft) { left = newLeft; }
};

// A good old binary search tree
template <class DT>
class BSTree
{
private:
	leaf<DT>* top = NULL;

protected:
	// clearLeaf
	// Clears a leaf and deletes its branches. Recursive.
	void clearLeaf ( leaf<DT>* toClear );

	// writeLeaf
	// Writes a leaf and its branches. Recursive.
	void writeLeaf ( leaf<DT>* toWrite ) const;

	// showLeaf
	// Writes a leaf in a 90 degrees counterclockwise rotation. Recursive.
	void showLeaf ( leaf<DT>* toShow, int depth ) const;

public:
	// Constructor. Creates an empty binary search tree.
	BSTree();

	// Destructor. Deallocates (frees) the memory used to store a binary search tree.
	~BSTree();

	// insert
	// Inserts newDataItem into a binary search tree. If a data item with the same
	// key as newDataItem already exists in the tree, then updates that data item's
	// nonkey fields with newDataItem's nonkey fields.
	void insert ( const leaf<DT> &newDataItem ) throw ( bad_alloc );

	// retrieve
	// Searches a binary search tree for the data item with key searchKey. If this
	// data item is found, then copies the data item to searchDataItem and returns
	// true. Otherwise, returns false with searchDataItem undefined.
	bool retrieve (DT searchKey, leaf<DT> &searchDataItem);

	// remove
	// Deletes the data item with key deleteKey from a binary search tree. If this
	// data item is found, then deletes it from the tree and returns true. Otherwise,
	// returns false.
	bool remove ( DT deleteKey );

	// writeKeys
	// Outputs the keys of the data items in a binary search tree. The keys are output
	// in ascending order, one per line.
	void writeKeys () const;

	// clear
	// Removes all the data items in a binary search tree.
	void clear ();

	// isEmpty
	// Returns true if a binary serch tree is empty. Otherwise, returns false.
	bool isEmpty () const;

	// isFull
	// Returns true if a binary search tree is full. Otherwise, returns false.
	bool isFull () const;

	// showStructure
	// Outputs the keys in a binary search tree. The tree is output with its
	// branches oriented from left (root) to right (leaves); that is, the tree is
	// output rotated counterclockwise 90 degrees from its conventional orientation.
	// If the tree is empty, outputs "Empty tree". Note this operation is intended
	// for debugging purposes only.
	void showStructure () const;
};

#include "BST.tpp"

#endif // PARSCH_BINARY_SEARCH_TREE_HPP