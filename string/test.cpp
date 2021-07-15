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

int main() {

    freopen("../io/input.txt", "r", stdin);
    freopen("../io/output.txt", "w", stdout);

	string input;
	cin>>input;

	vector<string> indiv;
	string temp;


	for(int i = 0; i < input.size(); i++) {

		if(input[i] == ',') {

			indiv.push_back(temp);
			temp="";

		}
		else {
			temp.push_back(input[i]);
		}
	}

	
	indiv.push_back(temp);

	int n = indiv.size();
	int ans = 0;

	map<string, int> bottles;

	vector<bool> counted(n, false);
	for(int i = 0; i < n; i++) {

		bottles[indiv[i]] = i;
	}


	for(auto curr : bottles) {

		string str = curr.first;

		if(str[1] == 'B') {

			string needCap;
			needCap.push_back(str[0]);
			needCap.push_back('C');

			if(bottles.count(needCap) and bottles[needCap] != -1) {

				int x = bottles[needCap];
				int y = bottles[str];

				if(abs(x-y) <= 3) {
					bottles[needCap] = -1;
					ans++;
				}
			}
		}
	}
	cout<<ans;








    fclose(stdin);
    fclose(stdout);

}