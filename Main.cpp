#include <iostream>
#include <string>
#include "DoublyLinkedList.h"
#include "Node.h"
#include "Complex.h"
using namespace std;

int main()
{
	DoublyLinkedList<int> dll;
		
	dll.addFront(7);
	dll.addFront(6);
	dll.addFront(9);
	dll.addFront(19);
	dll.addFront(90);

	//dll.popFront();
//	dll.addBack(8);
	//dll.popBack();
	
//	cout<<dll.getSize()<<endl;
//	cout<<dll.isEmpty()<<endl;
	
//	Complex com(3,4,1);
//	cout<<com.toString()<<endl;


	//addNode()
	Node<int>* iter = dll.getHead();

	int count = 0;
	while(count < 3)
	{
		iter = iter->next;
		count++;
	}
	//cout<<iter->data<<endl;
	dll.addNode(100,iter);
	
	//deleting a node.
	Node<int>* iter1 = dll.getHead();
	count = 0;
	while(count<4)
	{
		iter1 = iter1->next;
		count++;
	}
	dll.deleteNode(100,iter1);
	
	//findNode()
	Node<int>* myNode = dll.findNode(100);
	//cout<<myNode->data<<endl;
	dll.displayList();

	DoublyLinkedList<int> dll2;
	
	
	dll2.addBack(1);
	dll2.addBack(2);
	dll2.addBack(4);
	dll2.addBack(5);
	dll2.addBack(6);
	
	Node<int>* it = dll2.getHead();
	int place = 0;
	while(place <2)
	{
		it = it->next;
		place++;
	}
	
	dll2.addNode(3,it); 
	dll2.displayList();

	cout<<"MY HEAD: "<<dll2.getHead()->data<<endl;
	cout<<"MY HEAD NEXT: "<<dll2.getHead()->next->data<<endl;
	
	Node<int>* delit = dll2.getHead();
	int del = 0;
	while (del < 2)
	{
		delit = delit -> next;
		del++;
	}
	dll2.deleteNode(3, delit);
	
	dll2.displayList();
	return 0;
}

    
