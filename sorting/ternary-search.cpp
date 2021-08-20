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


int ternarySearch(vector<int> &array, int target) {

	int left = 0;
	int right = array.size()-1;


	while(left <= right) {

		int mid1 = left + (right-left)/3;
		int mid2 = right - (right-left)/3;

		if(array[mid1] == target) {

			return mid1;
		}
		if(array[mid2] == target) {

			return mid2;
		}


		if(target < array[mid1]) {

			right = mid1-1;
		}
		else if(target > array[mid2]) {

			left = mid2 + 1;
		}
		else {

			left = mid1 + 1;
			right = mid2 - 1;
		}
	}

	return -1; 

}









int main() {

    freopen("../io/input.txt", "r", stdin);
    freopen("../io/output.txt", "w", stdout);

    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i = 0; i < n; i++) {

    	cin>>arr[i];
    }

    sort(arr.begin(), arr.end());


    infor(arr);
    int queries;
    cin>>queries;

    for(int i = 0; i < queries; i++) {

    	int val;
    	cin>>val;

    	cout<<val<<" -> "<<ternarySearch(arr, val)<<endl;
    }




    fclose(stdin);
    fclose(stdout);

}