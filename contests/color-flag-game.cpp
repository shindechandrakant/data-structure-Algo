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
Problem link -> https://codeforces.com/contest/1534/problem/0
*/

void display(vector<vector<char> > &grid, int row, int col) {


	for(int i = 0; i < row; i++) {

    	for(int j = 0; j < col; j++) {

    		cout<<grid[i][j];    			
    	}
    	cout<<endl;
    }
}

int dots;

bool surround(vector<vector<char> > &grid, int row, int col, char by) {

	char org = by == 'W' ? 'R' : 'W';

	//left
	if(col-1 >= 0) {

		if(grid[row][col-1] == org)
			return false;

		if(grid[row][col-1] == '.')
				dots--;
		grid[row][col-1] = by;
	}
	//top

	if(row -1 >= 0) {

		if(grid[row-1][col] == org)
			return false;


		if(grid[row-1][col] == '.')
				dots--;

		grid[row-1][col] = by;
	}

	//bottom
	if(row + 1 < grid.size()) {

		if(grid[row+1][col] == org)
			return false;

		if(grid[row+1][col] == '.')
				dots--;

		grid[row+1][col] = by;
	}

	//right
	if(col + 1 < grid[col].size()) {

		if(grid[row][col+1] == org)
			return false;

		if(grid[row][col+1] == '.')
				dots--;

		grid[row][col+1] = by;
	}

	return true;
}



bool isItPossible(vector<vector<char> > &grid, int row, int col) {

	// cout<<dots<<endl;

	if(dots == row*col) {

		// cout<<"E";
		grid[0][0]= 'R';
		dots -=1;
	}

	col<<grid[0][0];

	for(int i = 0; i < row; i++) {

		for(int j = 0; j < col; j++) {

			if(grid[i][j] != '.') {

				char by = grid[i][j] == 'W' ? 'R' : 'W';

				bool ans = surround(grid, i, j, by);
				// cout<<ans<<endl;
				if(not ans)
					return false;


				// display(grid, row, col);
			}
		}
	}

	return dots == 0 ? true : isItPossible(grid, row, col);
}


int main() {

    // freopen("../io/input.txt", "r", stdin);
    // freopen("../io/output.txt", "w", stdout);

    int t;
    cin>>t;

    while(t--) {

    	dots = 0;
    	int row, col;
    	cin>>row>>col;

    	vector<vector<char> > grid (row, vector<char>(col));

    	for(int i = 0; i < row; i++) {

    		for(int j = 0; j < col; j++) {

    			cin>>grid[i][j];

    			if(grid[i][j] == '.')
    				dots++;
    		}
    	}

    	

    	if(isItPossible(grid, row, col)) {

    		cout<<"YES\n";
    		display(grid, row, col);
    	}
    	else 
    		cout<<"NO\n";
    }

    // fclose(stdin);
    // fclose(stdout);

}