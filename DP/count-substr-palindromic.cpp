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


// abcba
bool isItPalindrome(string str) {

	int start = 0;
	int end = str.size()-1;

	while(start < end) {

		if(str[start] != str[end]) {

			return false;
		}
		start++;
		end--;
	}
	return true;
}

void printAllSubstrings(string str) {

	int n = str.size();
	int count = 0;


	for(int i = 0; i < n; i++) {

		for(int j = i; j < n; j++) {

			string substr;
			for(int k = i; k <= j; k++) {

				substr.push_back(str[k]);
			}

			if(isItPalindrome(substr)) {

				count++;
				cout<<substr<<endl;
			}
		}
	}

	cout<<count<<endl;
}


// template<typename T>
// void printDiagonalMtrix(vector<vector<T> > &matrix) {


// 	int n = matrix.size();
// 	int m = matrix[0].size();

// 	for(int col = 0; col < m; col++) {

// 		for(int row = 0, gap = col; gap < m; row++, gap++) {

// 			cout<<matrix[row][gap]<<" ";
// 		}
// 		cout<<endl;
// 	}
// }


void countSubstrPalindrome(string str) {

	int n = str.size();

	vector<vector<string> > grid(n, vector<string> (n, "-"));
	vector<vector<bool> > dp(n, vector<bool> (n, false));
	int count = 0;

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

			if(dp[row][gap]) {

				count++;
			}
		}


	}

	cout<<count<<endl;
}



int main() {

    freopen("../io/input.txt", "r", stdin);
    freopen("../io/output.txt", "w", stdout);

	string str;
	cin>>str;

	printAllSubstrings(str);
	countSubstrPalindrome(str);

	// vector<vector<int> > mat = { 
	// 					{ 1, 2, 3, 4}, 
	// 					{ 5, 6, 7, 8}, 
	// 					{ 9, 10, 11, 12},
	// 					{ 13, 14, 15, 16}
	// 				};

	// printDiagonalMtrix<int>(mat);




    fclose(stdin);
    fclose(stdout);

}