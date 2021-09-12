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

vector<int> stateOfCells (vector<int> cell, int days)
{
    vector<int>  answer;
    // Write your code
    for(int i=0;i<days ;i++)
    {
    if(cell[0]==1)
    answer[0]=0;
    else if(cell[1]==1)
    answer[0]=1;
   
    if(cell[7]==1)
    answer[7]=0;
    else if(cell[6]==1)
    answer[7]=1;
   
    for(int k=0;k<=6;k++)
    {
    if(cell[k-1]==cell[k+1]){
    answer[k]=0;
    }
    else
    {
    answer[k]=cell[k+1];
    }
    }
         cell=answer;
    }

   
    return answer;
}

int main() {

  freopen("../io/input.txt", "r", stdin);
  freopen("../io/output.txt", "w", stdout);
  auto start = high_resolution_clock::now();


  


	vector<int> v1(8);
	vector<int> v2(8);

	for(auto &it : v2) cin>>it;

	int days;
	cin>>days;

	// for(int i = 0; i < days; i++) {

	// 	if(v2[0] == 1)
	// 		v1[0] = 0;
	// 	else if(v2[1] == 1)
	// 		v1[0] = 1;

	// 	if(v2[7] == 1)
	// 		v1[7] = 0;
	// 	else if(v2[6] == 1)
	// 		v1[7] = 1;

		
	// 	for(int k = 1; k <= 6; k++) {


	// 		// if(v2[k] == 1) {

	// 		// 	v1[k] = 0;
	// 		// }
	// 		 if(v2[k-1] == v2[k+1]) {

	// 			v1[k] = 0;
	// 		}
	// 		else {

	// 			v1[k] = v2[k-1] or v2[k+1];
	// 		}
	// 	}
	// 	v2 = v1;

	// 	// for(int i = 0; i <8; i++) cout<<v2[i]<<" ";
	// 	// 	cout<<endl;
	// }








  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout<<"\n\nTime :"<<(duration.count()/1000.0)<<" ms" << endl;
  fclose(stdin);
  fclose(stdout);


}