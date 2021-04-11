#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define MOD 1000000007
#define vi vector<int>

void display(bool **arr, int n, int m) {


	// for(int i = 0; i <= m; i++) 
	// 	cout<<i<<" ";
	// cout<<endl;

	for(int i = 0; i <= n; i++) {

         for(int j = 0; j <= m; j++) {

             cout<<(arr[i][j])<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}

// bool subSetOfSum(int *set, int n, int target) 
// {
// 	bool **arr = new bool*[n+1];
// 	for(int i = 0; i <= n; i++) {
// 		arr[i] = new bool[target+1] { true };
// 	}


// 	for(int i = 1; i <= n; i++) 
// 	{
// 		for(int j = 1; j <= target; j++) 
// 		{

// 			if(set[i-1] > j) 
// 				arr[i][j] = arr[i-1][j];
// 			else
// 				arr[i][j] = arr[i-1][j] or arr[i-1][j-set[i-1]];
// 		}
// 	}
// 	display(arr, n, target);
// 	return arr[n][target];
// }

	
void bfs(bool **arr, int *set, int i, int j, int sum, int &ans, string str) {
    
    
    if(not arr[i][j]) {
        return;
    }
    
    if(sum == 0) {
    	cout<<str<<endl;
        ans++;
        return;
    }
    
    if(arr[i-1][j])
    	bfs(arr, set, i-1, j, sum, ans, str);
    if(arr[i-1][j-set[i-1]])
    	bfs(arr, set, i-1, j-set[i-1], sum-set[i-1], ans, str + to_string(set[i-1]) + " ");
}

int perfectSum(int *arr, int n, int sum)
{
    bool **status = new bool *[n+1];
    for(int i = 0; i <= n; i++) {
        
        status[i] = new bool [sum+1] { true };
    }
    
    for(int i = 1; i <= n; i++) {
        
        for(int j = 1; j <= sum; j++) {
            
            if(arr[i-1] > j) {
                
                status[i][j] = status[i-1][j];
            }
            else {
                status[i][j] = status[i-1][j] or status[i-1][j-arr[i-1]];
            }
        }
    }
       
    if(not status[n][sum]) {
        return 0;
    }
    int ans = 0;
    display(status, n, sum);
    bfs(status, arr, n, sum, sum, ans, "");
    return ans;
}

 
int main() {

	int n, target;
	cin>>n>>target;
	int *arr = new int[n];
	for(int i = 0; i < n; i++)
		cin>>arr[i];

	perfectSum(arr, n, target);


}