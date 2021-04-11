#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
#define vi vector<ll>
#define pi pair<ll, ll>
#define v2d(name, m, n, inti) vector<vi>(name)(m, vi(n, inti))

// problem statement -> longest Path
// Problem link -> https://atcoder.jp/contests/dp/tasks/dp_g

class Graph {

	public:
		int edges;
		int vertices;
		list<int> *arr;
		Graph(int edges, int vertices) {

			this -> edges = edges;
			this -> vertices = vertices;
			arr = new list<int>[edges+1];
		}

		void addEdge(int u, int v)
		{
			arr[u].push_back(v);
		}


		int longestPath(int u, vi &dp) {

			if(arr[u].size() == 0)
				return 0;

			if(dp[u] != -1)
				return dp[u];

			int result = 0;
			for(auto it : arr[u]) {

				result = max(result, longestPath(it, dp) + 1);
			}
			return dp[u] = result;
		}
		void display() {

			for(int i = 0; i <= vertices; i++) {

				cout<<i<<" : ";
				for(auto it : arr[i])
					cout<<it<<" ";

				cout<<endl;
			}
		}
};


int main() {


	int n, m;
	cin>>n>>m;
	Graph g(n, m);
	for(int i = 0; i < m ; i++) {
		int u, v;
		cin>>u>>v;
		g.addEdge(u, v);
	}

	int result = 0;

	vi dp(n+1, -1);
	for(int i = 1; i <= n; i++)
		result = max(result, g.longestPath(i, dp));

	cout<<result;


	// g.display(); 
}