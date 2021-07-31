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
problem statement -> 
Problem link -> 
*/

void displayGraph(vector<vb> &graph) {


	for(auto row: graph) {

		for(auto cell : row) {

			cout<<cell<<" ";
		}
		cout<<endl;
	}
}


void dfs(vector<vb> &graph, int node, vector<bool> &visited, stack<int> &stk) {

	visited[node] = true;
	for(int i = 0; i < graph.size(); i++) {

		if(not visited[i] and graph[node][i]) {

			dfs(graph, i, visited, stk);
		}
	}
	stk.push(node);
}

void dfs(vector<vb> &graph, int node, vector<bool> &visited) {


	visited[node] = true;

	for(int i = 0; i < graph.size(); i++) {


		if(not visited[i] and graph[node][i]) {

			dfs(graph, i, visited);
		}
	}
}


int main() {

	freopen("../io/input.txt", "r", stdin);
	freopen("../io/output.txt", "w", stdout);

	int nodes, edges;

	cin>>nodes>>edges;

	vector<vector<bool> > graph(nodes+1, vector<bool>(nodes+1, false));
	vector<vector<bool> > reverseGraph(nodes+1, vector<bool>(nodes+1, false));

	bool bidir = false;

	for(int i = 0; i < edges; i++) {

		int u, v;
		cin>>u>>v;
		graph[u][v] = true;
		reverseGraph[v][u] = true;
	}

	displayGraph(graph);
	newline(5);
	vector<bool> visited(nodes+1, false);
	stack<int> stk;
	for(int i = 1; i <= nodes; i++) {

		if(not visited[i]) {

			dfs(graph, i, visited, stk);
		}
	}

	fill(visited.begin(), visited.end(), false);

	int components = 0;

	while(not stk.empty()) {

		if(not visited[stk.top()]) {

			dfs(reverseGraph, stk.top(), visited);
			components++;
		}
		stk.pop();
	}

	cout<<components<<endl;


	fclose(stdin);
	fclose(stdout);

}

	 