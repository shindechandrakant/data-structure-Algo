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

struct TrieNode {

	std::map<char, TrieNode*> data;
	bool isEnding;
	char currentChar;
	TrieNode() {

		isEnding = false;
		currentChar = '-';
	}
};

void insertIntoTrie(TrieNode *root, const string &str, int indx) {

	if(indx >= str.size()) {

		return;
	}

	if(root -> data.count(str[indx]) == 0) {

		// data not present

		TrieNode *node = new TrieNode();
		node -> currentChar = str[indx];


		root -> data[str[indx]] = node;


		// cout<<"inserting : "<<str[indx]<<endl;

		if(indx == str.size()-1) {
			node -> isEnding = true;
			return;	
		}

		insertIntoTrie(node, str, indx+1);

	}
	else {

		// data already exist
		// cout<<"Already Exist : "<<str[indx]<<endl;
		insertIntoTrie(root->data[str[indx]], str, indx+1);
	}
}


bool findWord(TrieNode *root, const string &str, int indx) {




	if(str.size() == indx) {

		return root->isEnding;
	}

	if(root -> data.count(str[indx]) == 0) {

		// char not present
		return false;
	}
	else {

		return findWord(root -> data[str[indx]], str, indx+1);
	}
}




int main() {

    #ifndef ONLINE_JUDGE
        freopen("../io/input.txt", "r", stdin);
        freopen("../io/output.txt", "w", stdout);
        auto start = high_resolution_clock::now();
    #endif

    TrieNode *root = new TrieNode();
    insertIntoTrie(root, "Chandu", 0);
    insertIntoTrie(root, "Chandrakant", 0);
  	insertIntoTrie(root, "Chandrak", 0);


   cout<<(findWord(root, "Chandu", 0) ? "Exists" : "Absent")<<endl;


   cout<<(findWord(root, "Chandrakan", 0) ? "Exists" : "Absent")<<endl;
   cout<<(findWord(root, "Chandrakant", 0) ? "Exists" : "Absent")<<endl;




    #ifndef ONLINE_JUDGE
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout<<"\n\nTime :"<<(duration.count()/1000.0)<<" ms" << endl;
        fclose(stdin);
        fclose(stdout);
    #endif


}