#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define MOD 1000000007
#define vi vector<lli>

void display(lli **arr, int n, int m) {

  cout<<endl<<endl;

	for(int i = 0; i <= n; i++) {

         for(int j = 0; j <= m; j++) {

             cout<<(arr[i][j])<<" ";
        }
        cout<<endl;
    }  
}

void countMaxScore(vi &cost, vi &value, int timeLeft) {
    
    
    int n = cost.size();
    lli **dp = new lli *[n+1];
    for(int i = 0; i <= n; i++)
        dp[i] = new lli[timeLeft + 1] { 0 };
    
    
    for(int i = 1; i <= n; i++) {
        
        for(int j = 1; j <= timeLeft; j++) {
            
            if(cost[i-1] > j)
                dp[i][j] = dp[i-1][j];
            else {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - cost[i-1]] + value[i-1]);
            }
            
        }
    }
    // display(dp, n, timeLeft);
    vi ans;
    vi pts;

    lli i = n;
    lli j = timeLeft;


    while(i > 0 and j > 0) {

      if(dp[i][j] != dp[i-1][j]) {

        ans.push_back(cost[i-1]);
        pts.push_back(value[i-1]);
        j = j - cost[i-1];
      }
      i--;
    }
 

    lli tem = dp[n][timeLeft];
    for(int i = 0; i < ans.size(); i++) {

      // cout<<ans[i]<<" "<<pts[i]<<endl;
      if(tem > pts[i])
          tem = pts[i];
    }
    cout<<abs(dp[n][timeLeft]-tem)<<endl;
}


int main() {
  
  int t;
  cin>>t;
  while(t--)
  {
    lli no, timeLeft;
    cin>>no>>timeLeft;
    
    
    vi weight(no);
    vi cost(no);
  
    for(int i = 0; i < no; i++) {
        cin>>weight[i]>>cost[i];
    }

    if(no == 1) {

      cout<<0<<endl;

    }
    else
      countMaxScore(cost, weight ,timeLeft); 

  }

}