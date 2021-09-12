#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;
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
problem statement -> count how many distinct subsequences can be formed
Problem link -> https://www.youtube.com/watch?v=9UEHPiK53BA
*/

int main() {

	freopen("../io/input.txt", "r", stdin);
	freopen("../io/output.txt", "w", stdout);
	auto start = high_resolution_clock::now();


	string str;
	cin>>str;
	int n = str.size();

	long *dp = new long [n+1] { 0 };

	map<char, int> mp;


	dp[0] = 1;

	for(int i = 1; i <= n; i++) {

		dp[i] = dp[i-1]*2;


		if(mp.count(str[i-1])) {

			int indx = mp[str[i-1]];

			dp[i] = dp[i] - dp[indx-1];

		}
		mp[str[i-1]] = i;
	}

	cout<<str<<" - "<<dp[n]-1;



	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout<<"\n\nTime :"<<(duration.count()/1000.0)<<" ms" << endl;
	fclose(stdin);
	fclose(stdout);


}