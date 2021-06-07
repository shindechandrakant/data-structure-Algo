#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
#define vi vector<ll>
#define pi pair<ll, ll>
#define v2d(name, m, n, inti) vector<vi>(name)(m, vi(n, inti))

// problem statement -> 
// Problem link->  geeksforgeeks.org/count-subsequences-product-less-k/

int main() {

	int n, k;
	cin>>n>>k;

	vi arr(n);

	for(auto &it : arr)
		cin>>it;

	int dp[k+1][n+1];

	memset(dp, 0, sizeof(dp));


	for(int i = 1; i <= k; i++) {

		for(int j = 1; j <= n; j++) {

			dp[i][j] = dp[i][j-1];

			if(arr[j-1] <= i and arr[j-1] > 0) {

				dp[i][j] += (dp[i/arr[j-1]][j-1] + 1);
			}
		}
	}


	cout<<dp[k][n];



}