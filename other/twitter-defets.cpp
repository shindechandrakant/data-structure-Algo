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
Problem link -> 


iip
4 5
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 1 1 1
4 5
1 1 1 0 0
1 1 1 1 1
1 1 1 1 1
1 0 1 1 0
*/


int maxDefeats(vector<vector<int> > &grid) {

	int rows = grid.size();
	int col = grid[0].size();
	vector<vector<int> > dp(rows, vector<int>(col, 0));
	int answer = -1;
	for(int i = 0; i < rows; i++) {

		dp[i][col-1] = grid[i][col-1];
	}

	for(int i = 0; i < col; i++) {

		dp[rows-1][i] = grid[rows-1][i];
	}
	for(int i = rows-2; i >= 0; i--) {

		for(int j = col-2; j >= 0; j--) {


			if(grid[i][j] == 1)
				dp[i][j] = min({dp[i][j+1], dp[i+1][j], dp[i+1][j+1]}) + 1;
			else 
				dp[i][j] = 0;

			if(answer < dp[i][j])
				answer = dp[i][j];
		}
	}
	return answer;
}



int main() {

    #ifndef ONLINE_JUDGE
        freopen("../io/input.txt", "r", stdin);
        freopen("../io/output.txt", "w", stdout);
        auto start = high_resolution_clock::now();
    #endif

  

int t = 2;

while(t--){
        int n, m;
        cin>>n>>m;

        vector<vector<int> > grid(n, vector<int>(m));

        for(int i = 0; i < n; i++) {

        	for(int j = 0; j < m; j++) {
        		cin>>grid[i][j];
        	}

        }

        cout<<maxDefeats(grid);




}

    #ifndef ONLINE_JUDGE
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout<<"\n\nTime :"<<(duration.count()/1000.0)<<" ms" << endl;
        fclose(stdin);
        fclose(stdout);
    #endif


}