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
  	vector<vector<char> > v(n, vector<char>(n));

  	int x1, y1, x2, y2;
  	int count = 0;
  	for(int i = 0; i < n; i++) {

  		for(int j = 0; j < n; j++) {

  			cin>>v[i][j];

  			if(v[i][j] =='*' and count == 0) {

  				x1 = i;
  				y1 = j;
  				count++;
  			}
  			else if(v[i][j] == '*' and count == 1) {

  				x2 = i;
  				y2 = j;
  			}
  		}
  	}

  	if(x2 == x1) {

  		if(x1+1 < n) {
  			v[x1+1][y1] = '*';
  			v[x1+1][y2] = '*';
  		}
  		else {
  			v[x1-1][y1] = '*';
  			v[x1-1][y2] = '*';
  		}
  	}
  	else if(y1 == y2) {

  		if(y1+1 < n) {

	  		v[x1][y1+1] = '*';
	  		v[x2][y1+1] = '*';
  		}
  		else {
  			v[x1][y1-1] = '*';
	  		v[x2][y1-1] = '*';
  		}
  	}
  	else {

  		v[x1][y2] = '*';
  		v[x2][y1] = '*';
  	}

  	for(int i = 0; i < n; i++)
  	{
  	  	for(int j = 0; j < n; j++) 
  	  	{
  	  		cout<<v[i][j];
  	  	}
  	  	cout<<endl;
  	}

  	  	// cout<<endl;


  }
  
}