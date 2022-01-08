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
#define MOD 1000000007

/*
problem statement -> 
Problem link -> https://codeforces.com/problemset/problem/230/A
*/

int main() {

    #ifndef ONLINE_JUDGE
        freopen("../io/input.txt", "r", stdin);
        freopen("../io/output.txt", "w", stdout);
        freopen("../io/err.txt", "w", stderr);
        auto start = high_resolution_clock::now();
    #endif

  
  	int strength, deagons;
  	cin>>strength>>deagons;

  	vector<pair<int, int> > level(deagons);

  	for(int i = 0; i < deagons; i++) {

  		cin>>level[i].first>>level[i].second;
  	}


  	sort(level.begin(), level.end());
  	// 	[](pair<int, int> p1, pair<int, int> p2) {

  	// 		if(p1.first != p2.first)
  	// 			return p1.first < p2.first;
  	// 		return p1.second < p2.second;
  	// });


  	// for(auto it : level)
  	// 	cout<<it.first<<" "<<it.second<<endl;


  	int k = 0;

  	for(k = 0; k < deagons; k++) {

  		if(strength > level[k].first)
  			strength += level[k].second;
  		else 
  			break;
  	}

  	// cout<<strength<<endl;/

  	cout<<(k == deagons ? "YES" : "NO");







    #ifndef ONLINE_JUDGE
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout<<"\n\nTime :"<<(duration.count()/1000.0)<<" ms" << endl;
        fclose(stdin);
        fclose(stdout);
        fclose(stderr);
    #endif


}