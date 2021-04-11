#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define MOD 1000000007
#define vi vector<int>

int main() {
  
  int t;
  cin>>t;
  while(t--)
  {

  	int n;
  	cin>>n;
  	map<int, int> mp;
  	int ans = 0;
  	// vector<pair<int, int>> v(n);
  	vi v(n);
  	for(int i = 0; i < n; i++) {

  		cin>>v[i];
  		// cin>>v[i].first;
  		// v[i].second = i+1;
  	} 

  	// }

  	set<int> st;
 	for(int i = 0; i < n; i++) {

 		int count = 1;
 		
 		if(st.count(v[i]) == 0) {

 				for(int j = i+1; j < n; j++)
		 		{
		 			if(v[i] == v[j])
		 				count++;
		 		}
 		}
 		if(count == 1 and st.count(v[i]) == 0) {
 			ans = i+1;
 			break;
 	 }
 		st.insert(v[i]);

 	}


  	cout<<ans<<endl;
  }
  
}