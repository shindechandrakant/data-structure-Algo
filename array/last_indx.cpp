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

int lastIndex(int pos, vector<int> &arr, int val) {

	if(arr.size() <= pos) {

		return -1;
	}

	int previous = lastIndex(pos+1, arr, val);
	if(previous == -1) {

		if(arr[pos] == val) {

			previous = pos;
		}
	}

	return previous;
}

int firstIndx(int pos, vector<int> &arr, int val) {

	if(pos >= arr.size()) {

		return -1;
	}

	if(arr[pos] == val) {

		return pos;
	}

	return firstIndx(pos+1, arr, val);

}


vector<int> allIndx(int pos, vector<int> &arr, int val) {

	if(pos >= arr.size()) {

		return { };
	}

	vector<int> ans = allIndx(pos+1, arr, val);

	if(arr[pos] == val) {

		ans.push_back(pos);
	}
	return ans;
}



int main() {

    #ifndef ONLINE_JUDGE
        freopen("../io/input.txt", "r", stdin);
        freopen("../io/output.txt", "w", stdout);
        auto start = high_resolution_clock::now();
    #endif


 //    int n, val;
 //    cin>>n>>val;
 //    vector<int> arr(n);
 //    for(int i = 0; i < n; i++) cin>>arr[i];

 //    cout<<lastIndex(0, arr, val)<<endl;
	// cout<<firstIndx(0, arr, val)<<endl;
	// arr = allIndx(0, arr, val);

	// infor(arr);


        string str = "Chandrakant";

        cout<<str.substr(6,2);





    #ifndef ONLINE_JUDGE
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout<<"\n\nTime :"<<(duration.count()/1000.0)<<" ms" << endl;
        fclose(stdin);
        fclose(stdout);
    #endif


}