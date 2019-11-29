#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include "Node.h"
#include <iostream>
#include <string>
//#include <iterator>
using namespace std;

template <class T>
class DoublyLinkedList
{
	protected:
		Node<T>* head; //pointer to the first node of the doubly linked list
		Node<T>* tail; //pointer to the last node of the dubly linked list
		int size; //size of the doubly linked list
		
	public:
		DoublyLinkedList();
		void addFront(T d); //add a node at the beginning 
							//of the doubly linked list
		void popFront(); //remove a node at the beginning 
						//of a doubly linked list
		void addBack(T d);
		void popBack();
		void addNode(T d, Node<T>* iter);
		void deleteNode(T d, Node<T>* iter);
		Node<T>* findNode(T d);
		int getSize() const;
		bool isEmpty() const;
		void displayList() const;
		
		Node<T>* getHead() const;
};



template <class T>
DoublyLinkedList<T> :: DoublyLinkedList()
{
	head = NULL;
	tail = NULL;
	size = 0;
	
}
template<class T>
void DoublyLinkedList<T> :: addFront(T d)
{
	Node<T>* newNode = new Node<T>(); //Make the new Node.
	newNode->data = d; //Put data in the new Node.
	newNode->prev = NULL; //New Node prev is NULL.
	newNode->next = head; //New Node next is the head.
	
	if(head == NULL)
	{
		tail = newNode;
	}
	else
	{
		head->prev = newNode;
	}
	head = newNode;
	size++;
}
template<class T>
void DoublyLinkedList<T> :: popFront()
{
	Node<T>* temp = head->next;
	temp->prev = NULL;
	head = temp;
	size--;
}
template<class T>
void DoublyLinkedList<T> ::addBack(T d)
{
	Node<T>* newNode = new Node<T>();
	newNode->data = d;
	newNode->prev = tail;
	newNode->next = NULL;
	if(tail == NULL)
	{
		head = newNode;
	}
	else
	{
		
		tail->next = newNode;
	}
	tail = newNode;
	size++;
	
}
template<class T>
void DoublyLinkedList<T> :: popBack()
{
	tail = tail->prev;
	tail->next = NULL;
	size--;
}
template<class T>
void DoublyLinkedList<T> :: addNode(T d, Node<T>* iter)
{
	Node<T>* temp = head;
	while(temp != iter)
	{
		temp = temp -> next;
	}
	temp = iter;
	cout<<temp->data<<endl;
	Node<T>* newNode = new Node<T>();
	newNode->data = d;
	newNode->prev = temp->prev;
	newNode->next = temp;
	(temp->prev)->next = newNode;
	
	
	temp->prev = newNode;
	size++;
}
template<class T>
void DoublyLinkedList<T> :: deleteNode(T d, Node<T>* iter)
{
	Node<T>* temp = head;
	while(temp != iter)
	{
		temp = temp -> next;
	}
	
	temp = iter;
	Node<T>* tempPrev = temp->prev;
	tempPrev->next = temp->next;
	(temp->next)->prev = tempPrev;
	 size--;
}
template<class T>
Node<T>* DoublyLinkedList<T> :: findNode(T d)
{
	Node<T>* temp = head;
	while(temp->data != d)
	{
		temp = temp->next;
	}
	return temp;
}

template<class T>
int DoublyLinkedList<T> :: getSize() const
{
	return size;
}
template<class T>
bool DoublyLinkedList<T> :: isEmpty() const
{
	if(size==0)
		return true;
	else
		return false;
}
template<class T>
void DoublyLinkedList<T> :: displayList() const
{
	Node<T>* tempHead = head;
	cout<<"NULL <-> ";
	while(tempHead != NULL)
	{
		cout<<tempHead->data<<" <-> ";
		tempHead = tempHead->next;
	}
	cout<<"NULL"<<endl;
}

template<class T>
Node<T>* DoublyLinkedList<T> :: getHead() const
{
	return head;
}


#endif
