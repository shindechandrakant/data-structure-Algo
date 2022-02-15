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
problem statement -> shift-rows.cpp
Problem link -> source
*/




void shiftRowZeros(vector<int> &arr) {

	int n = arr.size();

	for(int i = 0; i < n; i++) {

		int end = i;
		int start = i;
		while(end < n && arr[end] == 0) {
			end++;
		}
		while(end < n) {
			arr[start] = arr[end];
			start++;
			end++;
		}
		while(start < n) {
			arr[start] = 0;
			start++;
		}
	}
}

void addRowElements(vector<int> &arr) {

	int n = arr.size();

	shiftRowZeros(arr);
	for(int i = 0; i < n-1; i++) {

		if(arr[i] == arr[i+1]) {

			arr[i] += arr[i+1];
			arr[i+1] = 0;
		}

	}
	shiftRowZeros(arr);
}

void printArray(vector<int> &arr) {

	for(auto it: arr) {

		cout<<it<<" ";
	}
	cout<<endl;
}




int main() {

    #ifndef ONLINE_JUDGE
        freopen("../io/input.txt", "r", stdin);
        freopen("../io/output.txt", "w", stdout);
        freopen("../io/err.txt", "w", stderr);
        auto start = high_resolution_clock::now();
    #endif

  	int t;
  	cin>>t;
  		int n;
	  	cin>>n;

  	while(t--) {


	  	vector<int> arr(n);

	  	for(int i = 0; i < n; i++) {

	  		cin>>arr[i];
	  	}


	  	addRowElements(arr);
	  	printArray(arr);
  	}




    #ifndef ONLINE_JUDGE
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout<<"\n\nTime :"<<(duration.count()/1000.0)<<" ms" << endl;
        fclose(stdin);
        fclose(stdout);
        fclose(stderr);
    #endif
}

