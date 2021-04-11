#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define MOD 1000000007
#define vi vector<int>

void display(vi &arr) {

	for(auto it : arr)
		cout<<it<<" ";
	cout<<endl;
}

void dividArray(vi &arr, int &maximum, int &minimum, int left, int right) {

	if(left == right) {

		// check for min 
		if(arr[left] > maximum)
			maximum = arr[left];
		// check for min 
		if(arr[left] < minimum)
			minimum = arr[left];
		return;
	}

	int mid = left + ((right - left) / 2);
	// left part
	dividArray(arr, maximum, minimum, left, mid);
	//right part
	dividArray(arr, maximum, minimum, mid + 1, right);
}

void dividAndConqure(vi &arr, int &maximum, int &minimum) {

	dividArray(arr, maximum, minimum, 0, arr.size()-1);
}



int main() {

 	int n;
 	cin>>n;
 	vi arr(n);

  	for (int i = 0; i < n; ++i) cin>>arr[i];
  	int minimum = arr[0];
  	int maximum = arr[0];


  	dividAndConqure(arr, maximum, minimum);
  	display(arr);
  	cout<<"Maximum Element : "<<maximum<<endl;
  	cout<<"Minimum Element : "<<minimum;


}