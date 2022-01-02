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

void tableOfContent(vector<string> &description) {

	vector<vector<string> > ttt;
	int n = description.size();
	vector<string> temp;
	string str;

	cout<<n<<endl;

	for(int i = 0; i < n; i++) {

		str = description[i];

		cout<<i<<"- "<<str.size()<<endl;
		if(str.size() -= 0) {

			cout<<"inside"<<" "<<i<<endl;
			continue;
		}
		else if(str[0] == '#') {

			if(str[1] == '#') {
				// SubTopic
				temp.push_back(str.substr(3));
			}
			else {
				// Heading
				ttt.push_back(temp);
				temp.clear();
				temp.push_back(str.substr(2));
			}
		}
		// cout<<str.size()<<endl;
	}
	cout<<"here";
	// ttt.push_back(temp);
	vector<string> answer;
	cout<<"\ntt "<<ttt.size();


	for(int i = 0; i < ttt.size(); i++) {

		string current = to_string(i+1) + ". " + ttt[i][0];
		answer.push_back(current);
		cout<<"H: "<<current<<endl;

		for(int j = 1; j < ttt[i].size(); j++) {

			string temp = to_string(i+1) + "." + to_string(j) + ". " + ttt[i][j];
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
  cin>>n;

  vector<string> vect(n);

  for(int i = 0; i < n; i++) {

  	string str;

  	getline(cin, str, '\n');
  	// cout<<i<<" "<<str<<endl;
  	vect[i] = str;
  	// cout<<i<<" "<<vect.size()<<"-> "<<vect[i]<<endl;
  }

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