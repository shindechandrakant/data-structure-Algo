#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
#define vi vector<ll>
#define pi pair<ll, ll>
#define v2d(name, m, n, inti) vector<vi>(name)(m, vi(n, inti))

// problem statement -> almost prime
// Problem link -> https://codeforces.com/contest/26/problem/A

int main() {

	ll n;
	cin>>n;
	int result = 0;


	for(ll i = 6; i <= n; i++) {

		unordered_map<int, int>mp;

		ll org = i;
		while(org >= 2) {
			bool isPrime = true;
			for(ll j = 2; j <= i/2; j++) {

				if(org % j == 0) {

					mp[j]++;
					org /= j;
					isPrime = false;
					break;
				}
			}
			if(isPrime) {

				mp[org]++;
				break;
			}
		}

		if(mp.size()==2) {

			result++;
			// cout<<i<<endl;
		}
	} 
	cout<<result;
}