//Name : Minh Truong
//Class : CECS282
//Instructor: Minhthong Nguyen
//Purpose of the program: Complex Calculator
//Last updated:12/3/19
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "DoublyLinkedList.h"
#include "StackDoublyLinkedList.h"
#include "Node.h"
#include "Complex.h"
using namespace std;
Complex val;
/**
  *Pushing everything into the stack.
  *@param all My Stack
  *@param express The given expression
**/
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
				all.addFront(temp);
				temp = "";
				
				
				string temp1 = "";
				temp1 = temp1 + express[index];
				all.addFront(temp1);
				temp1 = "";
				
			}
			else
			{
				string temp1 = "";
				temp1 = temp1 + express[index];
				all.addFront(temp1);
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
/**
  *Push onto the stack
  *@param all My Stack
  *@param operators 
  *@paramo prands
  *@return bool
**/
bool pushOne(StackDoublyLinkedList<string>& all,StackDoublyLinkedList<string>& operators, StackDoublyLinkedList<int>& oprands)
{
	string temp = all.getTop();
	int i;
	istringstream(temp)>>i;
	cout<<i<<endl;
	if(i==0)
	{
		//char temp1 = all.getTop()[0];
		operators.addFront(temp);
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
/**
  *Precedence
  *@param ch my char into number
  *@return int
  *
**/
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
		case '%': return 4;
		default: return -1;		
	}
}
/**
  *Do operation
  *@param num1 Complex
  *@param num2 Complex
  *@param op my operator
  *@return Complex
**/
Complex operate(Complex num1, Complex num2, string op)
{
	cout<<num1.toString()<<num2.toString()<<endl;
	if(op[0]=='+')return num1 + num2;
    if(op[0]=='-')return num1 - num2;
    if(op[0]=='*')return num1 * num2;
    return num1 / num2;
}
/**
  *Check if its a digit
  *@param c 
  *@return bool
  *
**/
bool isDigit(char c)
{
	return (c>='0' && c<='9');
}
/**
  *Check if Operator
  *@param c
  *@return bool
  *
**/
bool isOp(string c)
{
	return (c[0]=='+' || c[0]=='-' || c[0]=='*' || c[0]=='/' || c[0]=='(' || c[0]==')');
}

/**
  *Pushing into correct stack and filter(2nd generation)
  *@param myString the expression
  *
  *
**/
void justDoIt(string myString)
{
	string express = myString;
	cout<<express<<endl;
	StackDoublyLinkedList<string> operators;
	StackDoublyLinkedList<int> oprands;
	StackDoublyLinkedList<string> all;
	StackDoublyLinkedList<Complex> complex;
	StackDoublyLinkedList<Complex> all2;
	
	
	//push ALL Operators and Oprands into one stack.
	pushingEverything(all,express);
	cout<<"all: "<<endl;
	all.displayList();

	//operators.getTop();
	//push ONE into Operators or Oprands.
	//return 1 if Operator
	//return 0 if Oprands
//	pushOne(all,operators,oprands);

	while(!all.isEmpty())
	{
		pushOne(all,operators,oprands);

		if(operators.getTop()=="i")
		{
			operators.popFront();
			if(oprands.getSize()==2)
			{
				int temp1 = oprands.getTop();
				oprands.popFront();
				int temp2 = oprands.getTop();
				oprands.popFront();
				
				if(operators.getTop()=="+")
				{
					Complex com(temp2,temp1,1);
					complex.addFront(com);
					all2.addFront(com);

					cout<<com<<endl;
				}
				else
				{
					Complex com(temp2,-temp1,1);
					complex.addFront(com);
					all2.addFront(com);

					cout<<com<<endl;
				}
			}
			else
			{
				int temp1 = oprands.getTop();
				oprands.popFront();
				
				if(operators.getTop()=="+")
				{
					Complex com(temp1,1,1);
					complex.addFront(com);
					all2.addFront(com);

					cout<<com<<endl;
				}
				else
				{
					Complex com(temp1,-1,1);
					complex.addFront(com);
//					string temp = com.toString();
					all2.addFront(com);
					cout<<com<<endl;
				}
			}
			operators.popFront();
		}
	}
	
	while(all2.getSize()>0)
	{
		Complex temp1 = all2.getTop();
		all2.popFront();
		Complex temp2 = all2.getTop();
		all2.popFront();
		if(operators.getTop()=="+" )
		{
			operate(temp2, temp1 ,"+");
		}
		if(operators.getTop()=="-" )
		{
			operate(temp2, temp1 ,"-");
		}
		if(operators.getTop()=="*" )
		{
			operate(temp2, temp1 ,"*");
		}
		if(operators.getTop()=="*" )
		{
			operate(temp2, temp1 ,"*");
		}
		if(operators.getTop()=="/" )
		{
			operate(temp2, temp1 ,"/");
		}
	}
}
/**
  *Change string into Complex
  *@param spot 
  *@return Complex
**/
Complex intoComplex(string spot)
{
	int index = 1;
	string temp1 = "";
	string temp2 = "";
	while(index<spot.length())
	{
		char sign = ' ';

		if(spot[index]!='+' || spot[index]!='-')
		{
			temp1=temp1+spot[index];
			//flag=false;
		}
		index++;
	}
	index = spot.length();
	while(index>0)
	{
		if(spot[index]=='i')
		{
			index--;
			if(spot[index]=='+' || spot[index]=='-')
			{
				temp2 = "1";
				break;
			}
			
			temp2 = temp2 + spot[index];
		}
		index--;
		
	}
		int i;
		istringstream(temp1)>>i;
		int p;
		istringstream(temp2)>>p;
		Complex val(i,p,1);
		return val;
	
}
//Global varible
	StackDoublyLinkedList<string> operators;
	StackDoublyLinkedList<Complex> oprands;
	StackDoublyLinkedList<string> all;
	StackDoublyLinkedList<Complex> complex;
	StackDoublyLinkedList<string> all2;
	
/**
*Split up the real and image.
*@param myString 
*@return void
**/
void justDoIt2(string myString)
{
	string express = myString;
	cout<<express<<endl;

	//push ALL Operators and Oprands into one stack.
	pushingEverything(all,express);
	cout<<"all: "<<endl;
	all.displayList();

	//operators.getTop();
	//push ONE into Operators or Oprands.
	//return 1 if Operator
	//return 0 if Oprands
//	pushOne(all,operators,oprands);
	
	while(!all.isEmpty())
	{
		if(all.getTop()=="=")
		{
			all.popFront();
		}
		if(all.getTop()=="i")
		{
			all.popFront();
			if(all.getTop()=="+" || all.getTop()=="-")
			{
				if(all.getTop()=="+")
				{
					all.popFront();
					string s = all.getTop();
					int i;
					istringstream(s)>>i;
					Complex com(i, 1, 1);
					all2.addFront(com.toString());
				}
				else
				{
					all.popFront();
					string s = all.getTop();
					int i;
					istringstream(s)>>i;
					Complex com(i, -1, 1);
					all2.addFront(com.toString());
				}
			}
			else
			{
				string s = all.getTop();
				int i;
				istringstream(s)>>i;
				all.popFront();
				if(all.getTop()=="+")
				{
					all.popFront();
					s = all.getTop();
					int j;
					istringstream(s)>>j;
					
					Complex com(j, i, 1);
					all2.addFront(com.toString());
				}
				else
				{
					all.popFront();
					s = all.getTop();
					int j;
					istringstream(s)>>j;
					
					Complex com(j, -i, 1);
					all2.addFront(com.toString());
				}
			}
		}
		//all.displayList();
		if(all.getTop()=="*" || all.getTop()=="/" || all.getTop()=="%" || all.getTop()=="+" || all.getTop()=="-")
		{
			//string s(1,operators.getTop());
			all2.addFront(all.getTop());
			//all.popFront();
		}
		if(all.getTop()=="(" || all.getTop()==")")
		{
			//string s(1,operators.getTop());
			all2.addFront(all.getTop());
			//all.popFront();
		}
		
		all.popFront();
	}
	cout<<endl;
	cout<<endl;
}

/**
  *Function that does all the Calculation.
  *
  *@return Complex
**/
Complex start1()
{	
	cout<<"all2"<<endl;
	all2.displayList();

while(!all2.isEmpty())
{
		if(all2.getTop()=="(" || all2.getTop()==")" || all2.getTop()=="+" 
		|| all2.getTop()=="-" || all2.getTop()=="*" || all2.getTop()=="/")
		{
			operators.addFront(all2.getTop());
			all2.popFront();
		}
		else{
			oprands.addFront(intoComplex(all2.getTop()));

			all2.popFront();
		}
		//all2.popFront();
}

if(operators.getTop()=="*")
{
	Complex temp1 = oprands.getTop();
	oprands.popFront();
	Complex temp2 = oprands.getTop();
	oprands.popFront();
	
	Complex temp = temp1 * temp2;
	return temp;
}
if(operators.getTop()=="/")
{
	Complex temp1 = oprands.getTop();
	oprands.popFront();
	Complex temp2 = oprands.getTop();
	oprands.popFront();
	
	Complex temp = temp2 / temp1;
	return temp;
}
if(operators.getTop()=="+")
{
	Complex temp1 = oprands.getTop();
	oprands.popFront();
	Complex temp2 = oprands.getTop();
	oprands.popFront();
	
	Complex temp = temp2 + temp1;
	return temp;
}
if(operators.getTop()=="-")
{
	Complex temp1 = oprands.getTop();
	oprands.popFront();
	Complex temp2 = oprands.getTop();
	oprands.popFront();
	
	Complex temp = temp2 - temp1;
	return temp;
}
	cout<<"all2"<<endl;
	all2.displayList();
	cout<<"OPERATOR"<<endl;
	operators.displayList();
	cout<<"OPRANDS"<<endl;
	oprands.displayList();
}
int main()
{
	string a;
	string myString = "";
	ifstream input;
	input.open("expression.txt");
	
	ofstream out;
	out.open("result.txt",ios_base::app);
	
	while(getline(input,a))
	{
		myString = a;
		justDoIt2(myString);
		//out<<start1()<<endl;
	}
	
	cout<<"MYANSWER"<<start1()<<endl;
	cout<<"all2"<<endl;
	all2.displayList();
	
	cout<<"all2"<<endl;
	all2.displayList();
	cout<<"OPERATOR"<<endl;
	operators.displayList();
	cout<<"OPRANDS"<<endl;
	oprands.displayList();
	//cout<<start1()<<endl;
	return 0;
}

    
