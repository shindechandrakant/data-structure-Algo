#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
#define vi vector<ll>
#define pi pair<ll, ll>
#define vb vector<bool>
#define vs vector<string>
#define newline(n) for(int iii = 0; iii < (n); iii++ )cout<<endl;
#define infor(vect) for(auto it : (vect)) { cout<<it<<" "; cout<<endl}
#define ump unordered_map
#define mp map
#define v2d(name, m, n, inti) vector<vi>(name)(m, vi(n, inti))
#define MOD 1000000007

/*
	problem statement -> 
	Problem link ->

*/

int main() {

    freopen("../io/input.txt", "r", stdin);
    freopen("../io/output.txt", "w", stdout);

    int n;
    cin>>n;
    vi array(n);

    for(int i = 0; i < n; i++)
    	cin>>array[i];

    for(auto it : array) cout<<it<<" ";
    
    //insertion sort
    for(int i = 1; i < n; i++) {

    	int key = array[i];
    	int j;
    	for(j = i-1; j >= 0 and array[j] > key; j--) {

    		array[j+1] = array[j];
    	}
    	array[j+1] = key;
    }
    for(auto it : array) cout<<it<<" ";
    fclose(stdin);
    fclose(stdout);

}