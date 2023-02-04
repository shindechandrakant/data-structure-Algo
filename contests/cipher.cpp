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
problem statement -> cipher.cpp
Problem link -> https://codeforces.com/contest/1703/problem/C
*/



int main() {

    #ifndef ONLINE_JUDGE
        freopen("../io/input.txt", "r", stdin);
        freopen("../io/output.txt", "w", stdout);
        freopen("../io/err.txt", "w", stderr);
        auto start = high_resolution_clock::now();
    #endif

  	
  	int t;
  	cin>>t;

  	while(t--) {

  		int wheels;
  		cin>>wheels;

  		vector<int> init(wheels);
  		for(auto &it : init) {

  			cin>>it;
  		}

  		for(int i = 0; i < wheels; i++) {

  			int n;
  			cin>>n;
  			string moves;
  			cin>>moves;

  			int number = init[i];

  			for(auto ops : moves) {


  				if(ops == 'D') {

  					if(number == 9) {
  						number = 0;
  					}
  					else {

  						number += 1;
  					}
  				}
  				else {

  					if(number == 0) {
  						number = 9;
  					}
  					else {

  						number -= 1;
  					}

  				}
  			}


  			cout<<number<<" ";
  		}
  		cout<<endl;
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

