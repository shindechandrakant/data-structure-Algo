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
Problem link -> https://codeforces.com/contest/1538/problem/A
*/


struct element {

	int val;
	int indx;
};

int main() {

  freopen("../io/input.txt", "r", stdin);
  freopen("../io/output.txt", "w", stdout);


  int t;
  cin>>t;

  while(t--) {


  	int n;
  	cin>>n;

  	vi v(n);

  	for(int i = 0 ; i < n; i++)
  		cin>>v[i];

  	element min1, max1;

  	min1.val = max1.val = v[0];
  	max1.indx = min1.indx = 0;

  	for(int i = 1; i < n; i++) {

  		if(min1.val > v[i]) {

  			min1.val = v[i];
  			min1.indx = i;

  		}else if(max1.val < v[i]) {

  			max1.val = v[i];
  			max1.indx = i;
  		}
  	}


  	

  	int mindx= min1.indx;
  	int maxdx = max1.indx;

  	if(maxdx < mindx)
  		swap(maxdx, mindx);


  	int dif = abs(mindx - maxdx);

  // 	int half = n/2;


  // 	if(mindx <= half and maxdx <= half) {

  // 		cout<<maxdx+1<<endl;
  // 	}
  // 	else if(mindx >= half and maxdx >= half) {
  // 		cout<<mindx+1<<endl;

  // }
  // else {


  	int removeMax = n - maxdx;
  	int removeMin = mindx+1;

  	int ans = min({removeMin+removeMax, removeMin+dif, removeMax+dif});

  	cout<<ans<<endl;

  // }

}






  fclose(stdin);
  fclose(stdout);

}