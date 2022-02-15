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
problem statement -> div-7.cpp
Problem link -> https://codeforces.com/contest/1633/problem/A
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

  		string str;
  		cin>>str;

  		int ones = 0;
  		int ans = 0;
  		int zeros = 0;

  		for(int i = 0; i < str.size(); i++) {

  			if(str[i] == '1') {
  				ones++;
  			}
  			else {
  				zeros++;
  			}

  			if(zeros == ones)
  				continue;

  			ans = max(ans, min(ones, zeros));
  		}

  		cout<<ans<<endl;

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

