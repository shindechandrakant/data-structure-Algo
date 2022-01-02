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

// time complexity = O(n^3)
// wrong code

void brtueForce(string str) {

    int n = str.size();
    int count = 0;
    vector<vector<bool> > dp(n, vector<bool> (n, false));

    for(int gap = 0; gap < n; gap++) {

        for(int i = 0, j = gap; i < n && j < n; i++, j++) {

            if(gap == 0) {

                dp[i][j] = true;
            }
            else if(gap == 1) {

                dp[i][j] = str[i] == str[j];
            }
            else if(str[i] == str[j] && dp[i+1][j-1]) {

                dp[i][j] = true;
            }
            else {

                dp[i][j] = false;
            }

            // to print and calculate all substrings
            if(dp[i][j] && 0) {

                count++;
                for(int k = i; k <= j; k++) {

                    cout<<str[k];
                }
                cout<<endl;
            }

        }
    }

    // cout<<"total palindrome are possible : "<<count<<endl;
    vector<vector<int> >  countDp(n, vector<int> (n, 0));


    for(int gap = 0; gap < n; gap++) {

        for(int i = 0, j = gap; j < n; j++, i++) {

            if(gap == 0) {

                countDp[i][j] = 0;
            } else if(gap == 1) {

                countDp[i][j] = str[i] == str[j];
            }
            else {

                if(dp[i][j]) {

                    countDp[i][j] = 0;
                }
                else {

                    int minimum = INT_MAX;
                    for(int k = i; k < j; k++) {

                        int left = countDp[i][k];
                        int right = countDp[k+1][j];

                        minimum = min(minimum, left + right + 1);
                    }

                    countDp[i][j] = minimum;
                }
            }
        }
    }

    cout<<"minimum cuts required : "<<countDp[0][n-1];
}



int main() {

    #ifndef ONLINE_JUDGE
        freopen("../io/input.txt", "r", stdin);
        freopen("../io/output.txt", "w", stdout);
        auto start = high_resolution_clock::now();
    #endif

  
  	string str;
  	cin>>str;

    brtueForce(str);








    #ifndef ONLINE_JUDGE
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout<<"\n\nTime :"<<(duration.count()/1000.0)<<" ms" << endl;
        fclose(stdin);
        fclose(stdout);
    #endif


}