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
*/


int counting(string s){

	  int current = 1;
	  int preview = 0;
	  int result = 0;

      for (int i = 1; i < s.size(); i++) {
      	
          if (s[i] == s[i - 1]) {

          	current++;
          }
          else 
          {
              result += min(current, preview);
              preview = current;
              current = 1;
          }
      }
      return result + min(current, preview);
}



vector<int> maxRevenue(vector<vector<int> > salesRecord) {


    vector<int> ans;

    for(int i = 0; i < salesRecord.size(); i++) {

        int profit = *max_element(salesRecord[i].begin(), salesRecord[i].end());
        ans.push_back(profit);
    }

    return ans;
}



long unlockKey(long key) {

    long answer = 0;
    string str = to_string(key);

    if(key > 0)
        sort(str.begin(), str.end());
    else 
        sort(str.begin(), str.end(), greater<char>());

    int indx = 0;
    cout<<str<<" ";

    while(indx < str.size() && str[indx] == '0')  {

        indx++;
    }

    if(key > 0)
        swap(str[indx], str[0]);
    else
        str.pop_back();

    for(int i = 0; i < str.size(); i++) {

        answer = answer * 10;
        answer += (str[i] - '0');
    }

    return key > 0 ? answer : answer * -1;
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


        long n;
        cin>>n;
        cout<<unlockKey(n)<<endl;
        }
  
    // int n, m;
    // cin>>n>>m;

    // vector<vector<int> > vect(n, vector<int>(m, 0));


    // for(int i = 0; i < n; i++) {

    //     for(int j= 0; j < m; j++) {

    //         cin>>vect[i][j];
    //     }
    // }

    // vector<int> ans = maxRevenue(vect);

    // for(auto it: ans) cout<<it<<" ";


    #ifndef ONLINE_JUDGE
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout<<"\n\nTime :"<<(duration.count()/1000.0)<<" ms" << endl;
        fclose(stdin);
        fclose(stdout);
    #endif


}