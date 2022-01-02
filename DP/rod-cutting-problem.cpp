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

string rods;
void bruteForceRodCutting(vector<int> values,int rod, int profit, int &answer, string psf) {


	if(rod == 0) {
		if(answer < profit)
			rods = psf;
		answer = max(profit, answer);		
		return;
	}

	if(rod < 0) {

		return;
	}

	for(int i = 0; i < values.size(); i++) {

		bruteForceRodCutting(values,rod-(i+1), profit+values[i], answer, psf + "-" + to_string(i+1));
	}
}


void dpApproach(vector<int> &arr) {

	int n = arr.size();
	vector<int> dp(n+1);
	dp[0] = arr[0];
	dp[1] = max(arr[1], 2*arr[0]);

	for(int i = 2; i < n; i++) {

		dp[i] = arr[i];

		int start = 0;
		int end = i-1;

		while(start <= end) {
			dp[i] = max(dp[i], dp[start]+dp[end]);
			start++;
			end--;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		cout<<dp[i]<<" ";
	}
	cout<<endl;
	cout<<dp[n-1];
}



int main() {

    freopen("../io/input.txt", "r", stdin);
    freopen("../io/output.txt", "w", stdout);
    freopen("../io/err.txt", "w", stderr);

	int n;
	cin>>n;
	vector<int> arr(n);

	for(int i = 0; i < n; i++) {

		cin>>arr[i];
	}

	dpApproach(arr);
	// int answer = 0;
	// bruteForceRodCutting(arr, n, 0, answer, "");
	// cout<<rods<<" "<<answer<<endl;




    fclose(stdin);
    fclose(stdout);
    fclose(stderr);

}