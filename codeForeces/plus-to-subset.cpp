
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
problem statement -> Statement
Problem link -> https://codeforces.com/contest/1624/problem/0
*/

int main() {

    #ifndef ONLINE_JUDGE
        freopen("../io/input.txt", "r", stdin);
        freopen("../io/output.txt", "w", stdout);
        freopen("../io/err.txt", "w", stderr);
        auto start = high_resolution_clock::now();
    #endif

  	
  	
  	// cout<<"Hello, I'm Running : plus-to-subset.cpp";
  	int t = 1;
  	cin>>t;

  	while(t--) {

  		int n;
  		cin>>n;

  		ll mini;
  		ll maxi;

  		cin>>mini;
  		maxi = mini;
  		for(int i = 1; i < n; i++) {

  			ll x;
  			cin>>x;
  			mini = min(mini, x);
  			maxi = max(maxi, x);
  		}

  		cout<<maxi-mini<<endl;



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

