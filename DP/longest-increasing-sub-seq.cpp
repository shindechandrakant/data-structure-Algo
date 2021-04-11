#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define MOD 1000000007
#define vi vector<int>

void display(int *arr, int n) {

	for(int i = 0; i < n; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}



int longestIncreasingSubsequence(int *arr, int n)
{
	int *lis = new int[n]{ 1 };

	// memset(lis, 1, sizeof(int*n));

	for(int i = 0; i < n; i++)
		lis[0] = 1;

	display(lis, n);
	for(int i = 0; i < n; i++) 
	{
		for(int j = 0; j <= i; j++)
		{
			if(arr[i] > arr[j] ) {

				lis[i] =  max(lis[i], lis[j]+1);
			}
		}
	}

	display(lis, n);

	int ans = *max_element(lis, lis+n);;
	delete []lis;
	return ans;
}

int main() 
{

	cout<<"Hello \a";
	// int n;
	// cin>>n;

	// int *arr = new int[n];
	// for(int i = 0; i < n; i++)
	//   	cin>>arr[i];

	// display(arr, n);
	// cout<<longestIncreasingSubsequence(arr, n);
}

