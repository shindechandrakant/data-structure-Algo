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
Problem link -> https://codeforces.com/contest/1579/problem/A
*/

int main() {

	// freopen("../io/input.txt", "r", stdin);
	// freopen("../io/output.txt", "w", stdout);
	// auto start = high_resolution_clock::now();




	int t;
	cin>>t;

	while(t--) {

		string str;
		cin>>str;

		int countA = 0;
		int countB = 0;
		int countC = 0;

		for(int i = 0; i <str.size(); i++) {

			if(str[i] == 'A') {

				countA++;
			}
			else if(str[i] == 'B') {

				countB++;
			}
			else {

				countC++;
			}
		}

		if((countC + countA) == countB) {

			cout<<"YES\n";
		}
		else {
			cout<<"NO\n";
		}
	}













	// auto stop = high_resolution_clock::now();
	// auto duration = duration_cast<microseconds>(stop - start);
	// cout<<"\n\nTime :"<<(duration.count()/1000.0)<<" ms" << endl;
	// fclose(stdin);
	// fclose(stdout);


}