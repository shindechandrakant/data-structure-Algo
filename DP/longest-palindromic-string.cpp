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
*/

int longestPalindromicStringLength(string str) {

	int n = str.size();
	int length = 0;
	vector<vector<bool> > dp(n, vector<bool>(n, false));

	// for(int i = 0; i < MOD; i++);

	for(int col = 0; col < n; col++) {

		for(int row = 0, gap = col; gap < n; row++, gap++) {


			if(col == 0) {

				dp[row][gap] = true;
			}
			else if(col == 1) {

				dp[row][gap] = str[row] == str[gap];
			}
			else if(str[row] == str[gap]) {

				dp[row][gap] = dp[row+1][gap-1];
			}
			else {

				dp[row][gap] = false;
			}

			if(dp[row][gap] and length < col) {

				length = col;
			}


		}
 

	}







	return length+1;
}


int main() {

    freopen("../io/input.txt", "r", stdin);
    freopen("../io/output.txt", "w", stdout);
    auto start = high_resolution_clock::now();


	string str;
	cin>>str;
	cout<<longestPalindromicStringLength(str);









	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
    cout<<"\n\nTime :"<<(duration.count()/1000.0)<<" ms" << endl;
    fclose(stdin);
    fclose(stdout);

}

