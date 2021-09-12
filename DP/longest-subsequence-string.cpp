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
// Problem link -> 


// LCS Recursion method
// TC -> exponential 2^(n+m)
// space o(max(l1, l2))
int rcmp = 0;
int LCSRecursion(int i, int j, string a, string b) {

	if(i == a.size() or j == b.size())
		return 0;

	rcmp++;
	if(a[i] == b[j])
		return 1 + LCSRecursion(i+1, j+1, a, b);
	else
		return max(LCSRecursion(i, j+1, a, b), LCSRecursion(i+1, j, a, b));
}

int bcmp = 0;
int LCSBacktracking(int i, int j, string a, string b, vector<vi> &dp) {

	if(i == a.size() or j == b.size())
		return 0;

	if(dp[i][j] != -1)
		return dp[i][j];

	bcmp++;
	if(a[i] == b[j])
		return dp[i][j] = 1 + LCSBacktracking(i+1, j+1, a, b, dp);
	else
		return dp[i][j] = max(LCSBacktracking(i, j+1, a, b, dp), LCSBacktracking(i+1, j, a, b, dp));
}

// Dynamic profile appnroach
// time complexity O(n^2)
// space complexity O(n^2)
int LCSDynamicProgramming(string a, string b) 
{

	v2d(dp, a.size()+1, b.size()+1, 0);

	for(int i = 1; i <= a.size(); i++)
	{
		for(int j = 1; j <= b.size(); j++)
		{
			if(a[i-1] == b[j-1])
				dp[i][j] = 1 + dp[i-1][j-1];
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}

	// int i = a.size();
	// int j = b.size();

	// string ans;
	// while(i > 0 and j > 0)
	// {

	// }


	return dp[a.size()][b.size()];
}

int main() {


    freopen("../io/input.txt", "r", stdin);
    freopen("../io/output.txt", "w", stdout);

	string a, b;
	cin>>a>>b;
	string ans = "";
	v2d(dp, a.size()+1, b.size()+1, -1);
	cout<<"ans: "<<LCSRecursion(0, 0, a, b)<<" Recursion calls: "<<rcmp<<endl;
	cout<<"ans: "<<LCSBacktracking(0, 0, a, b, dp)<<" Backtracking calls: "<<bcmp<<endl;
	cout<<"ans: "<<LCSDynamicProgramming(a, b)<<" Dynamic Programming";;;;;;;;




    fclose(stdin);
    fclose(stdout);

}
