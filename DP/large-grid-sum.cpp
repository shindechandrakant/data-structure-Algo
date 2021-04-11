#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
#define vi vector<int>
#define vll vector<ll>

ll kadane(vll &temp, int &start, int &end) {

	ll sum = 0;
	ll maxSum = INT_MIN;
	end = -1;
	int tempStart = 0;
	int n = temp.size();
	for(int i = 0; i < n; i++) {

		sum += temp[i];
		
		if(sum < 0) {
			sum = 0;
			tempStart = i + 1;
		}else if(sum > maxSum) {
			maxSum = sum;
			start = tempStart;
			end = i;
		}
	}

	if(end != -1) return maxSum;


	maxSum = temp[0];
	start = end = 0;
	for(int i = 1; i < n; i++) 
	{
		if(maxSum < temp[i]) {

			maxSum = temp[i];
			start = end = i;
		}
	}
	return maxSum;
}

ll maxSumReactangle(vector<vector<ll> > &grid) {

	ll ans = 0;
	int n = grid.size();
	int m = grid[0].size();
	vll temp(n, 0);
	int start, end, tlc, tlr, brc, brr;

	for(int leftCol = 0; leftCol < m; leftCol++) {

		temp.assign(n, 0);
		for(int rightCol = leftCol; rightCol < m; rightCol++) {

			for(int i = 0; i < n; i++) {

				temp[i] += grid[i][rightCol];
			}

			int sum = kadane(temp, start, end);
			// cout<<sum<<" "<<start<<" "<<end<<endl;

			if(sum > ans) {
				
				ans = sum;
				tlc = leftCol;
				brc = rightCol;
				tlr = start;
				brr = end;
			}

		}
	}

	cout<<"( "<<tlr<<" , "<<tlc<<" )\n";
	cout<<"( "<<brr<<" , "<<brc<<" )\n";
	return ans;
}


int main() {

  ll n, m;
  cin>>n>>m;

  vector<vector<ll> > grid(n, vector<ll>(m));

  for(int i = 0; i < n; i++) {
  	for(int j = 0; j < m; j++) {

  		cin>>grid[i][j];
  	}
  }

  ll result = maxSumReactangle(grid);
  cout<<result;
}