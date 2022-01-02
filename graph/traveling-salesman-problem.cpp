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

vector<vector<int> > grid(4, vector<int>(4, 0));

int dp[(1<<10)+2][20];



int tsp(int mask, int curr, int n) {

    cout<<mask<<" "<<curr<<"\n";

    if(mask == ((1 << n) -1)) {
        // base case
        return grid[curr][0];
    }
    if(dp[mask][curr] != -1) {

        return dp[mask][curr];
    }
    int ans = INT_MAX;

    for(int city = 0; city < n; city++) {

        if((mask & (1 << city)) == 0) {

            ans = min(ans, tsp(mask | (1 << city), city, n) + grid[curr][city]);
        }
    }
    return dp[mask][curr] = ans;
}



int main() {

    #ifndef ONLINE_JUDGE
        freopen("../io/input.txt", "r", stdin);
        freopen("../io/output.txt", "w", stdout);
        auto start = high_resolution_clock::now();
    #endif

    memset(dp, -1, sizeof(dp));

    int n; 
    cin>>n;

    for(int i = 0; i < n; i++) {

        int x, y, c;
        cin>>x>>y>>c;
        x--;
        y--;

        grid[x][y] = c;
        grid[y][x] = c;
    }

    for (int i = 0; i < (n); ++i)
    {
        for(int j = 0; j < n; j++) {

            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<tsp(1, 0, n);






    #ifndef ONLINE_JUDGE
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout<<"\n\nTime :"<<(duration.count()/1000.0)<<" ms" << endl;
        fclose(stdin);
        fclose(stdout);
    #endif


}