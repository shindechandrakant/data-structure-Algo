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
Problem link -> https://codeforces.com/contest/1624/problem/B
*/

int main() {

    #ifndef ONLINE_JUDGE
        freopen("../io/input.txt", "r", stdin);
        freopen("../io/output.txt", "w", stdout);
        freopen("../io/err.txt", "w", stderr);
        auto start = high_resolution_clock::now();
    #endif

  	
  	
  	// cout<<"Hello, I'm Running : makr-app.cpp";
  	int t = 1;
  	cin>>t;

  	while(t--) {

  		ll a, b, c;
  		cin>>a>>b>>c;
  		

        // first term
        ll ft = (2*b) - c;

        if(ft > 0 && ft % a == 0) {

            cout<<"YES\n";
            continue;
        } 

        ll st = c + a;
        if((st % (2*b)) == 0) {

            cout<<"YES\n";
            continue;
        }

        ll ct = (2 * b) - a;
        if(ct > 0 && ct % c == 0) {

            cout<<"YES\n";
            continue;
        }

  		cout<<"NO\n";


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

