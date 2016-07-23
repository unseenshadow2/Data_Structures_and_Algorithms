#ifndef PARSCH_BINARY_SEARCH_TREE_TPP
#define PARSCH_BINARY_SEARCH_TREE_TPP

#include <exception>
#include <new>
#include <stdexcept>
#include <stddef.h>
#include <iostream>

#include "BST.hpp"
#include "Stack.hpp"

// Constructor. Creates an empty binary search tree.
template <class DT>
BSTree<DT>::BSTree()
{

}

// Destructor. Deallocates (frees) the memory used to store a binary search tree.
template <class DT>
BSTree<DT>::~BSTree()
{
	clear();
}

// clearLeaf
// Clears a leaf and deletes its branches. Recursive.
template <class DT>
void BSTree<DT>::clearLeaf ( leaf<DT>* toClear )
{
	if (toClear)
	{
		if (toClear->getRight()) { clearLeaf(toClear->getRight()); }
		if (toClear->getLeft()) { clearLeaf(toClear->getLeft()); }
		try { delete toClear; } catch (...) { cout << "We encountered an error while trying to clear a leaf..." << endl; }
	}
}

// writeLeaf
// Writes a leaf and its branches. Recursive.
template <class DT>
void BSTree<DT>::writeLeaf ( leaf<DT>* toWrite ) const
{
	if (toWrite)
	{
		if (toWrite->getLeft()) { writeLeaf(toWrite->getLeft()); }
		cout << toWrite->getKey() << endl;
		if (toWrite->getRight()) { writeLeaf(toWrite->getRight()); }
	}
}

// showLeaf
// Writes a leaf in a 90 degrees counterclockwise rotation. Recursive.
template <class DT>
void BSTree<DT>::showLeaf ( leaf<DT>* toShow, int depth ) const
{
	// Check right
	if (toShow->getRight()) 
	{ 
		showLeaf(toShow->getRight(), depth+1); // Show right

		for (int i = 0; i < depth; i++) // Display '/'
		{
			cout << '\t';
		}
		cout << "  /" << endl;
	}

	// Show current
	if (!(toShow->getRight() || toShow->getLeft())) // If we have no branches...
	{ 
		depth -= 1;

		for (int i = 0; i < depth; i++)
		{
			cout << '\t';
		}

		cout << "   " << toShow->getKey() << endl;
	}
	else // If we have branches
	{
		for (int i = 0; i < depth; i++)
		{
			cout << '\t';
		}

		cout << toShow->getKey() << endl;
	}

	// Check left
	if (toShow->getLeft()) 
	{ 
		for (int i = 0; i < depth; i++) // Display '\'
		{
			cout << '\t';
		}
		cout << "  \\" << endl;

		showLeaf(toShow->getLeft(), depth+1); // Show left
	}
}

// insert
// Inserts newDataItem into a binary search tree. If a data item with the same
// key as newDataItem already exists in the tree, then updates that data item's
// nonkey fields with newDataItem's nonkey fields.
template <class DT>
void BSTree<DT>::insert ( const leaf<DT> &newDataItem ) throw ( bad_alloc )
{
	leaf<DT>* temp;

	// Create a new leaf
	try { temp = new leaf<DT>; } 
	catch (bad_alloc ba) { throw ba; }

	// Assign the leaf the approprate values (most coming from newDataItem).
	temp->setKey(newDataItem.getKey());
	temp->setValue(newDataItem.getValue());
	temp->setLeft(NULL);
	temp->setRight(NULL);

	// Assign its location
	if (!top) { top = temp; }
	else
	{
		leaf<DT>* current = top;

		for (bool isRunning = true; isRunning; )
		{
			if (current->getKey() == temp->getKey()) // Transfer the "unique" data when the keys are equal
			{
				current->setValue(temp->getValue());
				delete temp;
				isRunning = false;
			}
			else if (temp->getKey() > current->getKey()) // Move right
			{
				if (current->getRight()) { current = current->getRight(); }
				else
				{
					current->setRight(temp);
					isRunning = false;
				}
			}
			else if (temp->getKey() < current->getKey()) // Move left
			{
				if (current->getLeft()) { current = current->getLeft(); }
				else
				{
					current->setLeft(temp);
					isRunning = false;
				}
			}
		}
	}
}

// retrieve
// Searches a binary search tree for the data item with key searchKey. If this
// data item is found, then copies the data item to searchDataItem and returns
// true. Otherwise, returns false with searchDataItem undefined.
template <class DT>
bool BSTree<DT>::retrieve (DT searchKey, leaf<DT> &searchDataItem)
{
	leaf<DT>* current = top;

	for (bool isRunning = true; isRunning; )
	{
		if (searchKey == current->getKey()) // We are equal, copy values.
		{
			searchDataItem.setKey(current->getKey());
			searchDataItem.setValue(current->getValue());
			searchDataItem.setRight(current->getRight());
			searchDataItem.setLeft(current->getLeft());
			return true;
		}
		else if (searchKey > current->getKey())
		{
			if (current->getRight()) { current = current->getRight(); }
			else { isRunning = false; }
		}
		else
		{
			if (current->getLeft()) { current = current->getLeft(); }
			else { isRunning = false; }
		}
	}

	return false;
}

