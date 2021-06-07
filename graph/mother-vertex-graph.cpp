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

// problem statement -> find a mother vertex
// Problem link -> geeksforgeeks.org/find-a-mother-vertex-in-a-graph/

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
		}
		// mother vertex
		// A mother vertex in a graph G = (V,E) is a vertex v 
		// such that all other vertices in G can be reached 
		// by a path from v.
		// TC : N*(N+E)
		void motherVertex() {


			cout<<"\nMother vertices are : ";
			for(int i = 0; i <= nodes; i++) {

				vector<bool> visited(nodes+1, false);

				int count = 0;

				queue<int> qu;
				qu.push(i);
				visited[i] = true;

				while(not qu.empty()) {

					int top = qu.front();
					qu.pop();
					for(auto it: adj[top]) {

						if(not visited[it]) {

							count++;
							qu.push(it);
							visited[it] = true;
						}
					}
				}
				if(count == nodes)
					cout<<i<<" ";
			}
			cout<<endl;
		}

		void dfs(int node, vector<bool> &visited) {

			visited[node] = true;
			for(auto it: adj[node]) {

				if(!visited[it]) {

					dfs(it, visited);
				}
			}
		}


		// TC: O(V+E)
		// but it will only find one
		void motherVertexDFS() {

			vector<bool>visited(nodes+1, false);

			int last = 0;

			for(int i = 0; i <= nodes; i++) {

				if(not visited[i]) {

					last = i;
					dfs(i, visited);
				}
			}

			fill(visited.begin(), visited.end(), false);

			dfs(last, visited);

			for(int i = 0; i <= nodes; i++) {

				if(not visited[i]) {

					cout<<"Try with Different edge\n\n";
					return;
				}
			}
			cout<<"Mother vertex using DFS : "<<last<<endl;

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
		graph.motherVertex();
		graph.motherVertexDFS();

	}
  	fclose(stdin);
  	fclose(stdout);
}