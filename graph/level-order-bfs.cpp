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

// problem statement -> to find level order traversal
// Problem link ->
/*
    1
    5 8
    0 4
    0 1
    0 3
    1 2
    3 2
    4 2
    4 5
    2 5
*/

class Graph {

    int nodes, edges;
    list<int> *adj;

    public:
        Graph(int nodes, int edges) {

            this -> edges = edges;
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


        void levelOrderTraversal() {

            vb visited(nodes+1, false);
            unordered_map<int, vector<int>> levels;
            queue<pair<int, int> > q;

            q.push({0, 0});
            visited[0] = true;


            while(not q.empty()) {

                auto front = q.front();
                q.pop();

                levels[front.second].push_back(front.first);

                for(auto it : adj[front.first]) {

                    if(not visited[it]) {

                        visited[it] = true;
                        q.push({it, front.second+1});
                    }
                }
            }

            for(auto vec : levels) {

                cout<<vec.first<<" : ";
                for(auto it : vec.second) {

                    cout<<it<<" ";
                }
                cout<<endl;
            }


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

        Graph graph(nodes, edges);


        for(int i = 0; i < edges; i++) {
            int u, v;
            cin>>u>>v;

            graph.addEdge(u, v, true);

        }

        graph.printGraph();
        graph.levelOrderTraversal();

    }

    fclose(stdin);
    fclose(stdout);
}