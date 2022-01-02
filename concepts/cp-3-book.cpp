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

int main() {

  freopen("../io/input.txt", "r", stdin);
  freopen("../io/output.txt", "w", stdout);
  auto start = high_resolution_clock::now();



  // vector<tuple<int, int, int> > tple;
  // tple.push_back({1,2,3});
  // cout<<tple.size();

  // set<vector<int> > st;

  // st.insert({1, 3, 2});
  // st.insert({1, 3, 2 }); // ordering matter

  // cout<<st.size();




  // auto it = equal_range(vect.begin(), vect.end(), x);
  // it.first - contain lower_bound
  // it.second - contain upper_bound

  // subset using bit manipulation 


  int n;
  cin>>n;

  








  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout<<"\n\nTime :"<<(duration.count()/1000.0)<<" ms" << endl;
  fclose(stdin);
  fclose(stdout);


}