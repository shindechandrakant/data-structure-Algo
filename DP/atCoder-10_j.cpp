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
// Problem link -> https://atcoder.jp/contests/dp/tasks/dp_j
/*	expection  = probability of the event * no. of times the event occur	*/

double dp[302][302][302];


double sushi(ll one, ll two, ll three, ll n) {

	if(one < 0 or two < 0 or three < 0) {	return 0;	}

	if(one == 0 and two == 0 and three == 0) return 0;

	if(dp[one][two][three] > -0.9) {

		return dp[one][two][three];
	}

	double expo = n + one*sushi(one-1, two, three, n) + two * sushi(one+1, two-1, three, n) + three*sushi(one, two+1, three-1, n);

	return dp[one][two][three] = expo / (one+two+three);
}

int main() {


	freopen("../io/input.txt", "r", stdin);
    freopen("../io/output.txt", "w", stdout);

	ll n;
	cin>>n;
	
	memset(dp, -1, sizeof(dp));
	ll one = 0, two = 0, three = 0;

	for(int i = 0; i < n; i++) {

		int x;
		cin>>x;

		if(x == 1) one++;
		else if(x == 2) two++;
		else three++;
	}

	cout<<fixed<<setprecision(10)<<sushi(one, two, three, n);

	fclose(stdin);
	fclose(stdout);
}