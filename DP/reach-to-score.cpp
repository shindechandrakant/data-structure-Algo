#include<bits/stdc++.h>
#include<iostream>
#include<math.h>
#include<bits/stdc++.h>

using namespace std;

void display(long long int arr[], int n) {

	for(int i = 0; i <= n; i++)
		cout<<arr[i]<<" ";

	cout<<endl;
}


long long int count(long long int n)
{
	long long int table[n+1],i;
	memset(table, 0, sizeof(table));
	table[0] = 1;                 
	// If 0 sum is required number of ways is 1.


    
    for (i = 3; i <= n; i++) 
    table[i] += table[i - 3]; 
      display(table, n);
    for (i = 5; i <= n; i++) 
    table[i] += table[i - 5]; 
      display(table, n);
    for (i = 10; i <= n; i++) 
    table[i] += table[i - 10]; 
      display(table, n);

	
	return table[n];
}

/*
1 0 0 1 0 1 1 0 2 1 2 3 1 5 4 4 9 5 11 14 11 
11


1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 
1 0 0 1 0 1 1 0 1 1 1 1 1 1 1 2 1 1 2 1 2 
1 0 0 1 0 1 1 0 1 1 2 1 1 2 1 3 2 1 3 2 4 


*/


int main()
{

	cout<<count(20);
	// cout<<"Hello World";


}










