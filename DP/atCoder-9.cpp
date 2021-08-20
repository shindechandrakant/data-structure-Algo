#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
#define vi vector<ll>
#define pi pair<ll, ll>
#define v2d(name, m, n, inti) vector<vi>(name)(m, vi(n, inti))

// problem statement -> conin propability
// Problem link -> https://atcoder.jp/contests/dp/tasks/dp_i


// recurrence -> f(i-1, x-1) * pi + f(i-1, x) * (1-pi)
//				 p(Head)			p(Tail)
// x == 0 and i == 0 return 1
// i == 0 and x > 0	 return 0

double dp[3005][3005];
//dp[i][j] -> probability of getting at least j head


double coins(vector<double> &arr, int i, int x) {

	if(x == 0) return 1;
	else if(i == 0) return 0;

	if(dp[i][x] > -0.9) return dp[i][x];

	return dp[i][x] = arr[i]*coins(arr, i-1, x-1) + (1- arr[i])*coins(arr, i-1, x);
}



int main() {

	freopen("../io/input.txt", "r", stdin);
    freopen("../io/output.txt", "w", stdout);
	int n;
	cin>>n;
	vector<double>arr(n+1);
	memset(dp, -1, sizeof(dp));

	for(int i = 0; i < n; i++) {

		cin>>arr[i+1];
	}
	cout<<fixed<<setprecision(10) <<coins(arr, n, n/2+1);

	fclose(stdin);
	fclose(stdout);

}