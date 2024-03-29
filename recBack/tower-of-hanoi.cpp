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

void towerOfHanoi(int disks, char towerA, char towerB, char towerC) {

    if(disks == 0) {

        return ;
    }

    towerOfHanoi(disks-1, towerA, towerC, towerB);
    cout<<"[ "<<towerA<<" -> "<<towerB<<" ]\n";
    towerOfHanoi(disks-1, towerC, towerB, towerA);
}



int main() {

    freopen("../io/input.txt", "r", stdin);
    freopen("../io/output.txt", "w", stdout);


    towerOfHanoi(3, 'A', 'B', 'C');






    fclose(stdin);
    fclose(stdout);

}