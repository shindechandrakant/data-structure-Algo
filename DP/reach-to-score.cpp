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

void display(long long int arr[], int n) {

	for(int i = 0; i <= n; i++)
		cout<<arr[i]<<" ";

	cout<<endl;
}


long long int count(long long int n) {

	long long int table[n+1],i;
	memset(table, 0, sizeof(table));
	table[0] = 1;                 
	// If 0 sum is required number of ways is 1.


    
    for (i = 3; i <= n; i++) 
    table[i] += table[i - 3]; 
      display(table, n);
    for (i = 5; i <= n; i++) 
    table[i] += table[i - 5]; 
      display(table, n);
    for (i = 10; i <= n; i++) 
    table[i] += table[i - 10]; 
      display(table, n);

	return table[n];
}



int incr = 0;
void numberofWays(int n, string ssf) {


	if( n < 0) {

		return;
	}



	if(n == 0) {

		incr++;
		return;
	}

	numberofWays(n-3, ssf + to_string(3) + ",");
	numberofWays(n-5, ssf + to_string(5) + ",");
	numberofWays(n-10, ssf + to_string(10) + ",");
}

map<int, int> counter;

int countNoWays(int n) {

		if( n < 0) {
		return 0;
	}

	if(counter.count(n) != 0) {

		return counter[n];
	}

	if(n == 0) {

		return 1;
	}

	incr++;

	int three = countNoWays(n-3);
	int five = countNoWays(n-5);
	int ten = countNoWays(n-10);
	return counter[n] = three + five + ten;
}


int main() {

  freopen("../io/input.txt", "r", stdin);
  freopen("../io/output.txt", "w", stdout);
  auto start = high_resolution_clock::now();


  
  int t;
  cin>>t;

  while(t--) {

  	incr = 0;
  	int num;
  	cin>>num;
	 	// numberofWays(num, "");

	 	cout<<countNoWays(num)<<" "<<incr<<endl;
  }















  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout<<"\n\nTime :"<<(duration.count()/1000.0)<<" ms" << endl;
  fclose(stdin);
  fclose(stdout);


}







