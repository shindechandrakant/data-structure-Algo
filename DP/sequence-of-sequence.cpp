#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
#define vi vector<ll>
#define pi pair<ll, ll>
#define v2d(name, m, n, inti) vector<vi>(name)(m, vi(n, inti))

// problem statement -> 
// Problem link -> 
void seqs(int prev, int start, int m, int n, int &ans) {
        
    if(start > m) { return; }
        
    cout<<start<<" ";
    if(n == 1) {
       ans++; 
       cout<<endl;
       return;
    }

    for(int i = start; i <= m; i++) {
        	
        if(2*i > m)
        	seqs(prev, i, m, n-1, ans);
        else
	 		seqs(i, i*2, m, n-1, ans);
    }
}
 


int main() {

	int n, m;
	cin>>n>>m;
	int ans = 0;
    seqs(1, 1, m, n, ans);
    cout<<endl<<ans;
}