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

vector<int> cards(vector<int> collection, int d) {

	int n = collection.size();
	vector<int> answer;

	sort(collection.begin(), collection.end());
	int current = 1;
	int indx = 0;
	while(true) {

		if(d-current < 0) {

			break;
		}

		if(collection[indx] == current) {

			indx++;
			current++;
			continue;
		}
		else {

			if(d-current >= 0) {

				answer.push_back(current);
				d -= current;
			}
		}
		current++;
	}



	return answer;
}

int main() {

  freopen("../io/input.txt", "r", stdin);
  freopen("../io/output.txt", "w", stdout);
  auto start = high_resolution_clock::now();


  int n;
  cin>>n;

  vector<int> collection(n);
  for(int i = 0; i < n; i++) {

  	cin>>collection[i];
  }

  int d;
  cin>>d;


  	collection = cards(collection, d);





	for(auto it : collection) {

		cout<<it<< " ";
	}










  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout<<"\n\nTime :"<<(duration.count()/1000.0)<<" ms" << endl;
  fclose(stdin);
  fclose(stdout);


}