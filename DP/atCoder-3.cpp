#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
#define vi vector<ll>
#define pi pair<ll, ll>
// problem link -> https://atcoder.jp/contests/dp/tasks/dp_c

int main() {

	ll n;
	cin>>n;
	vector<vi> v(n, vi(3));
	for(int i = 0; i < n; i++) cin>>v[i][0]>>v[i][1]>>v[i][2];

	vector<vi> dp(n, vi(3, 0));		

	dp[0][0] = v[0][0];
	dp[0][1] = v[0][1];
	dp[0][2] = v[0][2];

	for(int i = 1; i < n; i++) {

		dp[i][0] = v[i][0] + max(dp[i-1][1], dp[i-1][2]);
		dp[i][1] = v[i][1] + max(dp[i-1][0], dp[i-1][2]);
		dp[i][2] = v[i][2] + max(dp[i-1][0], dp[i-1][1]); 
	}

	cout<<max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
}