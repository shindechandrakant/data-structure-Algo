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

int main() {

	freopen("../io/input.txt", "r", stdin);
	freopen("../io/output.txt", "w", stdout);
	auto start = high_resolution_clock::now();

	int n;
	cin>>n;


	for(int i = 1; i <= n; i++) {

		for(int j = 1; j <= i; j++) {

			if(j < i)
				cout<<i<<"*";
			else
				cout<<i;
		}
		cout<<endl;
	}

	for(int i = n; i >= 1; i--) {

		for(int j = 1; j <= i; j++) {

			if(j < i)
				cout<<i<<"*";
			else
				cout<<i;
		}
		cout<<endl;
	}


	  






	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout<<"\n\nTime :"<<(duration.count()/1000.0)<<" ms";
	fclose(stdin);
	fclose(stdout);
	
	


}