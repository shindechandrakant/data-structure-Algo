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


    int rowFirst = mat1.size();
    int colFirst = mat1[0].size();

    int rowSec = mat2.size();
    int colSec = mat2[0].size();


    vector<vi> ans(rowFirst, vi(colSec));

    for(int i = 0; i < rowFirst; i++) {

        for(int j = 0; j < colSec; j++) {

            for(int k = 0; k < rowSec; k++) {


                ans[i][j] += (mat1[i][k] * mat2[k][j]);

            }
        }
    }

    return ans;
}


vector<vi> matrixExponential(vector<vi> &mat, int power) {

    if(power == 1) {

        return mat;
    }

    vector<vi> ans = matrixExponential(mat, power/2);

    if(power % 2 == 0) {

        ans = matrixMultiplication(ans, ans);
    }
    else {

        ans = matrixMultiplication(ans, ans);
        ans = matrixMultiplication(ans, mat);
    }

    return ans;

}


vector<vi> getMatrix() {

    int n, m;
    cin>>n>>m;

    vector<vi> mat(n, vi(m));
    for(int i = 0; i < n; i++) {

        for(int j = 0; j < m; j++) {

            cin>>mat[i][j];
        }
    }
    return mat;
}


void display(vector<vi> &ans) {


    for(int i = 0; i < ans.size(); i++) {

        for(int j = 0; j < ans[i].size(); j++) {

            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"\n-----------------"<<endl;
}



int main() {

    freopen("../io/input.txt", "r", stdin);
    freopen("../io/output.txt", "w", stdout);

    vector<vi> mat1 = getMatrix();
    vector<vi> mat2 = getMatrix();

    // vector<vi> ans = matrixExponential(mat1, 2);

    vector<vi> ans = matrixMultiplication(mat1, mat2);
    display(mat1);
    display(mat2);
    display(ans);


    fclose(stdin);
    fclose(stdout);
}