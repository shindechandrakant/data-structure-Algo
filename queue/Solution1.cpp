#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;
#define ll long long int
#define MOD 1000000007
#define vi vector<ll>
#define pi pair<ll, ll>
#define vb vector<bool>
#define vs vector<string>
#define newline(n) for(int i = 0; i < (n); i++ )cout<<endl;
#define infor(vect) for(auto it : (vect)) { cout<<it<<endl; }
#define ump unordered_map
#define mp map
#define v2d(name, m, n, inti) vector<vi>(name)(m, vi(n, inti))
#define MOD 1000000007

/*
problem statement -> 
Problem link -> 
*/

void print2nd(int arr[], int arr_len) {


	int big = arr[0];
	int secondBig = arr[0];
	int small = arr[0];
	int secondSmall = arr[0];


	for(int i = 1; i < arr_len; i++) {



		// max find
		if(arr[i] > big) {

			secondBig = big;
			big = arr[i];
		}
		else if(secondBig < arr[i]) {

			secondBig = arr[i];
		}

		// minimum find

		if(arr[i] < small) {

			secondSmall = small;
			small  = arr[i];
		}
		else if(secondSmall > arr[i]) {

			secondSmall = arr[i];
		}
	}

	cout<<secondSmall<<", "<<secondBig;
}


int main() {

  freopen("../io/input.txt", "r", stdin);
  freopen("../io/output.txt", "w", stdout);
  auto start = high_resolution_clock::now();

  	int n;
  	cin>>n;

  	int arr[n];

  	for(int i = 0; i < n; i++) {

  		cin>>arr[i];
  	}

  	print2nd(arr, n);










  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout<<"\n\nTime :"<<(duration.count()/1000.0)<<" ms" << endl;
  fclose(stdin);
  fclose(stdout);


}