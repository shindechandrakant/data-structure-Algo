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
problem statement -> 
Problem link -> https://cses.fi/problemset/task/1623
*/


ll sum = 0;
ll minE = INT_MAX;


ll min(ll a, ll b) {

	return a > b ? b : a;
}

void getMinDiff(ll indx, ll num, vector<ll> &arr, string ssf, ll total, ll length) {

	minE = min(minE, abs(sum - total - total));
	if(num <= 0) {

		// cout<<length<<" "<<total<<" "<<num<<" ";
		// cout<<ssf<<endl;
		return;
	}

	for(int i = indx; i < arr.size(); i++) {

		getMinDiff(i+1, num-arr[i], arr, ssf + to_string(arr[i]) + "-", total+arr[i], length+1);

	}


}



int main() {

    #ifndef ONLINE_JUDGE
        freopen("../io/input.txt", "r", stdin);
        freopen("../io/output.txt", "w", stdout);
        auto start = high_resolution_clock::now();
    #endif

  	int n;
  	cin>>n;
  	vector<ll> arr(n);

  	for(auto &it : arr) {

  		cin>>it;
  		sum += it;
  	}


  	// cout<<sum<<endl;

  	getMinDiff(0, sum/2, arr, "", 0, 0);

  	// if(sum&1)
  	// 	minE += 1;

  	cout<<minE;



  	// if(sum % 2 == 0) {

  	// 	cout<<0;
  	// }
  	// else {

  	// 	cout<<small;
  	// }













    #ifndef ONLINE_JUDGE
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout<<"\n\nTime :"<<(duration.count()/1000.0)<<" ms" << endl;
        fclose(stdin);
        fclose(stdout);
    #endif


}