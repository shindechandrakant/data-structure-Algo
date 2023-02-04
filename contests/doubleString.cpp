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
problem statement -> doubleString.cpp
Problem link -> https://codeforces.com/contest/1703/problem/D
*/

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
  		map<string, int> strs;

  		for(int i = 0; i < n; i++) {

  			string it;
  			cin>>it;
  			strs[it]++;
  		}

		
		string answer;  	
  		for(auto str1 : strs) {



  			string str = str1.first;
  			bool flag = false;
  			string temp;
  			temp.push_back(str1.first[0]);


  			for(int i = 1; i < str.size(); i++) {

  				string subStr = str.substr(i);

  				if(strs.count(subStr) == 1 || strs.count(temp) == 1) {

  					flag = true;
  					break;
  				} 
  				temp.push_back(str[i]);


  			}

  			if(flag) {
  				answer.push_back('1');
  			}else {

  				answer.push_back('0');
  			}


  		}

  		cout<<answer<<endl;




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

