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
problem statement -> Kosaraju Algo to find Strongly Connected Components
Steps :-> 1: Apply Random Order DFS and Backtrack and store nodes in stack 
		  2: Reverse All The Graph
		  3: Apply DFS using Stack on new Grph and count Strongly connected components
*/
class Graph {

	int nodes, edges;
	list<int> *adj;
	list<int> *reverseGraph;

	public:
		Graph(int nodes) {

			this -> nodes = nodes;
			this -> adj = new list<int>[nodes+1];
			this -> reverseGraph = new list<int>[nodes+1];
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

		void revGraph() {


			for(int i = 1; i <= nodes; i++) {

				for(auto it : adj[i]) {

					reverseGraph[it].push_back(i);
				}
			}

			for(int i = 0; i <= nodes; i++) {

				cout<<i<<" : ";
				for(auto edge : reverseGraph[i]) {

					cout<<edge<<" ";
				}
				cout<<endl;
			}
		}

		void dfsHelper(int node, vb &visited, stack<int> &dfsStack) {

			visited[node] = true;

			cout<<node<<" ";
			for(auto it: adj[node]) {

				if(not visited[it]) {

					dfsHelper(it, visited, dfsStack);
				}
			}
			dfsStack.push(node);
		}

		stack<int> dfsOriginalGraph() {

			vector<bool> visited(nodes+1, false);
			stack<int> dfsStack;

			for(int i = 1; i <= nodes; i++) {

				if(not visited[i]) {

					dfsHelper(i, visited, dfsStack);
				}
			}
			return dfsStack;
		}

		void connectedComponentDFS(int node, vector<bool> &visited) {

			visited[node] = true;

			for(auto it : reverseGraph[node]) {

				if(not visited[it]) {

					connectedComponentDFS(it, visited);
				}

			}

		}

		int findConnectedComponents(stack<int> &dfsStack) {

			int components = 0;

			vector<bool> visited(nodes+1, false);

			while(not dfsStack.empty()) {

				int top = dfsStack.top();
				dfsStack.pop();

				if(not visited[top]) {

					connectedComponentDFS(top, visited);
					components++;
				}
			}
			return components;
		}


};

int main() {

	freopen("../io/input.txt", "r", stdin);
	freopen("../io/output.txt", "w", stdout);

	int t = 1;
	// cin>>t;

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
		stack<int> dfsStack = graph.dfsOriginalGraph();
		graph.revGraph();

		int components = graph.findConnectedComponents(dfsStack);

		cout<<components;


	}

	fclose(stdin);
	fclose(stdout);

}

