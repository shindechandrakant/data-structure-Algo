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




vector<vi> matrixMultiplication(vector<vi> &mat1, vector<vi> &mat2) {


	int n = mat1.size(); // 
	int m = mat1[0].size();

	int x = mat2.size();
	int y = mat2[0].size();

	vector<vi> newMat(x, vector<ll> (m, 0));


	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{

			// matrix code

		}
	}



}





int main() {

    freopen("../io/input.txt", "r", stdin);
    freopen("../io/output.txt", "w", stdout);


	cout<<"I'm Running";






    fclose(stdin);
    fclose(stdout);

}