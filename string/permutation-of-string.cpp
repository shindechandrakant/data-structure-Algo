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

void printPermuatations(string str, int left, int right) {

	if(left == right) {

		cout<<str<<endl;
		return;
	}

	// cout<<left<<" "<<right<<": \n";
	set<char> chars;
	for(int i = left; i <= right; i++) {

		if(chars.count(str[i]) == 0) {

			chars.insert(str[i]);
			swap(str[i], str[left]);
			printPermuatations(str, left+1, right);
			swap(str[i], str[left]);
		}
	}
}

void newWay(string str, string ssf) {


	if(str.size() == 1) {

		ssf.push_back(str[0]);
		cout<<ssf<<endl;
		return;
	}

	for(int mid = 0; mid < str.size(); mid++) {


		string left = str.substr(0, mid);
		string right = str.substr(mid+1);
		string tt = left + right;
		newWay(tt, ssf + str[mid]);
	}




}



int main() {

  	freopen("../io/input.txt", "r", stdin);
  	freopen("../io/output.txt", "w", stdout);
  	auto startExecution = high_resolution_clock::now();


	string str;
	cin>>str;
	// printPermuatations(str, 0, str.size()-1);

	newWay(str, "");



	auto stopExecution = high_resolution_clock::now();
	auto durationExecution = duration_cast<microseconds>(stopExecution - startExecution);
	cout<<"\n\nTime :"<<(durationExecution.count()/1000.0)<<" ms"<<endl;
	fclose(stdin);
	fclose(stdout);
}