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
Problem link -> https://cses.fi/problemset/task/2205
*/


vector<string> grayCode(int n) {

    if(n == 1) {

        return { "0", "1" };
    }

    vector<string> result = grayCode(n-1);
    vector<string> currentResult;

    for(int i = 0; i < result.size(); i++) {

        string str = "0";
        str += result[i];
        currentResult.push_back(str);
    }

    for(int i = result.size()-1; i >= 0; i--) {

        string str = "1";
        str += result[i];
        currentResult.push_back(str);
    }



    return currentResult;

}



int main() {

    #ifndef ONLINE_JUDGE
        freopen("../io/input.txt", "r", stdin);
        freopen("../io/output.txt", "w", stdout);
        auto start = high_resolution_clock::now();
    #endif

  int n;
  cin>>n;

  vector<string> result = grayCode(n);


  for(auto &it: result) {

    cout<<it<<"\n";
  }


  // string str;

  // for(int i = 0; i < n; i++) {

  // 	str.push_back('0');
  // }


  // cout<<str<<endl;

  // for(long i = 1; i < (1l << n); i++) {

  // 	long x = i;
  // 	string old = str;
  // 	int counter = n-1;

  // 	while(x) {

  // 		old[counter] = (x % 2 == 0 ? '0' : '1');
  // 		x /= 2;
  // 		counter--;
  // 	}
  // 	cout<<old<<endl;
  // }











    #ifndef ONLINE_JUDGE
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout<<"\n\nTime :"<<(duration.count()/1000.0)<<" ms" << endl;
        fclose(stdin);
        fclose(stdout);
    #endif


}