// remove
// Deletes the data item with key deleteKey from a binary search tree. If this
// data item is found, then deletes it from the tree and returns true. Otherwise,
// returns false.
template <class DT>
bool BSTree<DT>::remove ( DT deleteKey )
{
	if (isEmpty())
	{
		return false;
	}
	else
	{
		Stack<leaf<DT>*> past; // Hold the past of the tree
		leaf<DT>* current = top;

		// Find our value
		for (bool isRunning = true; isRunning; )
		{
			if (deleteKey == current->getKey())	{ isRunning = false; }
			else if (deleteKey > current->getKey())
			{
				if (current->getRight())
				{
					past.push(current);
					current = current->getRight();
				}
				else { return false; } // The value doesn't exist
			}
			else
			{
				if (current->getLeft())
				{
					past.push(current);
					current = current->getLeft();
				}
				else { return false; } // The value doesn't exist
			}
		}

		// Delete current (the value we found)
		if (!(current->getRight() || current->getLeft())) // No branches
		{
			leaf<DT>* temp = past.pop();

			if (temp) // Not top
			{
				if (temp->getRight() == current) { temp->setRight(NULL); }
				else { temp->setLeft(NULL); }
			}
			else if (current == top) // Is top
			{
				top = NULL;
			}
			else { return false; } // Error
		}
		else if (!current->getRight() != !current->getLeft()) // One branch
		{
			leaf<DT>* temp = past.pop();
			
			if (temp) // Not top
			{
				if (current == temp->getRight()) // Right
				{
					temp->setRight((current->getRight()) ? current->getRight() : current->getLeft());
				}
				else if (current == temp->getLeft())  // Left
				{
					temp->setLeft((current->getRight()) ? current->getRight() : current->getLeft());
				}
			}
			else if (current == top) // Is top
			{
				if (current->getRight()) { top = current->getRight(); }
				else { top = current->getLeft(); }
			}
			else { return false; } // Error
		}
		else // Two branches
		{
			leaf<DT>* temp = current->getRight(); // Minimum value
			past.push(temp);

			// Find the minimum element in the right subtree
			for (bool isRunning = true; isRunning; )
			{
				if (temp->getLeft())
				{
					past.push(temp);
					temp = temp->getLeft();
				}
				else { isRunning = false; }
			}

			// Move the data over
			current->setKey(temp->getKey());
			current->setValue(temp->getValue());

			// Remove temp
			if (temp->getRight()) // We have a right, but not a left (smallest value)
			{
				if (current->getRight() == temp) // Only went down one layer
				{
					current->setRight(temp->getRight());
					temp->setRight(NULL);
				}
				else // Went down at least 2 layers
				{
					past.peek()->setLeft(temp->getRight());
					temp->setRight(NULL);
				}
			}
			else // We have no right or left (smallest value)
			{
				if (current->getRight() == temp) // Only went down one layer
				{
					current->setRight(NULL);
				}
				else
				{
					past.peek()->setLeft(NULL);
				}
			}

			current = temp;
		}

		delete current;

		return true;
	}
}

// writeKeys
// Outputs the keys of the data items in a binary search tree. The keys are output
// in ascending (smallest to largest) order, one per line.
template <class DT>
void BSTree<DT>::writeKeys () const
{
	if (isEmpty())
	{
		cout << "Empty tree..." << endl;
	}
	else
	{
		writeLeaf(top);
	}
}

// clear
// Removes all the data items in a binary search tree.
template <class DT>
void BSTree<DT>::clear ()
{
	if (!isEmpty()) { clearLeaf(top); top = NULL; }
}

// isEmpty
// Returns true if a binary serch tree is empty. Otherwise, returns false.
template <class DT>
bool BSTree<DT>::isEmpty () const
{
	return !top;
}

// isFull
// Returns true if a binary search tree is full. Otherwise, returns false.
template <class DT>
bool BSTree<DT>::isFull () const
{
	return false; // Because we never defined what full was, we can never be full.
}

// showStructure
// Outputs the keys in a binary search tree. The tree is output with its
// branches oriented from left (root) to right (leaves); that is, the tree is
// output rotated counterclockwise 90 degrees from its conventional orientation.
// If the tree is empty, outputs "Empty tree". Note this operation is intended
// for debugging purposes only.
template <class DT>
void BSTree<DT>::showStructure () const
{
	if (isEmpty())
	{
		cout << "Empty tree..." << endl;
	}
	else
	{
		showLeaf(top, 0);
	}
}

#endif // PARSCH_BINARY_SEARCH_TREE_TPP