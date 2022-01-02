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
Problem link -> https://codeforces.com/contest/1574/problem/A
*/


void printBrackets(int n, int open, int close, string ssf, int &counter) {

	if(n < close or n < open or counter == n) {

		return;
	}

	if(n == open and n == close) {

		counter++;
		cout<<ssf<<endl;
		return;
	}


	if(open < n) {

		printBrackets(n, open+1, close, ssf+"(", counter);
	}

	if(close < open) {

		printBrackets(n, open, close+1, ssf + ")", counter);
	}


}

int main() {

  	freopen("../io/input.txt", "r", stdin);
  	freopen("../io/output.txt", "w", stdout);
  	auto start = high_resolution_clock::now();


  	int t;
  	cin>>t;

  	while(t--) {

  		int n;
  		cin>>n;
  		int counter = 0;

  		printBrackets(n, 0, 0, "", counter);



  	}











  	auto stop = high_resolution_clock::now();
  	auto duration = duration_cast<microseconds>(stop - start);
  	cout<<"\n\nTime :"<<(duration.count()/1000.0)<<" ms" << endl;
  	fclose(stdin);
  	fclose(stdout);


}

#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using ll = long long;
const ll mod = 1000000007;
#define F first
#define S second
#define fo(i,a,b) for(ll i=a;i<b;i++)
#define T ll t; cin>>t; fo(i,0,t)
#define pb push_back
#define printclock cerr<<"Time : "<<1000*(ld)clock()/(ld)CLOCKS_PER_SEC<<"ms\n";
 
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tt=1;
    cin>>tt;
    while(tt!=0){
        ll n; cin>>n;
        fo(i,0,n){
            cout<<"(";
        }
        fo(i,0,n){
            cout<<")";
        }
        cout<<'\n';
        ll k=n-1;
        while(k!=0){
               fo(i,0,k){
            cout<<"(";
        }
        fo(i,0,k){
            cout<<")";
        }
        ll r=n-k;
        fo(i,0,r)
        cout<<"()";
        
        cout<<'\n';
            k--;
        }
        tt--;
    }
   	printclock;
    return 0;
}

void find() {
 
cin>>n;
string s = "";
for(int i=0;i<2*n;i++) {
   if(i & 1) {
      s += ')';
   } else {
      s += '(';
   }
}
cout<<s<<"\n";
 
for(int i=1;i<2*n-1;i+=2) {
   s[i] = '(';
   s[i+1] = ')';
   cout<<s<<"\n";
}
 
 
 
}