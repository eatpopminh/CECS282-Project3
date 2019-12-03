#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "DoublyLinkedList.h"
#include "StackDoublyLinkedList.h"
#include "Node.h"
#include "Complex.h"
using namespace std;

void pushingEverything(StackDoublyLinkedList<string>& all,string express)
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
				all.addBack(temp);
				temp = "";
				
				
				string temp1 = "";
				temp1 = temp1 + express[index];
				all.addBack(temp1);
				temp1 = "";
				
			}
			else
			{
				string temp1 = "";
				temp1 = temp1 + express[index];
				all.addBack(temp1);
				temp1 = "";
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
bool pushOne(StackDoublyLinkedList<string>& all,StackDoublyLinkedList<char>& operators, StackDoublyLinkedList<int>& oprands)
{
	string temp = all.getTop();
	int i;
	istringstream(temp)>>i;
	if(i==0)
	{
		char temp1 = all.getTop()[0];
		operators.addFront(temp1);
		all.popFront();
		return true;
	}
	else
	{
		oprands.addFront(i);
		all.popFront();	
		return false;
	}
		
}
int getPrecedence(char ch)
{
	switch(ch)
	{
		case '+':
		case '-': return 1;
		case '*':
		case '/': return 2;
		case '(':
		case ')': return 3;
		default: return -1;
		
			
	}
}
Complex operate(Complex num1, Complex num2, char op)
{
	if(op=='+')return num1 + num2;
    if(op=='-')return num1 - num2;
    if(op=='*')return num1 * num2;
    return num1 / num2;

}
bool isDigit(char c)
{
	return (c>='0' && c<='9');
}
bool isOp(char c)
{
	return (c=='+' || c=='-' ||c=='*' ||c=='/' ||c=='(' ||c==')');
}
//int evaluate(string s)
//{
//	StackDoublyLinkedList<char> ops;
//	StackDoublyLinkedList<int> vals;
//	int val = 0;
//	int pos = 0;
//	while(pos<s.length())
//	{
//		char spot = s[pos];
//		if(isDigit(spot))
//		{
//			val = (val*10)+(int)(spot-'0');
//		}
//		else if(isOp(spot))
//		{
//			if(spot == '(')
//			{
//				ops.addFront(spot);
//				val = 0;
//			}
//			if(vals.isEmpty())
//			{
//				vals.addFront(val);
//				//ops.addFront(ops);
//				val=0;
//			}
//			else if(spot==')')
//			{
//				vals.addFront(val);
//				while(ops.getTop()!='(')
//				{
//					spot = ops.popFront();
//					val = vals.popFront();
//				}
//			}
//		}
//	}
//}
void splitOPS(StackDoublyLinkedList<string>& all,StackDoublyLinkedList<char>& operators, StackDoublyLinkedList<int>& oprands)
{
	while(!all.isEmpty())
	{
		string temp = all.getTop();
		int i;
		istringstream(temp)>>i;
		
		if(i==0)
		{
			char temp1 = all.getTop()[0];
			operators.addFront(temp1);
		}
		else
		{
			oprands.addFront(i);
		}
		all.popFront();	
	}
}


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
void pushingOperat(StackDoublyLinkedList<char>& operators, string express)
{
	int index = 0;
	bool flag = true;
	while(flag)
	{
		if(express[index]=='+' || express[index]=='-' || express[index]=='*' || express[index]=='/'
			  || express[index]=='(' || express[index]==')' || express[index]=='i' || express[index]=='=')
		{
			operators.addFront(express[index]);
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




	//ofstream out;
	//out.open("output.txt",ios_base::app);
	string express = "33+2i*4+i=";
	cout<<express<<endl;
	StackDoublyLinkedList<char> operators;
	StackDoublyLinkedList<int> oprands;
	StackDoublyLinkedList<string> all;
	StackDoublyLinkedList<Complex> complex;
	StackDoublyLinkedList<string> all2;


	
	
//	string temp = "0";
//	int i;
//	istringstream(temp)>>i;
//	cout<<i<<endl;	
	
	
//	pushingOprands(oprands, express);
//	pushingOperat(operats, express);
//	oprands.displayList();
//	operats.displayList();
	
	
	//push ALL Operators and Oprands into one stack.
	pushingEverything(all,express);
	cout<<"all: "<<endl;
	all.displayList();
	cout<<all.getTop()<<endl;

	//push ONE into Operators or Oprands.
	//return 1 if Operator
	//return 0 if Oprands
//	pushOne(all,operators,oprands);
//	pushOne(all,operators,oprands);
//	pushOne(all,operators,oprands);
//	pushOne(all,operators,oprands);


	bool flag = true;
	while(flag)
	{
		int idk = pushOne(all,operators,oprands);
		
		
//		if(operators.getTop()=='i')
//		{
//			//char temp = operators.getTop();
////			operators.popFront();
////			if((operators.getTop()!='+' && operators.getTop()!='-'))
////			{
////				string s(1,operators.getTop());
////				all2.addFront(s);
////			}
////			operators.addFront(temp);
//		}
		
//		if( operators.getTop()=='*' || operators.getTop()=='/' || operators.getTop()=='%')
//		{
//			string s(1,operators.getTop());
//			all2.addFront(s);
//			operators.popFront();
//		}
//		if(operators.getTop()=='(' || operators.getTop()==')')
//		{
//			string s(1,operators.getTop());
//			all2.addFront(s);
//			//all2.popFront();
//		}
//		operators.displayList();

		
		if(operators.getTop()=='i')
		{
			operators.popFront();
			if(oprands.getSize()==2)
			{
				int temp1 = oprands.getTop();
				oprands.popFront();
				int temp2 = oprands.getTop();
				oprands.popFront();
				
				if(operators.getTop()=='+')
				{
					Complex com(temp2,temp1,1);
					complex.addFront(com);
					//all2.addFront((com.toString()));

					cout<<com<<endl;
				}
				else
				{
					Complex com(temp2,-temp1,1);
					complex.addFront(com);
					//all2.addFront((com.toString()));

					cout<<com<<endl;
				}
			}
			else
			{
				int temp1 = oprands.getTop();
				oprands.popFront();
				
				
				if(operators.getTop()=='+')
				{
					Complex com(temp1,1,1);
					complex.addFront(com);
					//all2.addFront((com.toString()));

					cout<<com<<endl;
				}
				else
				{
					Complex com(temp1,-1,1);
					complex.addFront(com);
//					string temp = com.toString();
					//all2.addFront((com.toString()));
					cout<<com<<endl;
				}
			}
			operators.popFront();
		}
		
//		if(idk==0)
//		{
//			cout<<"HERE"<<endl;
//			oprands.displayList();
//			operators.displayList();
//			if(operators.getTop()==')')
//			{
//				cout<<"HERE"<<endl;
//
//				operators.popFront();
//
//				int temp1 = oprands.getTop();
//				oprands.popFront();
//				int temp2 = oprands.getTop();
//				oprands.popFront();
//				if(operators.getTop()=='+')
//				{
//					Complex com(temp2,temp1,1);
//					complex.addFront(com);
//					cout<<com<<endl;
//				}
//				else
//				{
//					Complex com(temp2,-temp1,1);
//					complex.addFront(com);
//					cout<<com<<endl;
//				}
//				operators.popFront();
//
//			}
//		}
//		if(idk==1)
//		{
//			if(operators.getTop()=='(')
//			{
//				while(operators.getTop()!=')')
//				{
//					int idk = pushOne(all,operators,oprands);	
//				}
//				cout<<"AFTER()"<<endl;
//				operators.displayList();
//				operators.popFront();
//				
//				if(operators.getTop()=='i')
//				{
//					operators.popFront();
//					if(oprands.getSize()==2)
//					{
//						int temp1 = oprands.getTop();
//						oprands.popFront();
//						int temp2 = oprands.getTop();
//						oprands.popFront();
//						
//						if(operators.getTop()=='+')
//						{
//							Complex com(temp2,temp1,1);
//							complex.addFront(com);
//							cout<<com<<endl;
//						}
//						else
//						{
//							Complex com(temp2,-temp1,1);
//							complex.addFront(com);
//							cout<<com<<endl;
//						}
//					}
//					else
//					{
//						int temp1 = oprands.getTop();
//						oprands.popFront();
//						
//						
//						if(operators.getTop()=='+')
//						{
//							Complex com(temp1,1,1);
//							complex.addFront(com);
//							cout<<com<<endl;
//						}
//						else
//						{
//							Complex com(temp1,-1,1);
//							complex.addFront(com);
//							cout<<com<<endl;
//						}
//					}
//					operators.popFront();
//				}
//				
//			}
//				
//		}
//			if(operators.getTop()=='i')
//			{
//				operators.popFront();
//				if(oprands.getSize()==2)
//				{
//					int temp1 = oprands.getTop();
//					oprands.popFront();
//					int temp2 = oprands.getTop();
//					oprands.popFront();
//					
//					if(operators.getTop()=='+')
//					{
//						Complex com(temp2,temp1,1);
//						complex.addFront(com);
//						cout<<com<<endl;
//					}
//					else
//					{
//						Complex com(temp2,-temp1,1);
//						complex.addFront(com);
//						cout<<com<<endl;
//					}
//				}
//				else
//				{
//					int temp1 = oprands.getTop();
//					oprands.popFront();
//					
//					
//					if(operators.getTop()=='+')
//					{
//						Complex com(temp1,1,1);
//						complex.addFront(com);
//						cout<<com<<endl;
//					}
//					else
//					{
//						Complex com(temp1,-1,1);
//						complex.addFront(com);
//						cout<<com<<endl;
//					}
//				}
//				operators.popFront();
//			
//		}
		
		
		//THIS SHIT WORKS
//			if(operators.getTop()=='i')
//			{
//				operators.popFront();
//				if(oprands.getSize()==2)
//				{
//					int temp1 = oprands.getTop();
//					oprands.popFront();
//					int temp2 = oprands.getTop();
//					oprands.popFront();
//					
//					if(operators.getTop()=='+')
//					{
//						Complex com(temp2,temp1,1);
//						complex.addFront(com);
//						cout<<com<<endl;
//					}
//					else
//					{
//						Complex com(temp2,-temp1,1);
//						complex.addFront(com);
//						cout<<com<<endl;
//					}
//				}
//				else
//				{
//					int temp1 = oprands.getTop();
//					oprands.popFront();
//					
//					
//					if(operators.getTop()=='+')
//					{
//						Complex com(temp1,1,1);
//						complex.addFront(com);
//						cout<<com<<endl;
//					}
//					else
//					{
//						Complex com(temp1,-1,1);
//						complex.addFront(com);
//						cout<<com<<endl;
//					}
//				}
//				operators.popFront();
//			}	
		
		
		if(operators.getTop()=='=')
		{
			flag = false;
			operators.popFront();
		}
	}
	
//	char op = operators.getTop();
//	cout<<op<<endl;
//		if(op=='+')
//		{
//			Complex temp1 = complex.getTop();
//			complex.popFront();
//			Complex temp2 = complex.getTop();
//			complex.popFront();
//			Complex com = temp2 + temp1;
//			answers.addFront(com);
//			operators.popFront();
//			cout<<com<<endl;
//		}
//		else if(op=='-')
//		{
//			Complex temp1 = complex.getTop();
//			complex.popFront();
//			Complex temp2 = complex.getTop();
//			complex.popFront();
//			Complex com = temp2 - temp1;
//			answers.addFront(com);
//			operators.popFront();
//			cout<<com<<endl;
//		}
//		else if(op=='*')
//		{
//			Complex temp1 = complex.getTop();
//			complex.popFront();
//			Complex temp2 = complex.getTop();
//			complex.popFront();
//			Complex com = temp2 * temp1;
//			answers.addFront(com);
//			operators.popFront();
//			cout<<com<<endl;
//		}
//		else if(op=='/')
//		{
//			Complex temp1 = complex.getTop();
//			complex.popFront();
//			Complex temp2 = complex.getTop();
//			complex.popFront();
//			Complex com = temp2 / temp1;
//			answers.addFront(com);
//			operators.popFront();
//			cout<<com<<endl;
//		}


//	if(oprands.getSize()==2)
//	{
//		
//		int im = oprands.getTop();
//		oprands.popFront();
//		//cout<<"hello"<<pushOne(all,operators,oprands);
//
//		if(pushOne(all,operators,oprands)==1)
//		{
//			if(operators.getTop()=='i')
//			{
//				operators.popFront();
//			}
//		}
//
//		
//		int re = oprands.getTop();
//		oprands.popFront();
//		//operators
//		char temp = operators.getTop();
//		operators.popFront();
//		if(temp=='+')
//		{
//			Complex com(re,im,1);
//			cout<<com<<endl;
//		}
//		if(temp=='-')
//		{
//			Complex com(re,-im,1);
//			cout<<com<<endl;
//		}	
//		
//	
//		
//	}
//	pushOne(all,operators,oprands);
	
	
	
	
		
		

		
			
	cout<<"MY Complex: "<<endl;
//	while(complex.isEmpty()==0)
//	{
//		cout<<complex.getTop()<<endl;
//		complex.popFront();
//	}
//	cout<<"ALL: "<<endl;
//	all2.displayList();

	
	cout<<"Oprands: "<<endl;
	oprands.displayList();
	cout<<"Operator: "<<endl;
	operators.displayList();
	
	return 0;
}

    
