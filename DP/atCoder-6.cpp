#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
#define vi vector<ll>
#define pi pair<ll, ll>
#define vb vector<bool>
#define vs vector<string>
#define newline(n) for(int i = 0; i < (n); i++ )cout<<endl;
#define infor(vect) for(auto it : (vect)) { cout<<it<<endl; }
#define ump unordered_map
#define mp map
#define v2d(name, m, n, inti) vector<vi>(name)(m, vi(n, inti))
#define MOD 1000000007
/*
// problem statement -> LCS 
// https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/
// https://atcoder.jp/contests/dp/tasks/dp_f
// solution link -> https://unacademy.com/class/atcoder-dp-problem-set-2/ZTHRSSE7 
*/


string global;

int LCS(int i, int j, string s, string t, string sof)
{

	if(global.size() < sof.size()) {

		global = sof;
	}

	if(i == s.size() or j == t.size())
		return 0;

	int result = 0;
	if(s[i] == t[j])
		result = 1 + LCS(i+1, j+1, s, t, sof+s[i]);
	else
		result = max(LCS(i, j+1, s, t, sof), LCS(i+1, j, s, t, sof));
	
	return result;
}


int main() {

	freopen("../io/input.txt", "r", stdin);
    freopen("../io/output.txt", "w", stdout);

	string s ,t;
	cin>>s>>t;

	int n = s.size();
	int m = t.size();

	cout<<LCS(0, 0, s, t, "")<<endl;

	vector<vi> dp(n+1, vi(m+1, 0));

	for(int i = 1; i <= n; i++) // s string
	{
		for(int j = 1; j <= m; j++) // t string
		{
			if(s[i-1] == t[j-1]) {

				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else {

				dp[i][j] = max( dp[i-1][j], dp[i][j-1]);
			}
		}
	}

	int ans = dp[n][m];

	int i = n;
	int j = m;

	string str(ans, ' ');


	while( i > 0 and j > 0) {

		if(s[i-1] == t[j-1]) {

			str[ans-1] = s[i-1];
			i--;
			j--;
			ans--;
		}
		else if(dp[i-1][j] > dp[i][j-1]) {

			// upward directon
			i--;
		}
		else {

			// left direction
			j--;
		}
	}

	cout<<str<<endl;
	cout<<global<<endl;
	fclose(stdin);
    fclose(stdout);
}