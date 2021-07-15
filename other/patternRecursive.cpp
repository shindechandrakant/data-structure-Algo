#include<iostream>
using namespace std;


void pattern(int n, int i)
{
	if(n == 0)
		return;

	if(i < n) {

		cout<<"* ";
		pattern(n, i+1);

	} else {

		cout<<endl;
		pattern(n-1, 0);
	}
}



void pattern1(int indx, int row, int n)
{
	if(row == n)
		return;

	// cout<<"pushing -> "<<indx<<" "<<row<<" "<<n<<endl;
	if( indx <= row) 
	{
		cout<<"* ";
		pattern1(indx+1, row, n);
	}
	else
	{
		cout<<endl;
		pattern1(0, row+1, n);
	}
	// cout<<"poping -> "<<indx<<" "<<row<<" "<<n<<endl;
}

int main()
{
	
	int n;
	cin>>n;
	// pattern(n, 0);
	pattern1(0, 0, n);
	return 0;
}

















