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
Problem link -> https://codeforces.com/contest/1610/problem/B
*/

bool isItPalindrome(vector<int> &vect, int element) {

	int start = 0;
	int end = vect.size()-1;


	while(start < end) {

		if(vect[start] == element){

			start++;
		}
		else if(vect[end] == element) {

			end--;
		}
		else if(vect[start] != vect[end]) {

			return false;
		}
		else {

			start++;
			end--;
		}
	}


	return true;
}

int main() {

    #ifndef ONLINE_JUDGE
        freopen("../io/input.txt", "r", stdin);
        freopen("../io/output.txt", "w", stdout);
        auto start = high_resolution_clock::now();
    #endif

  
    int t;
    cin>>t;

    while(t--) {

    	int n;
    	cin>>n;
    	vector<int> vect(n);
    	set<int> st;
    	for(int i = 0; i < n; i++) {

    		cin>>vect[i];
    		st.insert(vect[i]);
    	}

    	bool isItPossible = false;

    	if((n/2+1) >= st.size()) {

	    	for(auto it : st) {

	    		if(isItPalindrome(vect, it)) {

	    			isItPossible = true;
	    			break;
	    		}
	    	}
    	}


    	cout<<(isItPossible ? "YES" : "NO")<<endl;
    }

    #ifndef ONLINE_JUDGE
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout<<"\n\nTime :"<<(duration.count()/1000.0)<<" ms" << endl;
        fclose(stdin);
        fclose(stdout);
    #endif
}