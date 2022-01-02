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
Problem link -> https://cses.fi/problemset/task/1624
*/
vector<vector<char> > board(8, vector<char> (8));

bool isItSafe(int x, int y) {

	// left side
	for(int i = y; i >= 0; i--) {

		if(board[x][i] == '-')
			return false;
	}

	// left corner
    for(int i = x, j = y; i >= 0 && j >= 0; i--, j--) {

        if(board[i][j] == '-')
            return false;
    }
    // up
    for(int i = x; i >= 0; i--) {

        if(board[i][y] == '-')
            return false;
    }
    // right up
    for(int row = x, col = y; row >= 0 && col < 8; row--, col++) {

        if(board[row][col] == '-')
            return false;
    }





	return true;
}



void findWays(int x, int y, int queens, int &answer) {


    if(queens == 0) {

        answer++;
        return;
    }

    for(int i = x; i < 8; i++) {


        for(int j = 0; j < 8; j++) {

            if(isItSafe(i, j) && board[i][j] != '*') {

                char old = board[i][j];
                board[i][j] = '-';
                findWays(i+1, j, queens-1, answer);
                board[i][j] = old;
            }

        }


    }


}









int main() {

    #ifndef ONLINE_JUDGE
        freopen("../io/input.txt", "r", stdin);
        freopen("../io/output.txt", "w", stdout);
        auto start = high_resolution_clock::now();
    #endif

    
    for(int i = 0; i < 8; i++) {

    	for(int j = 0; j < 8; j++) {

    		cin>>board[i][j];
    	}
    }


    int ans = 0;

    findWays(0, 0, 8, ans);

    cout<<ans;













    #ifndef ONLINE_JUDGE
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout<<"\n\nTime :"<<(duration.count()/1000.0)<<" ms" << endl;
        fclose(stdin);
        fclose(stdout);
    #endif


}