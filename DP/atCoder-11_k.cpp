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
problem statement -> 
Problem link -> https://atcoder.jp/contests/dp/tasks/dp_k
*/


string stones(vi &arr, ll k) {

	vb dp(k+1, false);

	for(int i = 1; i <= k; i++) {

		for(auto val : arr) {

			if(i < val) {
				continue;
			}
			if(not dp[i-val]) {

				dp[i] = true;
			}
		}
	}
	return dp[k] ? "First" : "Second";
}


int main() {

    freopen("../io/input.txt", "r", stdin);
    freopen("../io/output.txt", "w", stdout);

    ll n, k;

    cin>>n>>k;

    vi v(n);

    for(auto &it : v) {

    	cin>>it;
    }


    cout<<stones(v, k);







    fclose(stdin);
    fclose(stdout);

}