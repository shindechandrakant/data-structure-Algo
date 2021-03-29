#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define MOD 1000000007
#define vi vector<int>

// problem Link -> https://codeforces.com/contest/1472/problem/B?csrf_token=293e8bd63ba263556336b633642892fd



int main() {
  
  int t;
  cin>>t;
  while(t--)
  {

  	int n;
  	cin>>n;
  	long total = 0;
  	// map<int, int>mp;
  	int bob = 0;
  	int alie = 0;
  	for(int i= 0; i < n; i++) {

  		int x;
  		cin>>x;
  		if(bob < alie)
  			bob += x;
  		else
  			alie += x;
  		// total += x;
  		// mp[x]++;
  	}

  	bool ans = bob == alie;

  	// for(auto it : mp) {

  	// 	if(it.second % 2 != 0) {

  	// 		ans = false;
  	// 		break;
  	// 	}
  	// }


  	if(ans) 
  		cout<<"YES"<<endl;
  	else
  		cout<<"NO"<<endl;


  }
  
}