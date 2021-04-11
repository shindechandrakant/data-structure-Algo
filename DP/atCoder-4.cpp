#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
#define vi vector<ll>
#define pi pair<ll, ll>
#define v2d vector<vi>


int main() {


	ll n, cap;
	cin>>n>>cap;

	vi weight(n);
	vi value(n);

	for(int i = 0; i < n; i++)	cin>>weight[i]>>value[i];

	v2d dp(n+1, vi(cap+1, 0));

	for(ll i = 1; i <= n; i++) {

		for(ll j = 1; j <= cap; j++) {

				if(j < weight[i-1]) 
					dp[i][j] = dp[i-1][j];
				else
					dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i-1]] + value[i-1]);
		}
	}

	cout<<dp[n][cap];
}