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

void findNumber(int num, int &larget, int &small) {


  while(num) {

    int rem = num % 10;

    if(larget < rem) {

        small = larget;
        larget = rem;
    }
    else if(small < rem){
      small = rem;
    }

    num /= 10;
  }
}

int main() {


  freopen("../io/input.txt", "r", stdin);
  freopen("../io/output.txt", "w", stdout);
  auto start = high_resolution_clock::now();


  int numCustmer;
  cin>>numCustmer;

  vector<int> balance(numCustmer);

  for(int i =0; i< numCustmer; i++) {


    cin>>balance[i];
  }

  int product = 0;
  int sum = 0;


  for(int i = 0; i < numCustmer; i++) {

    for(int j = i+1; j < numCustmer; j++) {

      if(balance[i] * balance[j] < product) {

        product = balance[i] * balance[j];
        sum = balance[i] + balance[j];
      }


    }

  }

  cout<<sum;
	




  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout<<"\n\nTime :"<<(duration.count()/1000.0)<<" ms" << endl;
  fclose(stdin);
  fclose(stdout);


}
