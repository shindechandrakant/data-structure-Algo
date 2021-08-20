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
problem statement ->  lonngest bitonic series which is increasring to certain point and decreases to certain point;
Problem link -> https://www.youtube.com/watch?v=jdfpGSSyN2I&list=PL-Jc9J83PIiEZvXCn-c5UIBvfT8dA-8EG&index=3
*/


vector<int> longestIncreasingSequence(vector<int> &arr) {

	int n = arr.size();

	vector<int> dp(n, 1);
	// int *dp = new int[n] { 1 };


	for(int i = 1; i < n; i++) {

		for(int j = i-1; j >= 0; j--) {

			if(arr[i] > arr[j]) {

				dp[i] = max(dp[i], dp[j]+1);
			}
		}

	}

	return dp;
}

void display(vector<int> &dp) {

	for(auto it : dp) {

		cout<<it<<" ";
	}
	cout<<endl;

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
// 10
// 10 22 9 33 21 50 41 60 80 3

	vector<int> forwardIncresingsqu = longestIncreasingSequence(arr);
	reverse(arr.begin(), arr.end());
	vector<int> reverseIncresingsqu = longestIncreasingSequence(arr);

	int answer = 0;

	display(forwardIncresingsqu);
	display(reverseIncresingsqu);

	for(int i = 0; i < n; i++) {

		answer = max(answer, forwardIncresingsqu[i] + reverseIncresingsqu[n-i-1]- 1);
	}

	cout<<answer;

    fclose(stdin);
    fclose(stdout);

}