#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define MOD 1000000007
#define vi vector<int>

int main() 
{
	int t;
	cin>>t;

	for(int tt = 1; tt <= t; tt++)
	{
		int n, cost;
		cin>>n>>cost;
		int atMax = n * 2 - 2;
		int atMin = n - 1;
		if(cost > atMax or cost < atMin) {
			cout<<"Case #"<<tt<<": "<<"IMPOSSIBLE"<<endl;
			continue;
		}

		if(atMin == cost) {

			cout<<"Case #"<<tt<<": ";

			for(int i = 1; i <= n; i++)
				cout<<i<<" ";

			cout<<endl;
			continue;
		}

		if(atMax == cost) {

			cout<<"Case #"<<tt<<": ";

			for(int i = n; i >= 1; i--)
				cout<<i<<" ";

			cout<<endl;
			continue;
		}







	}












  

}