#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;

namespace manipulator
{
	ostream &output(ostream &manipulator)
	{
		manipulator<<"Enter a number ";
		return manipulator;
	}
	istream &input(istream &in)
	{
		int x;
		in>>x;
		cout<<in;
		return in;
	}
}

using namespace manipulator;

int main()
{
	cout.fill('*');
	cout.width(15);
	cout.setf(ios::left,ios::adjustfield);
	cout<<"Chandu";
	/*
			OUTPUT
		Chandu*********
	*/
	cout<<endl<<output;
	cin>>input;
	cout<<input;
}




