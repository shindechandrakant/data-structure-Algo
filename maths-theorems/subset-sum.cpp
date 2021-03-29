#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define MOD 1000000007
#define vi vector<int>

// Given a set of non-negative integers, and a value 
// sum, determine if there is a subset of the given 
// set with sum equal to given sum. 

// link -> https://www.geeksforgeeks.org/subset-sum-problem-dp-25/



// Brute Force Approach
// complexity 2^n

int BFF = 0;
bool isSubsetSum(vi &set, int n, int sum, int target) {


	// cout<<sum<<" ";
	if(sum == target)
		return true;

	if(n == set.size())
		return false;

	if(sum > target)
		return false;

	BFF++;
	return isSubsetSum(set, n + 1, sum, target) ||
		isSubsetSum(set, n + 1, sum + set[n], target); 
}

// Backtracking Approach
// complexity 2^n
bool isSubsetSumBacktracking(vi &set, int index, int csum, int tsum, int target) {

	if(csum == target) {

		return true;
	}
	if(set.size() == index) {

		return false;
	}

	if(csum > target) {
		return false;
	}

	BFF++;


	return  isSubsetSumBacktracking(set, index+1, csum + set[index], tsum - set[index], target) or
		isSubsetSumBacktracking(set, index+1, csum, tsum - set[index], target);
}


// Dynamic Programming approach
// time Complexity O(s * target)
bool isSubsetSumDP(vi &set, int target) {

	int ss = set.size();

	bool **dp = new bool*[set.size()+1]; 

	for(int i = 0; i <= set.size()+1; i++) {

		dp[i] = new bool[target+1] {false};

	}

	for(int i = 0; i <= set.size(); i++)
		dp[i][0] = true;



	for(int i = 0; i <= set.size(); i++)
	{
		for(int j = 0; j <= target; j++) {

			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"\n\n";
	for(int i = 1; i <= ss; i++)
	{
		for(int j = 1; j <= target; j++)
		{

			if(j < set[i-1]) {
				dp[i][j] = dp[i-1][j];
			}
			else {

				dp[i][j] = dp[i-1][j] or dp[i-1][j - set[i-1]];
			}
		}
	}


	cout<<endl<<endl;
for(int i = 0; i <= set.size(); i++)
	{
		for(int j = 0; j <= target; j++) {

			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}





	bool ans = dp[ss][target];
	delete []dp;
	return ans;

}



int main() {

  vi set = { 7, 2, 3 };

  cout<<isSubsetSum(set, 0, 0, 55);
  cout<<" "<<BFF<<endl;
  BFF = 0;
  cout<<endl<<isSubsetSumBacktracking(set, 0, 0, 10, 55);
  cout<<" "<<BFF<<endl<<endl;

  cout<<isSubsetSumDP(set, 5);

}


// Try BackTracking approach
