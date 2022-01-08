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
#define MOD 1000000007

/*
problem statement -> 
Problem link ->https://codeforces.com/problemset/problem/1342/A
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

    	ll x, y, a, b;
    	cin>>x>>y;
    	// cin.ignore();
    	cin>>a>>b;

    	// cout<<x<<" "<<y<<" "<<a<<" "<<b<<endl;
    	if(x == 0 && y == 0) {

    		cout<<0<<endl;
    		continue;
    	}

    	ll ans = 0;

    	if(a > b) {

    		ans += (min(x, y) * b);
    		ans += (abs(x-y)*a);
    	}
    	else {

    		ans = min((x+y)*a, min(x, y)*b + abs(x-y)*a);

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
