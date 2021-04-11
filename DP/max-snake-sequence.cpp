#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
#define vi vector<ll>
#define pi pair<ll, ll>
#define v2d(name, m, n, inti) vector<vi>(name)(m, vi(n, inti))

// problem statement -> max snak sequence
// Problem link -> https://www.geeksforgeeks.org/find-maximum-length-snake-sequence/


bool isItSafe(int i, int j, vector<vi> &grid) {

	return i >= 0 and j >= 0 and i < grid.size() and j < grid[0].size();
}

int snakePath(int i, int j, vector<vi> &grid) {


	if(not isItSafe(i, j, grid))	return 0;

	cout<<grid[i][j]<<" ";
	int result1 = 0;
	int result2 = 0;
	if(j+1 < grid[i].size() and (grid[i][j] == grid[i][j+1] + 1 or grid[i][j] == grid[i][j+1] - 1))
		result1 = 1 + snakePath(i, j+1, grid);
	if(i+1 < grid.size() and (grid[i][j] == grid[i+1][j] + 1 or grid[i][j] == grid[i+1][j] - 1))
		result2 = 1 + snakePath(i+1, j, grid);
	return max(result2, result1);
}


int main() {

	int n, m;
	cin>>n>>m;

	v2d(grid, n, m, 0);

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin>>grid[i][j];

	int  ans = 0;

	for(int i = 0; i < m; i++) {
		ans = max(ans, snakePath(0, i, grid));
		cout<<endl;

	}
	cout<<endl;
	cout<<ans;
}

