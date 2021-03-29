#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#include<math.h>
#define vi vector<int>

vi 


int napsack(vi &wt, vi &cost, int tarwt) {

	int n = cost.size();
	vector<int> prev(tarwt+1, 0);
	vector<int> curr(tarwt+1, 0);

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= tarwt; j++)
		{
			if(wt[i-1] <= j) 
			{
				curr[j] = max(prev[j], cost[i-1] + prev[j-wt[i-1]]);
			}
			else {
				curr[j] = prev[j];
			}
		}
		prev.assign(curr.begin(), curr.end());
		fill_n(curr.begin(), curr.end(), 0);
	}

	return prev[tarwt];
}


int knapsackTD(vector<int> &wts, vector<int> &cost, int TW, int n, int i, vector<vector<int> > &dp){
        // Time complexity - O(n * TW)
        // Space complexity - O(n * TW)
        if(i == n) return 0;

        if(dp[i][TW] != 0) return dp[i][TW];

        if(wts[i] <= TW) {
                return dp[i][TW] = max(knapsackTD(wts, cost, TW, n, i+1, dp), knapsackTD(wts, cost, TW - wts[i], n, i+1, dp) + cost[i]);
        } else {
                return dp[i][TW] = knapsackTD(wts, cost, TW, n, i+1, dp);
        }
}


int main() {




}





