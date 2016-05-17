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

template <typename T>
struct DoublyNode
{
  T* key;
  DoublyNode* next;
  DoublyNode* previous;
};

template <class T>
class DoublyLinkedList
{
  T* Find(T dataToFind);
  bool Insert(T newData);
  bool Delete()
};

#endif // LINKED_LIST_HEADER
