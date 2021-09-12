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
Problem link -> 
*/

int _power(int n, int power) {

	if(power == 0) {

		return 1;
	}

	int halfPower = _power(n, power/2);

	if(power%2 == 0) {

		return ((halfPower %MOD) * (halfPower % MOD))%MOD;
	}
	else {

		return ((halfPower % MOD) * (halfPower % MOD) * (n % MOD)) % MOD;
	}
}





int main() {

  freopen("../io/input.txt", "r", stdin);
  freopen("../io/output.txt", "w", stdout);
  auto start = high_resolution_clock::now();


  
  int t;
  cin>>t;
  long mod = 1000000007;

  while(t--) {

  	int n, k;
  	cin>>n>>k;

  	long long int answer = _power(n, k);


  	for(int i = 1; i <= n/2; i++) {

  		if(n % i == 0) {

  		  	answer = (answer%MOD * _power(i, k)%MOD) %MOD;
  		 }
  	}

  	cout<<answer<<endl;


  }















  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout<<"\n\nTime :"<<(duration.count()/1000.0)<<" ms" << endl;
  fclose(stdin);
  fclose(stdout);


}