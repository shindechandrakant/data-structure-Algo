#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define MOD 1000000007
#define vi vector<int>
#define ump unordered_map<int, int>
// problem link
//https://www.hackerearth.com/challenges/competitive
// /march-circuits-21/algorithm/fair-competition-0315250e/

int getParent(int a, vi &parents) {
 
    return a == parents[a] ? a : getParent(parents[a], parents);
}

int getParentBT(int a, vi &parents, ump &mp) {
 
    if(mp.count(a) != 0)
      return mp[a];

    int x;
    if(a == parents[a]) {
      return parents[a];
    }
    else 
     x = getParentBT(parents[a], parents, mp);

   // cout<<a<<"  "<<x<<endl;
   mp[a] = x;
   return x;
}

void display(vi &v) {

    for (int i = 0; i < v.size(); ++i)
    {
      cout<<v[i]<<" ";
    }
    cout<<endl;
}

void formGroup(int a, int b, vi &parents, vi &degree) {


    int pa = getParent(a, parents);
    int pb = getParent(b, parents);

    if(degree[pa] > degree[pb]) 
    {

      parents[a] = pa;
      parents[b] = pa;
      degree[pa]++;
    }
    else 
    {
      parents[a] = pb;
      parents[b] = pb;
      degree[pb]++;
    } 
}

int main() {
  
  int t;
  cin>>t; 
  while(t--) {

    int n,m;
    cin>>n>>m;
    vi parents(n+1);
    vi degree(n+1, 0);

    for(int i = 1; i <= n; i++)
      parents[i] = i;
  
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin>>x>>y; 
        formGroup(x, y, parents, degree); 
    } 

    ump groups;
    ump mp;

    for(int i = 1; i < parents.size(); i++) {

        int x = getParentBT(i, parents, mp);
        groups[x]++;
    }

    long ans = 0;
    if(groups.size() == 1) {

      cout<<0<<endl;
      continue;
    }
    for(auto it = groups.begin(); it != groups.end(); it++)
    {
      auto i = it;
      i++;
      for(auto it2 = i; it2 != groups.end(); it2++) {

          ans += (it -> second * it2 -> second * 2);
      }
    }
    cout<<ans<<endl;
  } 
}

