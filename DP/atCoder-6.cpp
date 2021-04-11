#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
#define vi vector<ll>
#define pi pair<ll, ll>
#define v2d(name, m, n, inti) vector<vi>(name)(m, vi(n, inti))

// problem statement -> LCS 
// https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/
// https://atcoder.jp/contests/dp/tasks/dp_f
// Problem link -> 



int LCS(int i, int j, string s, string t)
{
	if(i == s.size() or j == t.size())
		return 0;

	int result = 0;
	if(s[i] == t[j])
		result = 1 + LCS(i+1, j+1, s, t);
	else
		result = max(LCS(i, j+1, s, t), LCS(i+1, j, s, t));

	return result;
}


int main() {

	string s ,t;
	cin>>s>>t;


}