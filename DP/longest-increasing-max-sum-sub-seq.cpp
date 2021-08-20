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
Problem link -> 
*/


pair<int, int> maxSumIncreasingSubsequence(vector<int> &arr) {

	int n = arr.size();

	int sum = 0;
	vector<pair<int, int> > dp(n, {1, 0});

	// first -> length
	// second -> sum

	for(int i = 0; i < n; i++) {

		dp[i].second = arr[i];

		for(int j = i-1; j >= 0; j--) {

			if(arr[i] >= arr[j] and dp[i].second < (dp[j].second + arr[i])) {

				dp[i] = { , dp[j].second + arr[i] };
			}


		}

	}



	return sum;
}



int main() {

    freopen("../io/input.txt", "r", stdin);
    freopen("../io/output.txt", "w", stdout);

    int n;
    cin>>n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++) {

    	cin>>arr[i];
    }

    cout<<maxSumIncreasingSubsequence(arr);

    fclose(stdin);
    fclose(stdout);

}