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

int answer = 0;
void formNew(vector<string> &sentence, map<string, int> &anagrams, int indx) {


	if(indx == sentence.size()) {

		answer++;
	}

	if(indx > sentence.size()) {

		return;
	}

	if(anagrams.count(sentence[indx]) == 0 or anagrams[sentence[indx]] <= 1) {

		return;
	}

	for(int i = indx; i < sentence.size(); i++) {

		formNew(sentence, anagrams, i);
	}


}




int count(vector<string> &words, vector<string> sentence) {

	map<string, int> anagrams;
	map<string, int> sen;

	vector<string> orignal = sentence;

	for(int i = 0; i < words.size(); i++) {

		sort(words[i].begin(), words[i].end());
		anagrams[words[i]]++;
	}

	for(int i = 0; i < sentence.size(); i++) {

		sort(sentence[i].begin(), sentence[i].end());
		sen[sentence[i]]++;
	}


	return 0;

}


int main() {

  freopen("../io/input.txt", "r", stdin);
  freopen("../io/output.txt", "w", stdout);
  auto start = high_resolution_clock::now();



  // int n;
  // cin>>n;

  // vector<string> words(n);

  // for(int i = 0; i < n; i++) {

  // 	cin>>words[i];
  // }


  // string sentence;

  char c = '9';
  cout<<c-'0';














  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout<<"\n\nTime :"<<(duration.count()/1000.0)<<" ms" << endl;
  fclose(stdin);
  fclose(stdout);


}