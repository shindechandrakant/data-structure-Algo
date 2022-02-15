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
problem statement -> divid-2-permutation.cpp
Problem link -> https://codeforces.com/contest/1624/problem/C
*/

int main() {

    #ifndef ONLINE_JUDGE
        freopen("../io/input.txt", "r", stdin);
        freopen("../io/output.txt", "w", stdout);
        freopen("../io/err.txt", "w", stderr);
        auto start = high_resolution_clock::now();
    #endif

  	
  	int t = 1;
  	cin>>t;

  	while(t--) {

  		int n;
  		cin>>n;
  		vector<bool> status(n+1, false);
  		vector<ll> vect(n);

  		for(int i = 0; i < n; i++) {

  			cin>>vect[i];
  		}

  		for(int i = 0; i < n; i++) {

  			while(vect[i] > n) {
  				vect[i] /= 2;
  			}

  			while(vect[i] > 0) {

  				if(!status[vect[i]]) {

  					status[vect[i]] = true;
  					break;
  				} 
  				else {
  					vect[i] /= 2;
  				}
  			}
  		}

  		bool isItPossible = true;
  		for(int i = 1; i <= n; i++) {

  			if(!status[i]) {

  				isItPossible = false;
  				break;
  			}
  		}

  		cout<<(isItPossible ? "YES" : "NO")<<endl;
  





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

