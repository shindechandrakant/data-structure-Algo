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


// 1 2 1 8 3 5 4 1
// log8 = 3

	// 1 2 1 8			3 5 4 1
 //  1 2 	1 8		 
 // 1  2   1  8



int comps = 0;
int functionCall = 0;
void dividArray(vi &arr, int &maximum, int &minimum, int left, int right) {

	if(left == right) {

		comps++;
		// check for min 
		if(arr[left] > maximum)
			maximum = arr[left];

		// check for min 
		if(arr[left] < minimum)
			minimum = arr[left];
		return;
	}

	
	functionCall++;
	int mid = (right + left )/2;

	// left part
	dividArray(arr, maximum, minimum, left, mid);
	//right part
	dividArray(arr, maximum, minimum, mid + 1, right);
}

// 2^log2 n
// n log n



void dividAndConqure(vi &arr, int &maximum, int &minimum) {

	dividArray(arr, maximum, minimum, 0, arr.size()-1);
}



int main() {

 	int n;
 	cin>>n;
 	vi arr(n);

  	for (int i = 0; i < n; ++i) 
  		cin>>arr[i];

  	int minimum = arr[0]; //init 
  	int maximum = arr[0];


  	dividAndConqure(arr, maximum, minimum);

  	cout<<"\n no. of comps : "<<comps<<endl;
  	display(arr);
  	cout<<"\nfunctionCall  "<<functionCall<<endl;
  	cout<<"Maximum Element : "<<maximum<<endl;
  	cout<<"Minimum Element : "<<minimum;




}