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

4 3
9 7 50
22 7 20
33 7 50
22 7 30
*/

vector<string> findOne(vector<string> &logs, int threshold) {


	map<string, int> Ids;
	for(int i = 0; i < logs.size(); i++) {

		string current = logs[i];
		int temp = 0;
		string val;
		int indx = 0;

		vector<string> track;

		while(temp < 2) {

			if(current[indx] == ' ') {

				track.push_back(val);
				val = "";
				temp++;
				indx++;
				continue;
			}
			val.push_back(current[indx]);
			indx++;
		}
		if(track[1] == track[0]) {

			Ids[track[1]]++;
		}
		else {

			Ids[track[1]]++;
			Ids[track[0]]++;
		}
	}

	vector<string> answer;
	for(auto it : Ids) {

		if(it.second >= threshold) {

			answer.push_back(stoi(it.first));
		}
	}

	
	sort(answer.begin(), answer.end());
	// same for to _String


	return answer;
}




int main() {

  freopen("../io/input.txt", "r", stdin);
  freopen("../io/output.txt", "w", stdout);
  auto start = high_resolution_clock::now();

	int n, limit;
	cin>>n>>limit;
	vector<string> logs;

	for(int i = 0; i < n; i++) {

		string id, send, amt;
		cin>>id>>send>>amt;

		string curr;
		curr = id + " " + send + " " + amt;
		logs.push_back(curr);
	}



	logs = findOne(logs, limit);


	for(auto it : logs) {

		cout<<it<< " ";
	}











  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout<<"\n\nTime :"<<(duration.count()/1000.0)<<" ms" << endl;
  fclose(stdin);
  fclose(stdout);


}
