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
Problem link -> https://codeforces.com/problemset/problem/500/A
*/

int main() {

  // freopen("../io/input.txt", "r", stdin);
  // freopen("../io/output.txt", "w", stdout);
  // auto start = high_resolution_clock::now();


  	ll n, target;
  	cin>>n>>target;

  	vi vect(n);

  	for(int i = 0; i < n; i++) {

  		cin>>vect[i];
  	}

  	bool isItPossible = false;

  	int curr = 0;

  	while(curr < n && vect[curr] != 0) {

  		curr += vect[curr];
  		if(curr == target-1) {

  			isItPossible = true;
  			break;
  		}
  		else if(curr > target) {

  			break;
  		}
  		
  	}



  	cout<< (isItPossible ? "YES" : "NO");











  // auto stop = high_resolution_clock::now();
  // auto duration = duration_cast<microseconds>(stop - start);
  // cout<<"\n\nTime :"<<(duration.count()/1000.0)<<" ms" << endl;
  // fclose(stdin);
  // fclose(stdout);


}