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

int main() {

    // freopen("../io/input.txt", "r", stdin);
    // freopen("../io/output.txt", "w", stdout);


	ll t;
	cin>>t;

	while(t--) {

		ll a, b, c;
		cin>>a>>b>>c;

		ll nppls = long(2l*abs(a-b));

		ll half = nppls/2l;
		ll answer = 0;

		if(nppls < c or nppls < a or nppls < b) {
			cout<<-1<<endl;
			continue;
		}

		if(c > half)
			answer = c-half;
		else
			answer = (c+half);

		cout<<answer<<endl;
		
		

	}




    // fclose(stdin);
    // fclose(stdout);

}

/*
8
-1
-1
-1
4
1
-1



*/