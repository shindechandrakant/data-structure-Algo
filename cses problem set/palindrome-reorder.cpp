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
Problem link -> https://cses.fi/problemset/task/1755
*/

int main() {

    #ifndef ONLINE_JUDGE
        freopen("../io/input.txt", "r", stdin);
        freopen("../io/output.txt", "w", stdout);
        auto _start = high_resolution_clock::now();
    #endif

  
  	string str;
  	cin>>str;


  	map<char, int> mp;

  	for(int i = 0; i < str.size(); i++) {
  		mp[str[i]]++;
  	}
  	vector<char> palindrom(str.size(), '-');

  	int n = str.size();
  	int end = str.size()-1;
  	int start = 0;

  	bool possible = true;

  	while(mp.size() > 0) {

  		auto it = mp.begin();
  		mp.erase(it -> first);

  		if(n % 2 == 0 && it -> second == 1) {

  			possible = false;
  			break;
  		}
  		else if(n % 2 == 1 && it -> second == 1) {

  			if(palindrom[n/2] != '-') {

  				possible = false;
  				break;
  			}

  			palindrom[n/2] = it -> first;
  		} 
  		else {

  			int half = it -> second/2;

  			for(int i = 0; i < half; i++) {

  				palindrom[start++] = it -> first;
  				palindrom[end--] = it -> first;
  			}
  			// mp.erase(it.first);
  			if(it -> second % 2 != 0) {
  				mp[it -> first] = 1;
  			}

  		}
  	}


  	if(!possible){

  	  	cout<<"NO SOLUTION";
  	}
  	else {

	  	for(auto it : palindrom) 
	  		cout<<it;
  	}









    #ifndef ONLINE_JUDGE
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - _start);
        cout<<"\n\nTime :"<<(duration.count()/1000.0)<<" ms" << endl;
        fclose(stdin);
        fclose(stdout);
    #endif


}