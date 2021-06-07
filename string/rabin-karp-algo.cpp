#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
#define vi vector<ll>
#define pi pair<ll, ll>
#define v2d(name, m, n, inti) vector<vi>(name)(m, vi(n, inti))

// problem statement ->  find the pattern occurance in a text
// Problem link -> 


int hashValue(string &s, int l) {


	int val = 0;
	int ten = 1;
	for(int i = 0; i < l; i++) {

		int ascii = (int)s[i];

		
		int temp = (ascii%MOD * ten%MOD)%MOD;
		val = (val % MOD + temp % MOD) % MOD;
		ten = (ten%MOD * 10) % MOD;
	}

	return val;
}


int main() {


	string text;
	string pattern;
	cin>>text;
	cin>>pattern;
	

	int hvText = hashValue(text, (int)pattern.size());
	int hvPattern = hashValue(pattern, (int)pattern.size());

	cout<<hvText<<endl;
	cout<<hvPattern<<endl<<endl;


	int lt = text.size();
	int lp = pattern.size();
	int tenPow = 1;

	for(int i = 0; i < lp-1; i++)
		tenPow = (tenPow%MOD * 10) % MOD;

	// cout<<tenPow<<endl<<endl;
	int occurances = hvText == hvPattern ? 1 : 0;

	for(int i = 1; i < (lt-lp+1); i++) {

		int crrPatHv = hvText - ((int)text[i-1]);
		crrPatHv /= 10;

		// cout<<"----"<<text[i+lp-1]<<"----";
		crrPatHv += (tenPow*(int)text[i + lp-1]);
		hvText = crrPatHv;

		// cout<<crrPatHv;

		if(crrPatHv == hvPattern) {
			occurances++;
			cout<<"--"<<i<<"* ";
			// chech here too both string because of bad function
			cout<<endl;
		}
	}

	// time complexity(m-n) ---average
	// m*n --- worstCase

	cout<<"NO. of occurances : "<<occurances;

}