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
problem statement -> 
Problem link -> 
1. https://www.codechef.com/NIUM2101/problems/ALPDIFF
3:https://www.codechef.com/NIUM2101/problems/DIVCLASS
2: https://www.codechef.com/NIUM2101/problems/ARRQUERY
*/

void questionOne() {

	int t;
	cin>>t;

	while(t--) {

		string a, b;
		cin>>a>>b;

		set<char> st;
		for(int i = 0; i < a.size(); i++) {

			st.insert(a[i]);
		}


		set<char> ans;
		for(int i = 0; i < b.size(); i++) {

			if(st.count(b[i]) == 0) {
				ans.insert(b[i]);
			}


		}




		if(ans.size() == 0) {

			cout<<-1<<endl;
			continue;
		}


		// sort(ans.begin(), ans.end());

		for(auto it : ans)
			cout<<it;

		cout<<endl;


	}
}


void questionTwo() {


	ll n, q;
	cin>>n>>q;

	vector<ll> arr(n);

	for(int i = 0; i < n; i++) {

		cin>>arr[i];
	}


	while(q--) {


		ll left, right, val;
		cin>>left>>right>>val;

		auto it = lower_bound(arr.begin()+left-1, arr.begin()+right, val);

		// cout<< *it<<" ";
		auto last = arr.begin()+right;
		int dist = distance(it, last);
		cout<<dist<<endl;




	}
}


void questionThree() {

	int t;
	cin>>t;
	while(t--) {

		int n;
		cin>>n;
		map<int ,int> mp;
		ll sum = 0;
		for(int i = 0; i < n; i++) {

			int x;
			cin>>x;
			mp[x]++;
		}

		if(n < 12 ) {

			cout<<"no\n";
		}
		else {

			if(n == 12 or mp.size() == 12) {

				cout<<"yes\n";
			}
			else if(mp.size() > 12) {

				cout<<"no\n";
			}
			else{

				cout<<"yes\n";
			}


		} 






	}


}

int main() {

    #ifndef ONLINE_JUDGE
        freopen("../io/input.txt", "r", stdin);
        freopen("../io/output.txt", "w", stdout);
        auto start = high_resolution_clock::now();
    #endif

  

        questionThree();










    #ifndef ONLINE_JUDGE
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout<<"\n\nTime :"<<(duration.count()/1000.0)<<" ms" << endl;
        fclose(stdin);
        fclose(stdout);
    #endif


}