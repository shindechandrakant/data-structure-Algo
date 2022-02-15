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
problem statement -> disjoint-union-set.cpp
Problem link -> https://leetcode.com/explore/learn/card/graph/618/disjoint-set/3881/
*/

int getParent(int indx, vector<int> &disjoint_set) {

    return indx == disjoint_set[indx] ? indx : getParent(disjoint_set[indx], disjoint_set);
} 


void addEdge(int u, int v, vector<int> &disjoint_set) {


    int up = getParent(u, disjoint_set);
    int vp = getParent(v, disjoint_set);

    disjoint_set[v] = up;

}


int main() {

    #ifndef ONLINE_JUDGE
        freopen("../io/input.txt", "r", stdin);
        freopen("../io/output.txt", "w", stdout);
        freopen("../io/err.txt", "w", stderr);
        auto start = high_resolution_clock::now();
    #endif

    int edges, nodes;
    cin>>nodes>>edges;
    vector<int> disjoint_set(nodes+1);

    for(int i = 0; i <= nodes; i++) {

    	disjoint_set[i] = i;
    }

    for(int i = 0; i < edges; i++) {

        int u, v;
        cin>>u>>v;
        addEdge(u, v, disjoint_set);
    }
  	

    int queries;
    cin>>queries;
    for(int i = 0; i < queries; i++) {

        int x, y;
        cin>>x>>y;

        int xp = getParent(x, disjoint_set);
        int yp = getParent(y, disjoint_set);

        if(xp == yp) {

            cout<<x<<" "<<y<<" has common parent : "<<xp;
        }
        else {
            cout<<x<<" "<<y<<" are disconnected";
        }
        cout<<endl;


    }






    #ifndef ONLINE_JUDGE
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout<<"\n\nTime :"<<(duration.count()/1000.0)<<" ms" << endl;
        fclose(stdin);
        fclose(stdout);
        fclose(stderr);
    #endif
}

