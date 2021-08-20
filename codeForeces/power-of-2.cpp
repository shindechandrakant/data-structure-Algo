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

vector<string> powerOfTwos() {

	vector<string> answer;


	for(ll i = 0; i <= 36; i++) {

		answer.push_back(to_string((ll)1l<<i));
		cout<<answer[i]<<endl;
	}

	return answer;
}

int main() {

    freopen("../io/input.txt", "r", stdin);
    freopen("../io/output.txt", "w", stdout);

    ll t;
    cin>>t;

    vector<string> pows = powerOfTwos();

    while(t--) {


    	string k;
    	cin>>k;



    }






    fclose(stdin);
    fclose(stdout);

}