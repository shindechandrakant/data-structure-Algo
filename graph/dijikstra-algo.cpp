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
problem statement -> dijikstra-algo.cpp
Problem link -> https://www.youtube.com/watch?v=sD0lLYlGCJE
Dijikstra Algo : single source shortest path algorithm 


ip

node edges source
5 5 1
u v w
1 2 2
2 3 3
3 4 5
1 3 7
2 5 1
*/

struct Edge {

	int start, end, weight;
};

void printGraph(vector<vector<Edge> > &graph) {


	for(int i = 1; i < graph.size(); i++) {

		cout<<i<<" : ";
		for(auto it : graph[i]) {

			cout<<"("<<it.end<<", "<<it.weight<<"), ";

		}
		cout<<endl;
	}
}


struct DijiNode {

	int node;
	int weightSoFar;
	string pathSoFar;
};


struct comparator {

	bool operator() (DijiNode const & d1, DijiNode const &d2) {

		return d1.weightSoFar > d2.weightSoFar;
	}

};


int main() {

    #ifndef ONLINE_JUDGE
        freopen("../io/input.txt", "r", stdin);
        freopen("../io/output.txt", "w", stdout);
        freopen("../io/err.txt", "w", stderr);
        auto start = high_resolution_clock::now();
    #endif

  	int edges;
  	int nodes;
  	int source;
  	cin>>nodes>>edges>>source;

  	vector<vector<Edge> > graph(nodes+1);
  	int u, v, w;
  	
  	for(int i = 0; i < edges; i++) {

  		cin>>u>>v>>w;
  		graph[u].push_back({u, v, w});	
  		graph[v].push_back({v, u, w});	

  	}

  	// printGraph(graph);
  	priority_queue<DijiNode, vector<DijiNode>, comparator> qu; 

  	vector<bool> visited(nodes+1, false);
  	qu.push({source, 0, to_string(source) });

  	while(not qu.empty()) {


  		DijiNode top = qu.top();
  		qu.pop();

  		if(visited[top.node]) {
  			continue;
  		}
  		cout<<"Node :"<<top.node<<", Weight : "<<top.weightSoFar<<", path :"<<top.pathSoFar<<endl;

  		visited[top.node] = true;

  		for(auto it : graph[top.node]) {

  			if(not visited[it.end]) {

  				qu.push({it.end, top.weightSoFar+it.weight, top.pathSoFar+ "-" + to_string(it.end)});
  			}
  		}
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

