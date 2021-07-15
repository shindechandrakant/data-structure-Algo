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


struct node { 

	int start, end, wt, id;

	bool operator < (const node &n) const{

		return this -> id < n.wt;
	}
};

bool cmp(node n1, node n2) { return n1.wt < n2.wt; }

struct compare {

	bool operator()(node &n1, node &n2) {

		// cout<<": "<<n1.id<<" "<<n2.id<<endl;
		return n1.wt > n2.wt;
	}

};


int findParent(int num, vector<int> &parent) {

	return num == parent[num] ? num : findParent(parent[num], parent);
}


int main() {

	freopen("../io/input.txt", "r", stdin);
	freopen("../io/output.txt", "w", stdout);

	int t;
	cin>>t;

	while(t--) {

		int nodes, edges;
		cin>>nodes>>edges;

		vector<node> nodeVector;

		priority_queue<node, vector<node>, compare> pq;

		for(int i = 0; i < edges; i++) {

			int x, y, wt;
			cin>>x>>y>>wt;
			pq.push({x, y, wt, i+1});
			nodeVector.push_back({x, y, wt});
		} 

		vector<bool> added(nodes+1, false);

		set<node> st;
		int count = 0;

		vector<int>parent(nodes+1);

		for(int i = 0; i <= nodes; i++) {

			parent[i] = i;
		}

		while(not pq.empty()) {

			node it = pq.top();
			pq.pop();
			if(count == nodes-1) { break; }

			int end = findParent(it.start, parent);
			int start = findParent(it.end, parent);

			if(added[it.start] && added[it.end]) {


				// check if cycle is there or not
				if(start == end)
					continue;
			}


			if(not added[it.start] and added[it.end]) {

				parent[it.start] = parent[it.end];
			}
			else
				parent[it.end] = parent[it.start];

			count++;
			st.insert(it);
			added[it.start] = added[it.end] = true;
			cout<<it.start<<" "<<it.end<<" "<<it.wt<<endl;

			for(int i = 1; i <= nodes; i++)
				cout<<parent[i]<<" ";

			cout<<endl;
		}



		// for(int i = 0; i < edges; i++) {

		// 	cout<<nodeVector[i].start<<" "<<nodeVector[i].end<<" "<<nodeVector[i].wt<<endl;
		// }

		// sort(nodeVector.begin(), nodeVector.end(), cmp);

		// cout<<"---------\n";
		// for(int i = 0; i < edges; i++) {

		// 	cout<<nodeVector[i].start<<" "<<nodeVector[i].end<<" "<<nodeVector[i].wt<<endl;

		// }

	}
	fclose(stdin);
	fclose(stdout);
}

	 