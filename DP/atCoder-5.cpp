#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
#define vi vector<ll>
#define pi pair<ll, ll>
#define v2d(name, m, n, inti) vector<vi>(name)(m, vi(n, inti))
#define inf 1e18
// problem statement -> knapsack2 dp, sanket Sing Atcoder part 1
// Problem link -> https://atcoder.jp/contests/dp/tasks/dp_e

int main() {

	ll n, w;
	cin>>n>>w;
	vi weight(n);
	vi value(n);

	for(int i = 0; i < n; i++)	cin>>weight[i]>>value[i];

	vi dp(n*1000+1, inf);
	dp[0] = 0;
	dp[value[0]] = weight[0];
	for(int i = 1; i <= n; i++) {

		vi temp(n*1000+1, inf);
		for(ll j = 0; j <= n*1000; j++) {

			if(j < value[i-1]) 
				temp[j] = dp[j];
			else {
					temp[j] = min({dp[j], weight[i-1] + dp[j-value[i-1]], temp[j]});
			}
		}
		dp.swap(temp);
	}

	ll result = 0;
	for(ll i = 0; i <= n*1000; i++)
		if(dp[i] <= w)
			result = i;	

	cout<<result;
}

/*

#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define ll 				long long int
#define ld				long double
#define mod             1000000007
#define inf             1e18
#define endl			"\n"
#define pb 				push_back
#define vi              vector<ll>
#define vs				vector<string>
#define pii             pair<ll,ll>
#define ump				unordered_map
#define mp 				make_pair
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define all(n) 			n.begin(),n.end()
#define ff 				first
#define ss 				second
#define mid(l,r)        (l+(r-l)/2)
#define bitc(n) 		__builtin_popcount(n)
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define iter(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define log(args...) 	{ string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;	
template <typename T> T gcd(T a, T b){if(a%b) return gcd(b,a%b);return b;}
template <typename T> T lcm(T a, T b){return (a*(b/gcd(a,b)));}
vs tokenizer(string str,char ch) {std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;}
 
 
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cout << *it << " = " << a << endl;
	err(++it, args...);
}
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;
 
 
int main( ) {
  
	ll n, w;
	cin>>n>>w;
	vi val(n, 0);
	vi wt(n, 0);
	loop(i, 0, n-1) {
		cin>>wt[i]>>val[i];
	}
	ll dp1[n*1000+1];
	ll dp2[n*1000+1];
	loop(i, 0, n*1000) {
		dp1[i] = inf;
		dp2[i] = inf;
	}
	dp1[0] = 0;
	dp1[val[0]] = wt[0];
	loop(i, 1, n-1) {
		loop(j, 0, n*1000) {
			if(val[i] > j) {
				dp2[j] = dp1[j];
			} else {
				dp2[j] = min({dp2[j], dp1[j], wt[i] + dp1[j-val[i]]});
			}
		}
		loop(k, 0, n*1000) {
			dp1[k] = dp2[k];
			dp2[k] = inf;
		}
	}
	int result = 0;
	loop(i, 0, n*1000) {
		if(dp1[i] <= w) result = i;
	}
	cout<<result;
  
}







*/