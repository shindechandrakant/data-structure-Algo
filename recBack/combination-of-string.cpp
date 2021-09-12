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


void combinationsOfString(int curr, int total, int selecton, int totalSelections, string ssf) {

    if(curr > total) {

        if(selecton == totalSelections) {

            cout<<ssf<<endl;
        }
        return;
    }

    combinationsOfString(curr+1, total, selecton, totalSelections, ssf+"-");
    combinationsOfString(curr+1, total, selecton+1, totalSelections, ssf+ to_string(selecton));
}




int main() {

    freopen("../io/input.txt", "r", stdin);
    freopen("../io/output.txt", "w", stdout);


	combinationsOfString(0, 4, 0, 3, "");


    fclose(stdin);
    fclose(stdout);
}