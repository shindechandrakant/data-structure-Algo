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
problem statement -> Buy sell and stocks, one transaction allowed
Problem link -> https://www.youtube.com/watch?v=4YjEHmw1MX0
*/


int maxProfitBruteForce(vector<int> &vect) {


	int answer = 0;
	int n = vect.size();

	vector<int> dp(n, 0);

	int mini = vect[0];

	for(int i = 0; i < n; i++) {

		mini = min(mini, vect[i]);
		dp[i] = mini;
	}

	for(int i = 0; i < n; i++) {

		answer = max(answer, vect[i] - dp[i]);
	}
	return answer;
}


int maxProfitOptimized(vector<int> &vect) {

	int answer = 0;

	int least = vect[0];

	for(int i = 0; i < vect.size(); i++) {

		if(vect[i] > least)
			least = vect[i];

		int profitToday = vect[i] - least;
		answer = max(answer, profitToday);
	}

	return answer;
}





int main() {

	freopen("../io/input.txt", "r", stdin);
	freopen("../io/output.txt", "w", stdout);
	auto start = high_resolution_clock::now();


  








	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout<<"\n\nTime :"<<(duration.count()/1000.0)<<" ms" << endl;
	fclose(stdin);
	fclose(stdout);


}
