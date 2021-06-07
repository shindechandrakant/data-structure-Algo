#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define MOD 1000000007
#define vi vector<int>


bool isPalindrome(string s) {

	int start = 0;
	int end = s.size()-1;

	while(start < end) {


		if(s[start] != s[end])
			return false;

		start++;
		end--;
	}



	return true;
}


int main() {
  
  int t;
  cin>>t;
  while(t--)
  {

  	string s;
  	int n;
  	cin>>n>>s;


  	// alice 1st
  	int bob = 0;
  	int alice = 0;

  	// reverese allow->  not a palindrome, and last pass not Reverse

  	bool turn = true;
  	// true -> alice
  	// false -> bob
  	bool lastPass = false;

  	while(true) {

  		int valid = s.find('0');
  		if(valid == -1)
  			break;

  		if(not lastPass and not isPalindrome(s)) {
  			reverse(s.begin(), s.end());
  			lastPass = true;
  		}
  		else {

  			for(int i = 0; i < s.size(); i++) {

  				if(s[i] == '0') {

  					s[i] = '1';
  					if(turn)
  						alice++;
  					else
  						bob++;
  					break;
  				}
  			}
  			lastPass = false;
  		}
  		turn = !turn;
  	}



/*
"ALICE", if Alice will win the game,
"BOB", if Bob will win the game,
"DRAW", if the game ends in a draw.


*/

  	if(alice == bob)
  		cout<<"DRAW\n";
  	else if(alice < bob)
  		cout<<"ALICE\n";
  	else
  		cout<<"BOB\n";


  }
}