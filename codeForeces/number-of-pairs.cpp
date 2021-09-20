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
Problem link -> https://codeforces.com/problemset/problem/1538/C
*/

int main() {

  // freopen("../io/input.txt", "r", stdin);
  // freopen("../io/output.txt", "w", stdout);
  // auto start = high_resolution_clock::now();

  	int t;
  	cin>>t;

  	while(t--) {

		ll n, left, right;
		cin>>n>>left>>right;

		vector<ll> vect(n);

		for(int i = 0; i < n; i++) {

			cin>>vect[i];
		}

		sort(vect.begin(), vect.end());

		ll answer = 0;

		for(int i = 0; i < n; i++) {

			int lower = abs(vect[i]-left);
			int upper = abs(vect[i]-right);

			auto lo_bound = lower_bound(vect.begin()+i+1, vect.end(), lower);
			auto up_bound = upper_bound(vect.begin()+i+1, vect.end(), upper);

			ll diff = abs((lo_bound - vect.begin()+1) - (up_bound - vect.begin() + 1));

			// cout<<vect[i]<<" "<<diff<<endl;
			answer += diff;
		}
		cout<<answer<<endl;
	}










  // auto stop = high_resolution_clock::now();
  // auto duration = duration_cast<microseconds>(stop - start);
  // cout<<"\n\nTime :"<<(duration.count()/1000.0)<<" ms" << endl;
  // fclose(stdin);
  fclose(stdout);


}

