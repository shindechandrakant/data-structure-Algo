#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
#define vi vector<ll>
#define pi pair<ll, ll>
#define vb vector<bool>
#define ump(dataTyp1, dataTyp2) unordered_map<(dataTyp1), (dataTyp2)>
#define mp(dataTyp1, dataTyp2) map<(dataTyp1), (dataTyp2)>
#define v2d(name, m, n, inti) vector<vi>(name)(m, vi(n, inti))
#define MOD 1000000007

// problem statement -> Detect Cycle In a Graph in directed Graph
// Problem link -> https://www.geeksforgeeks.org/detect-cycle-in-a-graph/
 
/*
	functions: all operation for cycle detection are performed on directed Graph
	1 -> using BFS non recursive
	2 -> using BFS recursive
	3 -> using DFS non recursive
	4 -> using DFS recursive
	5 -> Detect No. of Cycles
	6 -> print All cycles with length and path
*/

class Graph {

	int nodes, edges;
	list<int> *adj;

	public:
		Graph(int nodes) {

			this -> nodes = nodes;
			this -> adj = new list<int>[nodes+1];
		}

		void addEdge(int u, int v, bool bidir = false) {

			adj[u].push_back(v);

			if(bidir) {

				adj[v].push_back(u);
			}
		}

		void printGraph() {

			for(int i = 0; i <= nodes; i++) {

				cout<<i<<" : ";
				for(auto edge : adj[i]) {

					cout<<edge<<" ";
				}
				cout<<endl;
			}

			cout<<"\n\n";
		}

		void dfs(int node, vector<bool> &visited) {

			visited[node] = true;
			for(auto it: adj[node]) {

				if(not visited[it]) {

					dfs(it, visited);
				}
			}
		}

	    bool isCycle(vector<bool> &visited, int n, vector<bool> &check) {
	       
	        visited[n] = true;
	        check[n] = true;
	        
	        for(auto it: adj[n]) {
	            
	            if(check[it] )
	                return true;
	            else if(not visited[it] and isCycle(visited, it, check)) 
	                 return true;
	        }
	        check[n] = false;
	        return false;
	    }

		void detectCycleDFSUndirectedGraph() {

			vector<bool> visited(nodes+1, false);
     

			for(int i = 0; i <= nodes; i++) {

				if(not visited[i]) {

					vb check(nodes+1, false);

					if(isCycle(visited, check, i)) {

						cout<<"Cycle is present ";
						return;
					}
				}

				cout<<"Graph is Acyclic";
			}
		}

};



int main() {

	freopen("../io/input.txt", "r", stdin);
	freopen("../io/output.txt", "w", stdout);

	
	int nodes, edges;
	cin>>nodes>>edges;

	Graph g(nodes);

	for(int i = 0; i < edges; i++) {

		int u, v;
		cin>>u>>v;
		// cout<<u<<" "<<v<<endl;
		g.addEdge(u , v);
	}

	g.printGraph();
	g.detectCycleDFSUndirectedGraph();




	fclose(stdin);
	fclose(stdout);

}