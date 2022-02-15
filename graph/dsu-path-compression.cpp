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
problem statement -> dsu-path-compression.cpp
Problem link -> source
*/

class PathCompression {

	vector<int> rootArray;
	int nodes;

	public:

		PathCompression(int nodes) {

			rootArray.resize(nodes+1);
			this -> nodes = nodes;

			for(int i = 0; i <= nodes; i++) {
				rootArray[i] = i;
			}
		}


		// add edge. change parent 
		void addEdge(int u, int v) {

			int up = find(u);
			int vp = find(v);

			if(up != vp) {

				rootArray[vp] = up;
			}
		}

		// returns the parent of node
		int find(int root) {

			if(rootArray[root] == root)
				return root;

			return rootArray[root] = find(rootArray[root] );
		}

		// returns the boolean value, wether the nodes are connected or not
		bool isConnected(int x, int y) {

			return rootArray[x] == rootArray[y];
		}

};



int main() {

    #ifndef ONLINE_JUDGE
        freopen("../io/input.txt", "r", stdin);
        freopen("../io/output.txt", "w", stdout);
        freopen("../io/err.txt", "w", stderr);
        auto start = high_resolution_clock::now();
    #endif

  	
  	int edges, nodes;
    cin>>nodes>>edges;

    PathCompression quickFind(nodes);

    for(int i = 0; i < edges; i++) {

        int u, v;
        cin>>u>>v;
        quickFind.addEdge(u, v);
    }
  	

    int queries;
    cin>>queries;
    for(int i = 0; i < queries; i++) {

        int x, y;
        cin>>x>>y;

        if(quickFind.isConnected(x, y)) {

            cout<<x<<" "<<y<<" has common parent : ";
        }
        else {

            cout<<x<<" "<<y<<" are disconnected";
        }
        cout<<endl;


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

