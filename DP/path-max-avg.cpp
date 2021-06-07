#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
#define vi vector<ll>
#define pi pair<ll, ll>
#define v2d(name, m, n, inti) vector<vi>(name)(m, vi(n, inti))

// problem statement -> Path with maximum average value
// Problem link -> geeksforgeeks.org/path-maximum-average-value/

int main() {

	int n;
	cin>>n;
	v2d(grid, n, n, 0);

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin>>grid[i][j];

	vector<vector<pi>> dp(n, vector<pi>(n, { 0, 0 }));

	dp[0][0] = { grid[0][0], 1};

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++) 
		{
			if(i == 0 and j == 0) { continue; }

			if(i == 0) {
				// 1st row only one way to reach
				dp[i][j] = { dp[i][j-1].first + grid[i][j], dp[i][j-1].second+1 };
			}
			else if(j == 0) {
				dp[i][j] = { dp[i-1][j].first + grid[i][j], dp[i-1][j].second+1 };
			}
			else {

				// top to down
				float down = (dp[i-1][j].first + grid[i][j]) / (dp[i-1][j].second+1);
				// left to right
				float side = (dp[i][j-1].first + grid[i][j]) / (dp[i][j-1].second+1);

				if(down > side) {

					dp[i][j] = { dp[i-1][j].first + grid[i][j], dp[i-1][j].second+1 };
				}
				else {
					dp[i][j] = { dp[i][j-1].first + grid[i][j], dp[i][j-1].second+1 };
				}
			}
		}
	}
	pi temp = dp[n-1][n-1];
	cout<<(((float)temp.first / temp.second));
}