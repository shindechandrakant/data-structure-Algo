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

char getChar(string str) {

	int num = stoi(str);
	if(num > 26)
		return ' ';

	return (char)(96 + num);
}

void encodeString(string str, string ssf) {


	if(str.size() == 0) {

		cout<<ssf<<endl;
		return;
	}

	if(str[0] == '0')
		return;
	if(str.size() == 1) {

		char ch = getChar(str);
		ssf.push_back(ch);
		cout<<ssf<<endl;
		return;
	}

	string num;
	num.push_back(str[0]);
	string rem = str.substr(1);
	encodeString(rem, ssf + getChar(num));
	rem = str.substr(2);
	num.push_back(str[1]);
	if(stoi(num) <= 26)
	encodeString(rem, ssf + getChar(num));

}

int main() {

    #ifndef ONLINE_JUDGE
        freopen("../io/input.txt", "r", stdin);
        freopen("../io/output.txt", "w", stdout);
        freopen("../io/err.txt", "w", stderr);
        auto start = high_resolution_clock::now();
    #endif

  

     string str;
     cin>>str;
	encodeString(str, "");















    #ifndef ONLINE_JUDGE
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout<<"\n\nTime :"<<(duration.count()/1000.0)<<" ms" << endl;
        fclose(stdin);
        fclose(stdout);
    #endif


}