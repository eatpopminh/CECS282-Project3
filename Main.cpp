#include <iostream>
#include <string>
#include "DoublyLinkedList.h"
#include "Node.h"
using namespace std;

int main()
{
	DoublyLinkedList<int> dll;
	Node<int>* iter = dll.getHead();
	while(count < 5)
	{
		iter = iter -> next;
		count++;
	}
	ten->data = 10;
	dll.addNode(10,iter);
	
	int a = 6;
	
	dll.addFront(7);
	dll.addFront(a);
	
	//dll.popFront();
	//dll.addBack(8);
	//dll.popBack();
	//dll.addNode(100,ten);
	
	cout<<dll.getSize()<<endl;
	cout<<dll.isEmpty()<<endl;
	dll.displayList();
	return 0;
}
