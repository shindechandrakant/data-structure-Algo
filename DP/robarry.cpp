#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define MOD 1000000007
#define vi vector<int>

int main() 
{

	int n;
	cin>>n;

	vi v(n);

	for(int i = 0; i < n; i++) 
		cin>>v[i];

	vi dp(n, 0);

	dp[0] = v[0];
	dp[1] = max(dp[0], dp[1]);


	for(int i = 2; i < n; i++) {

		dp[i] = max(v[i] + dp[i-2], dp[i-1]);

	}

	cout<<dp[n-1];







}