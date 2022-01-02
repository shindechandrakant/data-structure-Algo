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

bool isValidPermutation(vector<long> &arr) {

	for(int i = 0; i < arr.size()-1; i++) {

		if(abs(arr[i] - arr[i+1]) == 1) {

			return false;
		}
	}
	return true;
}

vector<long> answer;

void formPermutation(vector<long> &arr, int indx, bool &ans) {

	if(indx >= arr.size() || ans) {

		return;
	}

	if(isValidPermutation(arr)) {

		answer = arr;
		ans = true;
		return;
	}

	for(int i = indx; i < arr.size(); i++) {


		swap(arr[i], arr[indx]);
		formPermutation(arr, indx+1, ans);
		swap(arr[i], arr[indx]);
	}
}




int main() {

    #ifndef ONLINE_JUDGE
        freopen("../io/input.txt", "r", stdin);
        freopen("../io/output.txt", "w", stdout);
        auto start = high_resolution_clock::now();
    #endif
  
    long n;
    cin>>n;

   

    if(n == 2 or n == 3) {

    	cout<<"NO SOLUTION";
    }
    else {

    	for(int i = 1; i <= n; i++) {

    		if(i % 2 == 0) {

    			cout<<i<<" ";
    		}
    	}


    	for(int i = 1; i <= n; i++) {

    		if(i % 2 != 0) {

    			cout<<i<<" ";
    		}
    	}


  


    }



    // vector<long> arr(n);

    // for(int i = 0; i < n; i++) {

    // 	arr[i] = i+1;
    // }




    // bool ans = false;
    // formPermutation(arr, 0, ans);


    // if(ans) {

    // 	for(auto it : answer) {

    // 		cout<<it<<" ";
    // 	}
    // }
    // else {

    // 	cout<<"NO SOLUTION";
    // }











    #ifndef ONLINE_JUDGE
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout<<"\n\nTime :"<<(duration.count()/1000.0)<<" ms" << endl;
        fclose(stdin);
        fclose(stdout);
    #endif


}