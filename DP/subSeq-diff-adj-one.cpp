#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
#define vi vector<ll>
#define pi pair<ll, ll>
#define v2d(name, m, n, inti) vector<vi>(name)(m, vi(n, inti))

// problem statement -> Longest subsequence such that difference between adjacents is one
// Problem link -> https://practice.geeksforgeeks.org/problems/longest-subsequence-such-that-difference-between-adjacents-is-one4724/1

// partially correct
int longestSubsequence(int n, vi &arr) {

    int ans = 0;
	for(int i = 0; i < n; i++) {

		int last = arr[i];
		int temp = 1;

		for(int j = i+1; j < n; j++) {

			if(abs(last-arr[j]) == 1) {
				last = arr[j];
				temp++;
			}
		}
		if(temp > ans)
			ans = temp;
	}
	return ans;
}

int main() {

	int n;
	cin>>n;

	vi arr(n);

	for(auto &it: arr) {
		cin>>it;
	}

	vi dp(n+1, 1);

	for(int i = 1; i < n; i++) {

		for(int j = i; j >= 0; j--) {

			if(arr[i] == arr[j]-1 or arr[i] == arr[j]+1) {

				dp[i] = max(dp[i], dp[j]+1);
			}
		}
	}
	cout<<(*max_element(dp.begin(), dp.end()));
}