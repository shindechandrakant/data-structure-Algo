#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define MOD 1000000007
#define vi vector<int>

// problem link
// https://www.geeksforgeeks.org/gold-mine-problem/


void display(vector<vector<int>> &M) {

	 for(int i = 0; i < M.size(); i++) 
	 {
         for(int j = 0; j < M[i].size(); j++)
         {
             cout<<M[i][j]<<" ";
             
         }
         cout<<endl;
    }
    cout<<endl<<endl;
}

int maxGold(int n, int m, vector<vector<int>> M) {
        
    vector<vector<int> > copy(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++)
    {
        copy[i][0] = M[i][0];
    }
   

    display(M);
    for(int j = 1; j < m; j++) {
        
        for(int i = 0; i < n; i++)
        {
            
            int max1 = copy[i][j-1] + M[i][j];
            
            int max2 = 0;
            int max3 = 0;
            
            if(i+1 < n)
                max2 = copy[i+1][j-1] + M[i][j];
                    
            if(i-1 >= 0)
                max3 = copy[i-1][j-1] + M[i][j];
            
            max1 = max(max1, max2);
            max1 = max(max1, max3);
            
            copy[i][j] = max1;
        }
        display(copy);
    }
        
   
    int ans = 0;
         
    for(int i = 0; i < n; i++)
       ans = max(ans, copy[i][m-1]);
         
         
    return ans;
}


int main(){

    int n, m;
    cin>>n>>m;
    vector<vector<int>> M(n, vector<int>(m, 0));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++)
            cin>>M[i][j];
    }
    cout<<maxGold(n, m, M)<<"\n";
    return 0;
}