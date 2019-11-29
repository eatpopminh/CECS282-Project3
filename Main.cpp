#include <iostream>
#include <string>
#include "DoublyLinkedList.h"
#include "Node.h"
#include "Complex.h"
using namespace std;

int main()
{
	DoublyLinkedList<int> dll;
	
	
	
	
	int a = 6;
	
	dll.addFront(7);
	dll.addFront(a);
	dll.addFront(9);
	dll.addFront(19);
	dll.addFront(90);

	//dll.popFront();
	dll.addBack(8);
	//dll.popBack();
	
	cout<<dll.getSize()<<endl;
	cout<<dll.isEmpty()<<endl;
	
//	Complex com(3,4,1);
//	cout<<com.toString()<<endl;

	Node<int>* iter = dll.getHead();

	int count = 0;
	while(count < 3)
	{
		iter = iter->next;
		count++;
	}
	cout<<iter->data<<endl;
	dll.addNode(100,iter);
	
	dll.displayList();

	
	
	return 0;
}

    
