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
bool cmp(pair<int, int> p1, pair<int, int> p2) {

	if(p1.first == p2.first) {

		return p1.second > p2.second;
	}

	return p1.first < p2.first;
}


void bad(int* arr, int n) {

	vector<pair<int, int> > newV(n);

	for(int i = 0; i < n; i++) {

		newV[i] = {arr[i], i};
	}

	sort(newV.begin(), newV.end(), cmp);


	for(int i = 0; i < n; i++) {

		cout<<newV[i].first<<"  "<<newV[i].second<<endl;
		arr[newV[i].second] = i+1;
	}
	cout<<endl<<endl;
	for(int i = 0; i < n; i++) {

		cout<<arr[i]<<" ";
	}
}



int main() {

    freopen("../io/input.txt", "r", stdin);
    freopen("../io/output.txt", "w", stdout);


	int n;
	cin>>n;

	int arr[n];

	for(int i = 0; i < n; i++) {

		cin>>arr[i];
		// cout<<arr[i]<<" ";
	}


	bad(arr, n);
    fclose(stdin);
    fclose(stdout);
}