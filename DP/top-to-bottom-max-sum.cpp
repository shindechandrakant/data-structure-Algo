#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
#define vi vector<ll>
#define pi pair<ll, ll>
#define v2d(name, m, n, inti) vector<vi>(name)(m, vi(n, inti))

// problem statement -> By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23
// Problem link -> https://projecteuler.net/problem=18

void printTriangle(vector<vi> &triangle) {


	for(int i = 0; i < triangle.size(); i++) {

		for(int j = 0; j < triangle[i].size(); j++)
			cout<<triangle[i][j]<<" ";

		cout<<endl;

	}



}


int findMaxTopTOBottom(vector<vi> &triangle) {

	int ans=0;
	vector<vector<ll> > dp;
	int n = triangle.size();

	for(int i = 0; i < n; i++) {

		vi temp(i+1, 0);
		dp.push_back(temp);
	}

/*
	  3
	 7 4
    2 4 6
   8 5 9 3
*/


	dp[0][0] = triangle[0][0];

	for(int i = 1; i < n; i++) 
	{

		for(int j = 0; j <= i; j++) {

			if(j == 0) {

				dp[i][j] = dp[i-1][0] + triangle[i][0];
			}
			else if(i == j) {

				dp[i][j] = dp[i-1][j-1] + triangle[i][j];
			}
			else {

				// cout<<dp[i-1][j-1]<<endl;
				// cout<<dp[i-1][j]<<endl;
				dp[i][j] = max(dp[i-1][j-1] + triangle[i][j], dp[i-1][j] + triangle[i][j]);
			}
		}
	}

	for(int i = 0; i < n; i++) {

		if(ans < dp[n-1][i])
			ans = dp[n-1][i];

	}

	// printTriangle(triangle);
	// cout<<endl<<endl;
	// printTriangle(dp);



	return ans;
}






int main() {

	
	vector<vector<ll> > triangle;
	int n;
	cin>>n;

	for(int i = 0; i < n; i++) {

		vi temp(i+1);
		for(int j = 0; j <= i; j++) {

			cin>>temp[j];
		}
		triangle.push_back(temp);
	}

	cout<<findMaxTopTOBottom(triangle);












}