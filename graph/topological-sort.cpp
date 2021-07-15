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

// problem statement -> Topological sorting
// Problem link -> https://www.geeksforgeeks.org/topological-sorting/
/*
	

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

#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class graph {

	public:
		int vertices;
		list<int> *adj;
		int *inDegree;
		int *outDegree;

		graph(int v) {

			inDegree = new int[v+1]{ 0 };
			outDegree = new int[v+1]{ 0 };
			vertices = v;
			adj = new list<int>[vertices+1];
		}

		void add_edge(int u, int v) {

			outDegree[u]++;
			inDegree[v]++;
			adj[u].push_back(v);
		}

		void display() {

			for(int i = 1; i <= vertices; i++)
			{
				cout<<" "<<i<<" : ";
				for(auto it : adj[i]) {

					cout<<it<<" ";
				}
				cout<<endl;
			}
		}

		void showDegree() {

			cout<<endl<<endl;
			cout<<"\tin\tout"<<endl;
			for(int i = 1; i <= vertices; i++)
			{
				cout<<i<<"\t"<<inDegree[i]<<"\t"<<outDegree[i]<<endl;
			}
		}

		void calculateDegree() {

			vector<int>inD(vertices+1, 0);
			vector<int>outD(vertices+1, 0);

			for(int i = 1; i <= vertices; i++)
			{
				outD[i] = adj[i].size();

				for(auto it : adj[i])
				{
					inD[it]++;
				}

			}

			cout<<endl<<endl;
			cout<<"\tin\tout"<<endl;
			for(int i = 1; i <= vertices; i++)
			{
				cout<<i<<"\t"<<inD[i]<<"\t"<<outD[i]<<endl;
			}
		}

		void reduceDegree(vector<int> &degree, int node, vector<bool> &visited) {

			for(auto it : adj[node]) {

				if(not visited[it]) {

					degree[it]--;
				}
			}
		}

		int zeroDegree(vector<int> &degree, vector<bool> &visited) {

			for(int i = 1; i <= vertices; i++)
			{
				if(not visited[i] && degree[i] == 0)
					return i;
			}

			return -1;
		}

		void getDegree(vector<int> &degree) {

			for(int i = 1; i <= vertices; i++)
				degree[i] = inDegree[i];
		}

		void topoLogicalSort() {

			vector<bool>visited(vertices+1, false);
			vector<int>degree(vertices+1, 0);
			getDegree(degree);

			int node = zeroDegree(degree, visited);
			
			while(node != -1) {

				node = zeroDegree(degree, visited);
				if(node == -1)
					break;
				cout<<node<<" ";
				visited[node] = true;
				reduceDegree(degree, node, visited);
			}

			for(int i = 1; i <= vertices; i++)
			{
				if(not visited[i])
				{
					cout<<endl<<"Cycle detected ";
					break;
				}
			}
		}
};



int main()
{
	int vertices,edges;
	cin>>vertices>>edges;
	graph g(vertices);
	for (int i = 0; i < edges; ++i) {

		int u,v;
		cin>>u>>v;
		g.add_edge(u, v);
	}
	g.display();
	g.showDegree();
	// g.calculateDegree();

	cout<<endl<<endl<<"Topo : ";
	g.topoLogicalSort();
}







