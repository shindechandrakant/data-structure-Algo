#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define MOD 1000000007
#define vi vector<int>

void display(vi &array) {

	for(int i = 0; i < array.size(); i++)
		cout<<array[i]<<" ";

	cout<<endl;
}

int main() {

  int n;
  cin>>n;
  vi array(n);

  for(int i = 0; i < n; i++) {

  	cin>>array[i];
  }

  cout<<"Before Sepration : ";
  display(array);

  int start = 0;
  int end = array.size()-1;

  while(start < end) 
  {
  	if(array[end] < 0) 
  	{
  		if(array[start] > 0) 
  		{
  			swap(array[start], array[end]);
  			end--;
  			start++;
  		}
  		else
  			start++;
  	}
  	else
  		end--;
  }
  cout<<"\nAfter Sepration : ";
  display(array);
}
// Time complexity -> O(n) and space O(1)