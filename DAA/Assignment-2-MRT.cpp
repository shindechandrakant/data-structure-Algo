#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
#define vi vector<ll>
#define pi pair<ll, ll>
#define ump(dataTyp1, dataTyp2) unordered_map<(dataTyp1), (dataTyp2)>
#define mp(dataTyp1, dataTyp2) map<(dataTyp1), (dataTyp2)>
#define v2d(name, m, n, inti) vector<vi>(name)(m, vi(n, inti))
#define MOD 1000000007

// problem statement ->  optimal storage on tapes problem
// Problem link -> 

void displayTapes(vi &tapes) {

	for(auto it : tapes)
		cout<<it<<" ";
}

float calculateMRT(vi &tapes) {

	int sum = tapes[0];
	for(int i = 1; i < tapes.size(); i++) {

		sum += (sum + tapes[i]);
	}
	return (float)sum/tapes.size();
}


float minMRT = 999999;
vi sequence;

void print(vi &tapes) {

	displayTapes(tapes);
	cout<<"Sequence has MRT : ";
	float mrt = calculateMRT(tapes); 
	cout<<mrt;

	if(mrt < minMRT) {

		minMRT = mrt;
		sequence = tapes;
	}
	cout<<endl;
}

void permutations(vi &tapes, int curr_indx) {


	if(curr_indx == tapes.size()-1) {

		print(tapes);
		return;
	}

	unordered_set<int> st;
	for(int i = curr_indx; i < tapes.size(); i++) {

		// avoid duplicates
		if(st.count(tapes[i]) != 0)
			continue;

		st.insert(tapes[i]);
		swap(tapes[i], tapes[curr_indx]);
		permutations(tapes, curr_indx+1);
		swap(tapes[i], tapes[curr_indx]);
	}
}

int main() {

  	freopen("../io/input.txt", "r", stdin);
  	freopen("../io/output.txt", "w", stdout);

	int n;
	cin>>n;
	vi tapes(n);
	for(int i = 0; i < n; i++) {

		cin>>tapes[i];
	}
	// sort(tapes.begin(), tape.end());

	permutations(tapes, 0); 

	cout<<"------------\n";
	cout<<"Ans : \n";
	print(sequence);

	fclose(stdin);
	fclose(stdout);

}

