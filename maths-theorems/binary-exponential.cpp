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


int _power(int n, int power) {

	if(power == 0) {

		return 1;
	}

	int halfPower = _power(n, power/2);

	if(power%2 == 0) {

		return halfPower*halfPower;
	}
	else {

		return halfPower*halfPower*n;
	}
}


int main() {

    freopen("../io/input.txt", "r", stdin);
    freopen("../io/output.txt", "w", stdout);


	int n, power;

	cin>>n>>power;


	for(int i = 0; i < 15; i++) {

		cout<<_power(2, i)<<endl;

	}




    fclose(stdin);
    fclose(stdout);

}