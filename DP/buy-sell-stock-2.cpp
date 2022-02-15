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
problem statement -> Buy sell and stocks, infinity transaction allowed
Problem link -> https://www.youtube.com/watch?v=4YjEHmw1MX0
*/


int maxProfitBruteForce(vector<int> &vect) {




	int answer = 0;


	int minimum = vect[0];

	vect.push_back(0);

	for(int i = 1; i < n; i++) {

		if(vect[i] < vect[i-1]) {
			answer += (vect[i-1] - minimum);
			minimum = vect[i];
		}
		minimum = min(minimum, vect[i]);
	}

	return answer;

}


int maxProfitOptimized(vector<int> &vect) {

	int profit = 0;

	for(int i = 1; i < vect.size(); i++) {

		if(vect[i] > vect[i-1])
			profit += (vect[i] - vect[i-1]);
	}


	return profit;
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
