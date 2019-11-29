#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
#include <string>

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
	
	string temp = "noooo";//to_string(re);
	//string temp = "hello";//"[" + static_cast<char>(re); //+ " + " ;//+ static_cast<char>(im) + "i]/" + static_cast<char>(dem);
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
	Complex com(a.re + b.re, a.im + b.im, 1);
	com.toString();

}


//Find GCD and LCM to reduce fraction and add fraction
int gcd(int a, int b);
int lcm(int a, int b);

#endif
