#include <iostream>
#include <string>
#include "DoublyLinkedList.h"
#include "Node.h"
using namespace std;

int main()
{
	DoublyLinkedList<int> dll;
	Node<int>* ten = new Node<int>();
	ten->data = 10;
	
	int a = 6;
	
	dll.addFront(7);
	dll.addFront(a);
	//dll.popFront();
	dll.addBack(8);
	//dll.popBack();
	dll.addNode(100,ten);
	//cout<<dll.getSize()<<endl;
	dll.displayList();
	return 0;
}
