
// problem Link -> https://codeforces.com/contest/1399/problem/B

#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#include<math.h>

int main() {

	int t;
	cin>>t;

	while(t--)
	{
		int n;
		cin>>n;
		vector<long long int>candy(n);
		vector<long long int>orange(n);
		long long int candMin = 0;
		long long int orangeMin = 0;
		for(int i= 0; i < n; i++) {
			cin>>candy[i];
			if(i == 0) {
				candMin = candy[0];
			}
			if(candMin > candy[i])
				candMin = candy[i];
		}

		for(int i= 0; i < n; i++) {

			cin>>orange[i];
			if(i == 0) {
				orangeMin = orange[0];
			}
			if(orange[i] < orangeMin ) {
				orangeMin = orange[i];
			}
		}

		long long int ans = 0;

		for(int i = 0; i < n; i++) {

			long long int od = orange[i] - orangeMin;
			long long int cd = candy[i] - candMin;

			if(cd > od)
				ans += cd;
			else 
				ans += od;
		}
		cout<<ans<<endl;

	}

}








