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
Problem link -> https://cses.fi/problemset/task/1622
*/


set<string> ans;

void formAllPermutations(int indx, string &str) {



	if(indx == str.size()) {

		// string temp = str;

		// reverse(temp.begin(), temp.end());	
		ans.insert(str);
		return;
	}


	set<char> st;
	for(int i = indx; i < str.size(); i++) {

		if(st.count(str[i]) == 1)
			continue;

		st.insert(str[i]);

		swap(str[i], str[indx]);
		formAllPermutations(indx+1, str);
		swap(str[i], str[indx]);
	}
}



int main() {

    #ifndef ONLINE_JUDGE
        freopen("../io/input.txt", "r", stdin);
        freopen("../io/output.txt", "w", stdout);
        auto start = high_resolution_clock::now();
    #endif

    string str;
    cin>>str;

	formAllPermutations(0, str);


	cout<<ans.size()<<endl;


	for(auto &it : ans) 
		cout<<it<<endl;









    #ifndef ONLINE_JUDGE
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout<<"\n\nTime :"<<(duration.count()/1000.0)<<" ms" << endl;
        fclose(stdin);
        fclose(stdout);
    #endif


}