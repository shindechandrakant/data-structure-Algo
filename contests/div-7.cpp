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
problem statement -> div-7.cpp
Problem link -> source
*/

int numDiff(int n1, int n2) {

	int diff = 0;

	string org = to_string(n1);
	string newn = to_string(n2);

	if(org.size() != newn.size())
		return 999999;

	for(int i = 0; i < org.size(); i++) {

		if(org[i] != newn[i])
			diff++;
	}

	return diff;
}



int main() {

    #ifndef ONLINE_JUDGE
        freopen("../io/input.txt", "r", stdin);
        freopen("../io/output.txt", "w", stdout);
        freopen("../io/err.txt", "w", stderr);
        auto start = high_resolution_clock::now();
    #endif

  	
  	
  	int t;
  	cin>>t;

  	while(t--) {

  		int n;
  		cin>>n;
  		int rem = n %  7 ;

  		if(rem == 0){
  			cout<<n<<endl;
  			continue;
  		}

  		int ans = INT_MAX;
  		int ans1 = 0;
  		
  		int newNum = n -rem;

  		while(newNum < 2000) {

  			int t = min(ans, numDiff(n, newNum));

  			if(t < ans){

  				ans = t;
  				ans1 = newNum;
  			}
  			newNum += 7;
  		}


  		cout<<ans1<<endl;

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

