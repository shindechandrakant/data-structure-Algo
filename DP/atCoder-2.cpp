#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
#define vi vector<ll>
// problem link -> https://atcoder.jp/contests/dp/tasks/dp_b

int main() {

	
	ll n, k;
	cin>>n>>k;
	vi v(n);
	for(int i = 0; i < n; i++)	cin>>v[i];

	vi dp(n);
	dp[0] = 0;
	dp[1] = abs(v[1] - v[0]);


	for(int i = 2; i < n; i++) {

		ll temp = INT_MAX;
		for(int j = 1; j <= k; j++) {
			if(i - j < 0)
				break;

			temp = min( abs(v[i] - v[i-j]) + dp[i-j], temp);

		}

		dp[i] = temp;
	}

	cout<<dp[n-1];

}