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

int main() {

  freopen("../io/input.txt", "r", stdin);
  freopen("../io/output.txt", "w", stdout);
  auto start = high_resolution_clock::now();


  

	// string str;
	// cin>>str;
	// transform(str.begin(), str.end(), str.begin(), ::tolower);

	// int answer = 0;

	// for(int i = 0; i < str.size(); i++) {

	// 	int indx = str[i] - 97;

	// 	if(indx == i) {

	// 		answer++;
	// 	}
	// }
	// cout<<answer;


  	int n, m;
  	cin>>n>>m;
  	vector<int> bagA(n);
  	vector<int> bagB(m);

  	int even_count_A = 0;
  	int even_count_B = 0;

  	for(int i = 0; i < n; i++) {

  		cin>>bagA[i];
  		if(bagA[i] % 2 == 0) {
  			even_count_A++;
  		}
  	}

  	for(int i = 0; i < m; i++) {

  		cin>>bagB[i];
  		if(bagB[i] % 2 == 0) {
  			even_count_B++;
  		}
  	}

  	int answer = m * even_count_A;
  	answer += (n- even_count_A)*even_count_B;
  	cout<<answer;







  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout<<"\n\nTime :"<<(duration.count()/1000.0)<<" ms" << endl;
  fclose(stdin);
  fclose(stdout);


}