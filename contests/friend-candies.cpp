#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define MOD 1000000007
#define vi vector<lli>

int main() {
  


	// freopen("../io/input.txt", "r", stdin);
	// freopen("../io/output.txt", "w", stdout);
  int t;
  cin>>t;
  while(t--)
  {

  	lli n, l, r;
  	cin>>n>>l>>r;
  	vi v;

  	for(int i = 0; i < n; i++) {

  		lli x;
  		cin>>x;

  		if(x <= r)
  			v.push_back(x);
  	}

  	// sort(v.begin(), v.end());


  	int ans = 0;

  	for(int i = 0; i < v.size(); i++) {

  		for(int j = i+1; j < v.size(); j++) {

  			lli sum = v[i] + v[j];
  			if(sum >= l and sum <= r)
  				ans++;
  			else if(sum > r)
  				break;
  		}
  	}
  	cout<<ans<<endl;
  }

  // fclose(stdin);
  // fclose(stdout);
  
}