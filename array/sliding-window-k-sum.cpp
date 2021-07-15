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
// Problem link -> https://practice.geeksforgeeks.org/tracks/ppc-arrays/?batchId=221

int main() {

	freopen("../io/input.txt", "r", stdin);
    freopen("../io/output.txt", "w", stdout);

	int n, k;
	cin>>n>>k;
	vector<int> arr(n);

	for(int i = 0; i < n; i++) {
		cin>>arr[i];
		// cout<<arr[i]<<" ";
	}
	// cout<<endl;

	int firstK = 0;

	for(int i = 0; i < k; i++)
		firstK += arr[i];

	int maxSum = firstK;

	int ans = maxSum;
	// cout<<0<<" "<<k<<" "<<ans<<endl;
	for(int i = 1; i+k < n; i++) {

		maxSum =  maxSum - arr[i-1] + arr[i+k-1];
		// cout<<arr[i+k]<<" ";
		ans = max(maxSum, ans);
		// cout<<i<<" "<<i+k<<" : "<<arr[i+k-1]<<" "<<maxSum<<endl;
	}
	cout<<ans;


	
    fclose(stdin);
    fclose(stdout);
}
