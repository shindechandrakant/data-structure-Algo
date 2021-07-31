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

void megreArray(vi &array, int start, int mid, int end) {



	



	
}


void mergeSort(vi &array, int start, int end) {

	if(start == end) {	return;	}

	int mid = (start + end) / 2;
	mergeSort(array, start, mid);
	mergeSort(array, mid+1, end);
	megreArray()

}


int main() {

    freopen("../io/input.txt", "r", stdin);
    freopen("../io/output.txt", "w", stdout);


	int n;
    cin>>n;
    vi array(n);

    for(int i = 0; i < n; i++)
    	cin>>array[i];

    // print array before sorting
    for(auto it : array) cout<<it<<" ";
    
    //Merge sort function

    mergeSort(vi, 0, n-1);


    // print array after sorting
    for(auto it : array) cout<<it<<" ";






    fclose(stdin);
    fclose(stdout);

}