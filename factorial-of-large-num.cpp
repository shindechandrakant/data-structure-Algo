



// Problem link - https://www.codechef.com/submit/FCTRL2



#include <iostream>
using namespace std;
#include<vector>
#include<bits/stdc++.h>

void calculateFact(int val, vector<int> &num, int &curr_indx)
{
    int carry = 0;
    for(int i = 0; i < curr_indx; i++)
    {
        int multi = num[i] * val + carry;
        
        num[i] = multi % 10;
        carry = multi / 10;
    }
    while(carry) {
        
        num[curr_indx] = carry % 10;
        carry /= 10;
        curr_indx++;
    }
}
void facto(int n)
{
    vector<int>v(300, 1);
    int curr_indx = 1;
    
    for(int i = 2; i <= n; i++) {
        
        calculateFact(i, v, curr_indx);
    }
    for(int i = curr_indx - 1; i >= 0; i--)
    {
        cout<<v[i];
    }
    cout<<endl;
}


int main() {

    int t;
    cin>>t;
    
    while(t--)
    {
       int n;
       cin>>n;
       
       facto(n);
    }
}








/*
// C++ program to compute factorial of big numbers
#include<iostream>
using namespace std;
#define MAX 50



int multiply(int x, int res[], int res_size);

void factorial(int n)
{
	int res[MAX];


	res[0] = 1;
	for(int i = 0; i < MAX; i++) {
		res[i] = 1;
	}
	int res_size = 1;


	for(int x=2; x<=n; x++) {

		for (int i=res_size-1; i>=0; i--)
			cout<<res[i]<<" ";
		
		cout<<endl;
		res_size = multiply(x, res, res_size);

	}

	cout << "Factorial of given number is \n";
	for (int i=res_size-1; i>=0; i--)
		cout << res[i];
}

int multiply(int x, int res[], int res_size)
{
	int carry = 0; 

	for (int i=0; i<res_size; i++)
	{
		int prod = res[i] * x + carry;

		// Store last digit of 'prod' in res[] 
		res[i] = prod % 10; 

		// Put rest in carry
		carry = prod/10; 
	}

	// Put carry in res and increase result size
	while (carry)
	{
		res[res_size] = carry%10;
		carry = carry/10;
		res_size++;
	}

	return res_size;
}


int main()
{
	factorial(5);
	return 0;
}
*/