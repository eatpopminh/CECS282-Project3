#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
#include <string>
#include <sstream>


using namespace std;

class Complex
{
	public:
		Complex();
		Complex(int r, int i, int d);
		int re;		//real part of a complex number
		int im;		//imaginary part of a complex number
		int dem;	//denominator part of a complex number
		string toString() const;	//Format [re + imi]/dem
		
};

Complex :: Complex()
{
	re = 0;
	im = 0;
	dem = 1;
}
Complex :: Complex(int r, int i, int d)
{
	re = r;
	im = i;
	dem = d;
}
string Complex :: toString() const
{
	stringstream ss;
	string temp;
	ss<<re;
	ss>>temp;
	
	stringstream ss1;
	string temp1;
	ss1<<im;
	ss1>>temp1;
	
	stringstream ss2;
	string temp2;
	ss2<<dem;
	ss2>>temp2;
	if(im<0)
		temp = "[" + temp + temp1 + "i]/" + temp2;
	else
		temp = "[" + temp + "+" + temp1 + "i]/" + temp2;
	
	return temp;
	
}

//Overloading operator for easy arithmetic
Complex operator+(Complex a, Complex b);
Complex operator-(Complex a, Complex b);
Complex operator*(Complex a, Complex b);
Complex operator/(Complex a, Complex b);
ostream& operator<<(ostream& stream, Complex a);

Complex operator+(Complex a, Complex b)
{
	Complex com(a.re + b.re, (a.im)+ (b.im), 1);
	return com;
}
Complex operator-(Complex a, Complex b)
{
	Complex com(a.re - b.re, a.im - b.im, 1);
	return com;
}
Complex operator*(Complex a, Complex b)
{
	Complex com((a.re * b.re)-(a.im*b.im), (a.re*b.im)+(a.im*b.re), 1);
	return com;
}
Complex operator/(Complex a, Complex b)
{
	Complex conjugate(b.re,-(b.im),1);
	int bot = ((b.re)*(b.re))+((b.im)*(b.im));
	//Complex top = a*conjugate;
	Complex top((a.re*b.re) + (a.im*b.im), (a.im*b.re)-(a.re*b.im),1);
	//cout<<bot.toString()<<endl;
	Complex temp(top.re,top.im,bot);
	return temp;
	
}
ostream& operator<<(ostream& stream, Complex a)
{
	stream<< a.toString();
	return stream;
}




//Find GCD and LCM to reduce fraction and add fraction
int gcd(int a, int b);
int gcd(int a, int b)
{
	if(b==0)
		return a;
	return gcd(b, a % b);
}
int lcm(int a, int b);
int lcm(int a, int b)
{
	return (a*b) / gcd(a,b);
}

#endif
