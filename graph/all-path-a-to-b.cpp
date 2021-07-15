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
problem statement -> Count all possible paths between two vertices
Problem link -> https://www.geeksforgeeks.org/count-possible-paths-two-vertices/
*/

/*
ip 
1
4 8
0 1
0 4
1 4
0 2
3 2
1 3
2 4
2 1

*/

// template<typename dataType>
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


		void dfsToPath(int node, vb &visited, string psf, int target) {


			if(node == target) {

				cout<<psf<<endl;
				return;
			}

			visited[node] = true;



			for(auto it : adj[node]) {

				if(not visited[it]) {

					dfsToPath(it, visited, psf + to_string(it) + "->", target);
				}
			}
			visited[node] = false;
		}

		void findAllPathsAtoB(int start, int end) {

			vb visited(nodes+1, false);
			string path = to_string(start) + "->";

			visited[start] = true;

			dfsToPath(start, visited, path, end);
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
		graph.findAllPathsAtoB(0, 4);
	}

	fclose(stdin);
	fclose(stdout);

}

	 