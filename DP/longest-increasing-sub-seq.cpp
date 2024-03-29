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
#define infor(vect) for(auto it : (vect)) { cout<<it<<" "; cout<<endl; }
#define ump unordered_map
#define mp map
#define v2d(name, m, n, inti) vector<vi>(name)(m, vi(n, inti))
#define MOD 1000000007

/*
problem statement -> 
Problem link -> 
*/




int longestSubsequence(vector<int> &arr) {

	int n = arr.size();
	vector<int> dp(n, 1);
	int answer = 0;
	for(int i = 1; i < n; i++) {

		for(int j = i-1; j >= 0; j--) {

			if(arr[i] > arr[j]) {

				dp[i] = max(dp[i], dp[j]+1);
			}
		}
	}


	int indx = 0;
	for(int i = 0; i < n; i++) {

		if(answer < dp[i]) {

			answer = dp[i];
			indx = i;
		}
	}

	int counter = answer;
	vector<int> sequence;
	int curr_val = arr[indx];

	for(int i = indx; i >= 0; i--) {

		if(dp[i] == counter and curr_val >= arr[i]) {

			sequence.push_back(arr[i]);
			curr_val = arr[i];
			counter -=1;
		}

	}

	for(int i = answer-1; i >= 0; i--) {

		cout<<sequence[i]<<" ";
	}
	cout<<endl;

	return answer;
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

    cout<<longestSubsequence(arr);
    fclose(stdin);
    fclose(stdout);

}