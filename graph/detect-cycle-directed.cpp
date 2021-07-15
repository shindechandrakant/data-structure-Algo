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
	1 -> using BFS non recursive--------not completed
	2 -> using BFS recursive------------not completed
	3 -> using DFS non recursive--------not completed
	4 -> using DFS recursive------------completed
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

			cout<<"\n";
		}

		//------------------------------------------
		// helper for detectCycleUsingDFSRecursiveMethod
		bool isCycleDFSRecursive(vb &visited, vb &checked, int node) {


			visited[node] = true;
			checked[node] = true;

			for(auto it : adj[node]) {

				if(checked[it]) {

					// cycle is detected
					return true;
				} else if(not visited[it] and isCycleDFSRecursive(visited, checked, it)) { 

					// to avoid visited calls
					return true;
				}


			}

			checked[node]= false;
			return false;
		}

		// detect cycle using dfs recursive solution
		void detectCycleUsingDFSRecursiveMethod() {


			vb visited(nodes+1, false);

			for(int i = 0; i <= nodes; i++) {

				if(not visited[i]) {

					vb checked(nodes+1, false);

					if(isCycleDFSRecursive(visited, checked, i)) {

						cout<<"DFS Rec : Given graph is cyclic"<<endl;
						return;
					}
				}
			}

			cout<<"DFS Rec : Given graph is Acyclic\n";
			cout<<endl;
		}

		//----------------------------------------
		//---Wrong answer
		// helper for isCycleDFSIterative
		bool isCycleDFSIterative(vb &visited, int node) {

			stack<int> stk;
			vb stacked(nodes+1, false);
			
			stk.push(node);
			stacked[node] = true;

			while(not stk.empty()) {

				int top = stk.top();
				stk.pop();
				visited[top] = true;

				for(auto it : adj[top]) {

					if(not stacked[it] and not visited[it]) {

						stk.push(it);
						stacked[it] = true;

					} else if(visited[it] and stacked[it]) {

						return true;
					}
				}
			}



			return false;
		}
		// detect cycle using dfs iterative solution
		void detectCycleUsingDFSIterativeMethod() {

			vb visited(nodes+1, false);

			for(int i = 0; i <= nodes; i++) {

				if(not visited[i]) {

					if(isCycleDFSIterative(visited, i)) {

						cout<<"DFS Itr : Given graph is cyclic"<<endl;
						return;
					}

				}
			}

			cout<<"DFS Itr : Given graph is Acyclic\n";
			cout<<endl;
		}
		//-----------------------------------------
		//wrong solutions
		// helper for isCycleDFSIterative
		bool isCycleBFSIterative(vb &visited, int node) {


			queue<int> q;
			q.push(node);

			vb added(edges+1, false);
			added[node] = true;

			while(not q.empty()) {

				int front = q.front();
				q.pop();
				visited[front] = true;

				for(auto it : adj[front]) {

					if(not added[it]) {

						added[it] = true;
						q.push(it);
					}
					else if(not visited[it]) {
						return true;
					}

				}




			}


			return false;
		}
		
		// detect cycle using bfs iterative solution
		void detectCycleUsingBFSIterativeMethod() {

			vb visited(nodes+1, false);

			for(int i = 0; i <= nodes; i++) {

				if(not visited[i]) {

					if(isCycleBFSIterative(visited, i)) {

						cout<<"BFS Itr : Given graph is cyclic\n\n";
						return;
					}
				}
			}
			cout<<"BFS Itr : Given graph is Acyclic\n\n";
		}

		//--------------------------------------------
		// find no. of cycles

};



int main() {

	freopen("../io/input.txt", "r", stdin);
	freopen("../io/output.txt", "w", stdout);

	int t;
	cin>>t;
	while(t--) {

	
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
		g.detectCycleUsingBFSIterativeMethod();
		// g.detectCycleUsingDFSIterativeMethod();
		// g.detectCycleUsingDFSRecursiveMethod();

	}



	fclose(stdin);
	fclose(stdout);

}

 //    bool isCycle(vector<bool> &visited, int n, vector<bool> &check) {
	       
	 //        visited[n] = true;
	 //        check[n] = true;
	        
	 //        for(auto it: adj[n]) {
	            
	 //            if(check[it] )
	 //                return true;
	 //            else if(not visited[it] and isCycle(visited, it, check)) 
	 //                 return true;
	 //        }
	 //        check[n] = false;
	 //        return false;
	 //    }

		// void detectCycleDFSUndirectedGraph() {

		// 	vector<bool> visited(nodes+1, false);
     

		// 	for(int i = 0; i <= nodes; i++) {

		// 		if(not visited[i]) {

		// 			vb check(nodes+1, false);

		// 			if(isCycle(visited, check, i)) {

		// 				cout<<"Cycle is present ";
		// 				return;
		// 			}
		// 		}

		// 		cout<<"Graph is Acyclic";
		// 	}
		// }
