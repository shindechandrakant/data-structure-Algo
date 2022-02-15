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
problem statement -> starter-24-codechef-3.cpp
Problem link -> source
*/

bool isPalindrome1(string str) {

	int start = 0;
	int end = str.size()-1;

	while(start < end) {

		if(str[start] == str[end])
			return false;


		start++;
		end--;
	}


	return true;

}

bool isPalindrome(string &str) {


	int start = 0;
	int end = str.size()-1;

	bool flag = false;
	int indx = end;

	while(start < end) {

		if(str[start] == str[end]) {

			swap(str[indx], str[start]);
			if(str[start] == str[end])
				flag = true;
			indx--;
		}

		start++;
		end--;
	}
	return flag;

}




int main() {

    #ifndef ONLINE_JUDGE
        freopen("../io/input.txt", "r", stdin);
        freopen("../io/output.txt", "w", stdout);
        freopen("../io/err.txt", "w", stderr);
        auto start = high_resolution_clock::now();
    #endif

  	
    int t;
    cin>>t;

    while(t--) {

    	int n;
    	cin>>n;
    	string str;
    	cin>>str;

    	if(n%2 != 0) {

    		cout<<"NO\n";
    		continue;
    	}
    	else {

	
			sort(str.begin(), str.end());
			bool ans = isPalindrome(str);
			if(ans || !isPalindrome1(str))
				cout<<"NO\n";
			else {
				cout<<"YES\n";
    			cout<<str<<endl;
			}
    	}

    }
 


    #ifndef ONLINE_JUDGE
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout<<"\n\nTime :"<<(duration.count()/1000.0)<<" ms" << endl;
        fclose(stdin);
        fclose(stdout);
        fclose(stderr);
    #endif
}

