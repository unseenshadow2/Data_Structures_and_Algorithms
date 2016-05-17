/*
 * Class: DoublyLinkedList
 * File: Header
 * Author: Anthony Parsch
 * Creation Date: 5/17/2016
 * Purpose: To demonstrate/gain an understanding of linked lists by
 *          creating a linked list implentation from scratch.
 */

#ifndef LINKED_LIST_HEADER
#define LINKED_LIST_HEADER

// DoublyNode
// The nodes for a DoublyLinkedList
template <typename T>
struct DoublyNode
{
  T* key;
  DoublyNode* next;
  DoublyNode* previous;
};

// DoublyLinkedList
// A linked list that is capable of being moved along in both a forward
// and backward direction
template <class T>
class DoublyLinkedList
{
protected:
  DoublyNode<T>* head; // The pointer to the beginning of the list
  DoublyNode<T>* tail; // The pointer to the end of the list
  DoublyNode<T>* current; // A "current" value to make the life of the user easier
  int _length; // The length of our DoublyLinkedList

public:
  // Default constructor
  DoublyLinkedList();

  // Constructor
  // Create a DoublyLinkedList with a initial key with the value given
  DoublyLinkedList(T firstValue);

  // Find
  // Find the DoublyNode where the key == dataToFind
  // This will rely upon the == operator
  DoublyNode<T>* Find(T dataToFind);

  // Insert
  // Inserts the new key value into a DoublyNode
  // at the position given, starting from 0. If a
  // negative value is passed, the value is placed
  // at the end of the DoublyLinkedList.
  // Returns whether the operation was successful.
  bool Insert(T newData, int position = -1);

  // Delete
  // Removes the DoublyNode at the given pointer.
  // Returns wether the operation was successful.
  bool Delete(DoublyNode* toDelete);

  // MoveForward
  // Move along the DoublyLinkedList in a forward
  // direction a number of positions given. Returns
  // the new current node.
  DoublyNode* MoveForward(int numToMove = 1);

  // MoveBackward
  // Move along the DoublyLinkedList in a backward
  // direction a number of positions given. Returns
  // the new current node.
  DoublyNode* MoveBackward(int numToMove = 1);

  // Length
  // Returns the number of nodes in the list
  int Length();

  // Minimum
  // Returns the minimum key value. Uses the < operator.
  T Minimum();

  // Maximum
  // Returns the maximum key value. Uses the < operator.
  T Maximum();

  // GetCurrent
  // Returns a pointer to the current DoublyNode.
  DoublyNode* GetCurrent();

  // operator++
  // Moves the current position in the DoublyLinkedList
  // in the forward direction by 1. Returns the new
  // current pointer.
  DoublyNode<T>* operator++(); // This one as well

  // operator--
  // Moves the current position in the DoublyLinkedList
  // in the backward direction by 1. Returns the new
  // current pointer.
  DoublyNode<T>* operator--();

  // operator()
  // Returns the key value at the current pointer's position.
  T operator()(); // Look this one up

  // operator==
  // Returns whether the key values of the current pointers
  // are equivilent to each other. Uses the == on the key
  // values.
  bool operator==(const DoublyLinkedList<T> dll1, const DoublyLinkedList<T> dll2);
};

#endif // LINKED_LIST_HEADER
