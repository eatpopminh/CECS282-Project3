#ifndef STACKDOUBLYLINKEDLIST_H
#define STACKDOUBLYLINKEDLIST_H

#include <iostream>
#include <string>
#include "DoublyLinkedList.h"
using namespace std;
template<class T>
class StackDoublyLinkedList : public DoublyLinkedList<T>
{
	public:
		StackDoublyLinkedList();
		void displayStack() const;  
		T getTop() const;	
	
};

StackDoublyLinkedList<T> :: StackDoublyLinkedList()
{
	DoublyLinkedList<T> dll;
}
void StackDoublyLinkedList<T> :: displayStack() const
{
	
}
T StackDoublyLinkedList<T> :: getTop() const
{
	
}

#endif
