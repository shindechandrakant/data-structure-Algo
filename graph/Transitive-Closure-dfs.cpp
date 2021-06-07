#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
#define vi vector<ll>
#define pi pair<ll, ll>
#define ump(dataTyp1, dataTyp2) unordered_map<(dataTyp1), (dataTyp2)>
#define mp(dataTyp1, dataTyp2) map<(dataTyp1), (dataTyp2)>
#define v2d(name, m, n, inti) vector<vi>(name)(m, vi(n, inti))
#define MOD 1000000007

// problem statement -> Transitive Closure of a Graph using DFS
// Problem link -> https://www.geeksforgeeks.org/transitive-closure-of-a-graph-using-dfs/

// DO matrix form
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

		void transitiveCloure() {

			vector<vector<bool>>transitiveCloureMatrix;

			for(int i = 0; i <= nodes; i++) {

				vector<bool> visited(nodes+1, false);

				dfs(i, visited);
				transitiveCloureMatrix.push_back(visited);
			}
 
			for(auto row : transitiveCloureMatrix) {

				for(auto cell : row) 
					cout<<cell<<" ";
				cout<<endl;
			}

			cout<<endl;
		}


};



int main() {

	freopen("../io/input.txt", "r", stdin);
	freopen("../io/output.txt", "w", stdout);

	int t;
	cin>>t;

	while(t--)
	{
		int nodes, edges;
		cin>>nodes>>edges;

		Graph graph(nodes);


		for(int i = 0; i < edges; i++) {

			int u, v;
			cin>>u>>v;

			graph.addEdge(u, v);

		}

		graph.printGraph();
		graph.transitiveCloure();

	}





	fclose(stdin);
	fclose(stdout);

}