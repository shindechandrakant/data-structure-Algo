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


ip

13
# Algorithms
This chapter covers the most basic algorithms.
## Sorting
Quick Sort is fast and widely used in pracice
Merge sort is a deterministic algorithm
## Searching
DFS and BFS are widely used graph searching
algorithms some varients of DFS are also used in game theory applications
# Data Structures
This chapter is all about data structures
It's a draft for now and will contain more sections in the future
# Binary Search Trees
*/

void tableOfContent(vector<string> &description) {

	vector<vector<string> > table;
	int n = description.size();
	vector<string> temp;
	string str;

	for(int i = 0; i < n; i++) {

		str = description[i];

		if(str[0] == '#') {

			if(str[1] == '#') {
				// SubTopic
				temp.push_back(str.substr(3));
			}
			else {
				// Heading
				table.push_back(temp);
				temp.clear();
				temp.push_back(str.substr(2));
			}
		}
		// cout<<str<<endl;
	}
	// cout<<"here";
	table.push_back(temp);
	vector<string> answer;
	cout<<table.size();


	for(int i = 0; i < table.size(); i++) {

		string current = to_string(i+1) + ". " + table[i][0];
		answer.push_back(current);
		cout<<"H: "<<current<<endl;

		for(int j = 1; j < table[i].size(); j++) {

			string temp = to_string(i+1) + "." + to_string(j) + ". " + table[i][j];
			answer.push_back(temp);
		}
	}

	for(int i = 0; i < answer.size(); i++) {

		cout<<answer[i]<<endl;
	}

}




int main() {

    #ifndef ONLINE_JUDGE
        freopen("../io/input.txt", "r", stdin);
        freopen("../io/output.txt", "w", stdout);
        auto start = high_resolution_clock::now();
    #endif

  
  int n;
  // cin>>n;

  // vector<string> vect;

  // for(int i = 0; i < n; i++) {

  // 	string str;

  // 	// getline(cin, str, '\n');
  // 	// cout<<i<<" "<<str<<endl;
  // 	// vect.push_back(str);
  // 	// cout<<i<<" "<<vect.size()<<"-> "<<vect[i]<<endl;
  // }

  cout<<"Outsie";


  cout<<"hh"<<vect.size();
  tableOfContent(vect);










    #ifndef ONLINE_JUDGE
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout<<"\n\nTime :"<<(duration.count()/1000.0)<<" ms" << endl;
        fclose(stdin);
        fclose(stdout);
    #endif


}