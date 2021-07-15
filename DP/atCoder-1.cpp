#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
#define vi vector<ll>
// problem link -> https://atcoder.jp/contests/dp/tasks/dp_a


int main() {

  ll n;
  cin>>n;

  vi v(n);
  for(int i = 0; i < n; i++)	cin>>v[i];

  vi dp(n, 0);

	dp[0] = 0;
	dp[1] = abs(v[0] - v[1]);

	for(int i = 2; i < n; i++) {

		dp[i] = min(abs(v[i] - v[i-1]) + dp[i-1], abs(v[i] - v[i-2]) + dp[i-2]);
	}

	cout<<dp[n-1];

}


c








