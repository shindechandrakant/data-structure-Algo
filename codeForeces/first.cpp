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
Problem link -> https://codeforces.com/contest/1560/problem/A
*/


vector<int> div3() {


	vector<int> answer;

	for(int i = 1; i < 3000; i++) {

		if(i % 3 != 0 and i % 10 != 3) {

			answer.push_back(i);
		}


	}


	return answer;

}

int main() {

    // freopen("../io/input.txt", "r", stdin);
    // freopen("../io/output.txt", "w", stdout);


	int t;
	cin>>t;

	vector<int> answer = div3();

	while(t--) {

		int x;
		cin>>x;

		cout<<answer[x-1]<<endl;


	}






    // fclose(stdin);
    // fclose(stdout);

}