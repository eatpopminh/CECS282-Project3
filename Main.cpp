#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "DoublyLinkedList.h"
#include "StackDoublyLinkedList.h"
#include "Node.h"
#include "Complex.h"
using namespace std;


void pushingOprands(StackDoublyLinkedList<int>& oprands, string express)
{
	int index = 0;
	string temp = "";
	bool flag = true;
	while(flag)
	{
		if(express[index]=='+' || express[index]=='-' || express[index]=='*' || express[index]=='/'
			  || express[index]=='(' || express[index]==')' || express[index]=='i' || express[index]=='=')
		{
			if(temp!="")
			{
				int i;
				istringstream(temp)>>i;
				oprands.addFront(i);
				temp = "";
			}
		}
		else
		{
			temp = temp + express[index];
		}
		if(express[index]=='=')
		{
			flag = false;
		}
		index++;
		
	}
}
void pushingOperat(StackDoublyLinkedList<char>& operats, string express)
{
	int index = 0;
	bool flag = true;
	while(flag)
	{
		if(express[index]=='+' || express[index]=='-' || express[index]=='*' || express[index]=='/'
			  || express[index]=='(' || express[index]==')' || express[index]=='i' || express[index]=='=')
		{
			operats.addFront(express[index]);
		}
	
		if(express[index]=='=')
		{
			flag = false;
		}
		index++;
	}
}

int main()
{


//	DoublyLinkedList<int> dll;
//		
//	dll.addFront(7);
//	dll.addFront(6);
//	dll.addFront(9);
//	dll.addFront(19);
//	dll.addFront(90);
//
//	//dll.popFront();
////	dll.addBack(8);
//	//dll.popBack();
//	
////	cout<<dll.getSize()<<endl;
////	cout<<dll.isEmpty()<<endl;
//	
////	Complex com(3,4,1);
////	cout<<com.toString()<<endl;
//
//
//	//addNode()
//	Node<int>* iter = dll.getHead();
//
//	int count = 0;
//	while(count < 3)
//	{
//		iter = iter->next;
//		count++;
//	}
//	//cout<<iter->data<<endl;
//	dll.addNode(100,iter);
//	
//	//deleting a node.
//	Node<int>* iter1 = dll.getHead();
//	count = 0;
//	while(count<4)
//	{
//		iter1 = iter1->next;
//		count++;
//	}
//	dll.deleteNode(100,iter1);
//	
//	//findNode()
//	Node<int>* myNode = dll.findNode(100);
//	//cout<<myNode->data<<endl;
//	dll.displayList();
//
//	DoublyLinkedList<int> dll2;
//	
//	
//	dll2.addBack(1);
//	dll2.addBack(2);
//	dll2.addBack(4);
//	dll2.addBack(5);
//	dll2.addBack(6);
//	
//	Node<int>* it = dll2.getHead();
//	int place = 0;
//	while(place <2)
//	{
//		it = it->next;
//		place++;
//	}
//	
//	dll2.addNode(3,it); 
//	dll2.displayList();
//
//	cout<<"MY HEAD: "<<dll2.getHead()->data<<endl;
//	cout<<"MY HEAD NEXT: "<<dll2.getHead()->next->data<<endl;
//	
//	Node<int>* delit = dll2.getHead();
//	int del = 0;
//	while (del < 2)
//	{
//		delit = delit -> next;
//		del++;
//	}
//	dll2.deleteNode(3, delit);
//	
//	dll2.displayList();
	
//	StackDoublyLinkedList<int> sdll;
//	sdll.addFront(5);
//	sdll.addFront(4);
//	sdll.addFront(3);
//	sdll.addFront(2);
////	cout<<"TOP: "<<sdll.getTop()<<endl;
////	sdll.displayStack();
//	
//	Complex com(2,3,1);
//	cout<<com<<endl;
//	
//	Complex com1(7,1,1);
//	cout<<com1<<endl;
//	cout<<endl;
//	Complex com3 = com + com1;
//	cout<<"+: "<<com3<<endl;
//	
//	Complex com4 = com - com1;
//	cout<<"-: "<<com4<<endl;
//	
//	Complex com5 = com * com1;
//	cout<<"*: "<<com5<<endl;
//	
//	Complex com6 = com / com1;
//	cout<<"/: "<<com6<<endl;

	//ofstream out;
	//out.open("output.txt",ios_base::app);
	string express = "33+2i*4+1=";
	cout<<express<<endl;
	StackDoublyLinkedList<char> operats;
	StackDoublyLinkedList<int> oprands;
//	int index = 0;
//	string temp = "";
//	bool flag = true;
//	while(flag)
//	{
//		if(express[index]=='+' || express[index]=='-' || express[index]=='*' || express[index]=='/'
//			  || express[index]=='(' || express[index]==')' || express[index]=='i' || express[index]=='=')
//		{
//			if(temp!="")
//			{
//				int i;
//				istringstream(temp)>>i;
//				cout<<i<<endl;
//				oprands.addFront(i);
//				temp = "";
//			}
//		}
//		else
//		{
//			temp = temp + express[index];
//		}
//		if(express[index]=='=')
//		{
//			flag = false;
//		}
//		index++;
//		
//	}
	pushingOprands(oprands, express);
	pushingOperat(operats, express);
	oprands.displayList();
	operats.displayList();
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}

    
