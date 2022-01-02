

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

int main() {

    #ifndef ONLINE_JUDGE
        freopen("../io/input.txt", "r", stdin);
        freopen("../io/output.txt", "w", stdout);
        auto start = high_resolution_clock::now();
    #endif

  
    // int n, y;
    // cin>>n>>y;

    // vector<int> track(n);

    // for(int i = 0; i < n; i++) {

    // 	cin>>track[i];
    // }

    // if(n == 1) {

    // 	cout<<track[0];
    // 	return 0;
    // }

    // vector<int> dp(n, 0);

    // dp[0] = track[0];
    // dp[1] = min(y, track[1]);
    // dp[2] = min(y, track[2]);

    // for(int i = 3; i < n; i++) {




    // }

     int houses, colours, k;
     cin>>houses>>colours>>k;

        vector<int> dp(houses + 1);
        dp[0] = 0;
        dp[1] = colours;
        dp[2] = colours * colours;

        for (int i = 3; i <= houses; ++ i) {
            dp[i] = dp[i - 1] * (colours - 1) + dp[i - 2] * (colours - 1); // same color
        }

        cout<<dp[houses]<<endl;


    #ifndef ONLINE_JUDGE
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout<<"\n\nTime :"<<(duration.count()/1000.0)<<" ms" << endl;
        fclose(stdin);
        fclose(stdout);
    #endif


}














