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
Problem link -> 
*/






void dfs(int row, int col, int n, int m, int **grid) {


	if(! (row >= 0 && col >= 0 && row < n && col < m)) {
		return;
	}

	if(grid[row][col] == 1) {

		return;
	}
	grid[row][col] = 1;

	dfs(row, col-1, n, m, grid);
	dfs(row, col+1, n, m, grid);
	dfs(row-1, col, n, m, grid);
	dfs(row+1, col, n, m, grid);
}







int main() {

    freopen("../io/input.txt", "r", stdin);
    freopen("../io/output.txt", "w", stdout);


    int n, m;
    cin>>n>>m;

    int arr[n][m];

    for(int i = 0; i < n; i++) {

    	for(int j = 0; j < m; j++) {

    		int x;
    		cin>>x;
    		arr[i][j] =x;

    	}
    }

  int answer = 0;
	for(int i = 0; i < n; i++) {

		for(int j = 0; j < m; j++) {


			if(arr[i][j] == 0) {

				dfs(i, j, n, m, arr);
				answer++;
			}
		}
	}
	cout<< answer;








    fclose(stdin);
    fclose(stdout);

}


// int count(int input1 , int **input2) {


// 	bool array[8][8];

// 	for(int i = 0; i < 8; i++) {

// 		for(int j = 0; j < 8; j++) {

// 			array[i][j] = false;
// 		}
// 	}


// 	for(int i = 0; i < input1; i++) {

// 		int x= input2[0];
// 		int y = input2[1];

// 		array[x][y]= true;

// 		for(int i = y; i>= 0; i--) {

// 			array[x][i] = true;
// 		} 


// 		for(int i = y; i < 8; i++) {

// 			array[x][i] = true;
// 		} 

// 		for(int i = x; i >= 0; i--) {

// 			array[i][y] = true;
// 		}

// 		for(int i = x; i < 8; i++) {
// 			array[i][y] = true;
// 		}


// 	}

// 		int answer = 0;
// 		for(int i = 0; i < 8; i++) {

// 		for(int j = 0; j < 8; j++) {

// 			if(array[i][j] == true) {

// 				answer++;
// 			}
// 		}
// 	}

// 	return answer;

// }