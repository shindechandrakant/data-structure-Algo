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

ll gcd(ll a, ll b) {

	return b == 0 ? a : gcd(b, a % b);
}

int main() {

  	freopen("../io/input.txt", "r", stdin);
  	freopen("../io/output.txt", "w", stdout);
  	auto start = high_resolution_clock::now();

  	ll t;
  	cin>>t;

  	while(t--) {

  		ll a, b, k;
  		cin>>a>>b>>k;

    if (a == b && k == 0)
    {
        cout << "YES\n";
        return;
    }
    else if (k == 1)
    {
        if (a != b && (a % b == 0 || b % a == 0))
        {
            cout << "YES\n";
            return;
        }
        else
        {
            cout << "NO\n";
            return;
        }
    }
    if (k <= numberOfPrimes(b) + numberOfPrimes(a))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }


  	}
 






  	auto stop = high_resolution_clock::now();
  	auto duration = duration_cast<microseconds>(stop - start);
  	cout<<"\n\nTime :"<<(duration.count()/1000.0)<<" ms" << endl;
  	fclose(stdin);
  	fclose(stdout);
}