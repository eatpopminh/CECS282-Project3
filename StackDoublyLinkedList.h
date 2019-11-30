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
template<class T>
StackDoublyLinkedList<T> :: StackDoublyLinkedList()
{
	
}
template<class T>
void StackDoublyLinkedList<T> :: displayStack() const
{
	Node<T>* temp = DoublyLinkedList<T>::head;
	while(temp!=NULL)
	{
		cout<<temp->data<<endl;
		temp = temp->next;
	}	
}
template<class T>
T StackDoublyLinkedList<T> :: getTop() const
{
	Node<T>* temp = DoublyLinkedList<T>:: head;

	return temp->data;
	
}

#endif
