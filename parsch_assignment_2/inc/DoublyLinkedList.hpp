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

// The nodes for a DoublyLinkedList
template <typename T>
struct DoublyNode
{
  T* key;
  DoublyNode* next;
  DoublyNode* previous;
};

// A DoublyLinkedList
template <class T>
class DoublyLinkedList
{
protected:
  DoublyNode<T>* head; // The pointer to the beginning of the list
  DoublyNode<T>* tail; // The pointer to the end of the list
  DoublyNode<T>* current; // A "current" value to make the life of the user easier
  int _length; // The length of our DoublyLinkedList

public:
  DoublyLinkedList();
  DoublyLinkedList(T firstValue);
  T* Find(T dataToFind);
  bool Insert(T newData);
  bool Delete(DoublyNode* toDelete);
  bool MoveForward(int numToMove);
  bool MoveBackward(int numToMove);
  int Length();
  DoublyNode* Minimum();
  DoublyNode* Maximum();
  DoublyNode* GetCurrent();
};

#endif // LINKED_LIST_HEADER
