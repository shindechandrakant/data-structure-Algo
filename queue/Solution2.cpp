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


void findPairs(int arr[][2], int len) {


	for(int i = 0; i < len; i++) {


		if(arr[i][0] == INT_MIN) {

			continue;
		}
		bool flag = false;
		for(int j = i+1; j < len; j++) {


			if(flag && arr[i][0] == arr[j][1] && arr[i][1] == arr[j][0]) {

				arr[j][0] = INT_MIN;
				arr[j][1] = INT_MIN;
			}
			else if(arr[i][0] == arr[j][1] && arr[i][1] == arr[j][0]) {


				cout<<"("<<arr[i][0]<<", "<<arr[i][1]<<")\n";
				arr[j][0] = INT_MIN;
				arr[j][1] = INT_MIN;
				flag = true;
			}
		}
	}
}






int main() {

  freopen("../io/input.txt", "r", stdin);
  freopen("../io/output.txt", "w", stdout);
  auto start = high_resolution_clock::now();


  

	int n;
	cin>>n;
	int arr[n][2];

	for(int i = 0; i < n; i++) {

		cin>>arr[i][0]>>arr[i][1];
	}



	findPairs(arr, n);











  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout<<"\n\nTime :"<<(duration.count()/1000.0)<<" ms" << endl;
  fclose(stdin);
  fclose(stdout);


}