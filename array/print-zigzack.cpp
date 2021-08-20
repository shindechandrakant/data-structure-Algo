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

bool isItSafe(vector<vi> &array, int row, int col) {

	return row >= 0 and col >= 0 and array.size() > row and array[row].size() > col;

}


void printZicZac(vector<vi> &array, int row, int col) {


	if(not isItSafe(array, row, col)) {

		return;
	}

	cout<<array[row][col]<<" ";
	

	printZicZac(array, row, col+1);
	

}



int main() {

    freopen("../io/input.txt", "r", stdin);
    freopen("../io/output.txt", "w", stdout);


	int n, m;
	cin>>n>>m;

	vector<vi> array(n, vi(m));

	for(int i = 0; i < n; i++) {

		for(int j = 0; j < m; j++) {

			cin>>array[i][j];
		}
	}


	printZicZac(array, 0, 0);





    fclose(stdin);
    fclose(stdout);

}