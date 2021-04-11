#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
#define vi vector<ll>
#define v2 vector<vi>
#define pi pair<ll, ll>
#define vc vector<vector<char> >
#define v2d(name, m, n, inti) vector<vi>(name)(m, vi(n, inti))

// problem statement -> find paths
// Problem link -> https://atcoder.jp/contests/dp/tasks/dp_h

ll n, m;

bool isItSafe(int i, int j, vc &grid) {

	return i >= 0 and j >= 0 and i < grid.size() and j < grid[i].size() and grid[i][j] == '.';
}


int noOfPaths(int i, int j, vc &grid, v2 &dp) {

	if(not isItSafe(i, j, grid))
		return 0;

	if(dp[i][j] != -1)
		return dp[i][j];


	if(i == n-1 and j == m-1){

		return 1;
	}
	int x = noOfPaths(i, j+1, grid, dp);
	int y = noOfPaths(i+1, j, grid, dp);

	return dp[i][j] = (x % MOD + y % MOD)%MOD;
}


int main() {

	cin>>n>>m;
	vector<vector<char> > grid(n, vector<char> (m));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin>>grid[i][j];


	v2d(dp, n, m, -1);

	noOfPaths(0, 0, grid, dp);
	cout<<dp[0][0];

}