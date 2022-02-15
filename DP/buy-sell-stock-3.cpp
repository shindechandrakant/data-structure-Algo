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
problem statement -> Buy sell and stocks, infinity transaction allowed, k fees
Problem link -> https://www.youtube.com/watch?v=pTQB9wbIpfU
*/


int maxProfitBruteForce(vector<int> &vect, int fees) {

	int n = vect.size();

	int oldBoughtState = -vect[0];
	int oldSoldState = 0;

	for(int i = 1; i < n; i++) {

		int newBoughtState = 0;
		int newSoldState = 0;

		// if we buy at ith Day
		if(oldSoldState - vect[i] > oldBoughtState) {

			newBoughtState = oldSoldState - vect[i];
		}
		else {
			newBoughtState = oldBoughtState;
		}

		// if we Sell at ith day
		if(oldBoughtState + arr[i] - fees > oldSoldState) {

			newSoldState = oldBoughtState + arr[i] - fees;
		}
		else {

			newSoldState = oldSoldState;
		}

		oldSoldState = newSoldState;
		oldBoughtState = newBoughtState;
	}
	return oldSoldState;
}



int main() {

	freopen("../io/input.txt", "r", stdin);
	freopen("../io/output.txt", "w", stdout);
	auto start = high_resolution_clock::now();









	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "\n\nTime :" << (duration.count() / 1000.0) << " ms" << endl;
	fclose(stdin);
	fclose(stdout);


}


