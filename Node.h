#ifndef NODE_H
#define NODE_H


using namespace std;
template <class T>
struct Node
{
	T data; //data of node
	Node* prev; //pointer to previous node
	Node* next; //pointer to the next node
};

#endif
