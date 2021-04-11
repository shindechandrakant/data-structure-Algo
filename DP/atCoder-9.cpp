#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
#define vi vector<ll>
#define pi pair<ll, ll>
#define v2d(name, m, n, inti) vector<vi>(name)(m, vi(n, inti))

// problem statement -> conin propability
// Problem link -> https://atcoder.jp/contests/dp/tasks/dp_i


// recurrence -> f(i-1, x-1) * pi + f(i-1, x) * (1-pi)
//				 p(Head)			p(Tail)
// x == 0 and i == 0 return 1
// i == 0 and x > 0	 return 0


int main() {

	int n;
	cin>>n;
	vector<float>v(n);
	for(int i = 0; i < n; i++)	cin>>v[i];


}