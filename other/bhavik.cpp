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


void swap(int &a, int &b) {


    // a = 5'
    // b = 6'
    b = a + b;
    a = b - a;
    b = b - a;
}

// What replaces the question mark ?
// 9999 = 4
// 8888 = 8
// 1816 = 3
// 1212 = 0
// 1919 = ?


/*
select sum(salary) as no_of_employees
from employee
order by emp_id desc;
*/


int main() {

    #ifndef ONLINE_JUDGE
        freopen("../io/input.txt", "r", stdin);
        freopen("../io/output.txt", "w", stdout);
        auto start = high_resolution_clock::now();
    #endif


    int a, b;
    cin>>a>>b;

    cout<<"Before Swp: a = "<<a<<", b = "<<b<<endl;
    swap(a,b );
    cout<<"After Swp: a = "<<a<<", b = "<<b<<endl;











    #ifndef ONLINE_JUDGE
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout<<"\n\nTime :"<<(duration.count()/1000.0)<<" ms" << endl;
        fclose(stdin);
        fclose(stdout);
    #endif


}