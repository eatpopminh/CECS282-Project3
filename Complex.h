#include<iostream>

using namespace std;

class Complex
{
	public:
		Complex();
		Complex(int r, int i, int d);
		int re;		//real part of a complex number
		int im;		//imaginary part of a complex number
		int dem;	//denominator part of a complex number
		string toString() cosnt;	//Format [re + imi]/dem
		
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

