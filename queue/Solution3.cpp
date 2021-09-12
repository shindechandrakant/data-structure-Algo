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

bool isInterleaved(char s1[], char s2[], char s3[], int s1_len, int s2_len)
{


	int s3_len = s1_len + s2_len;

	int i = 0;
	if(s1[0] == s3[0]) {

		for(int count = 0, count2 = 0; i < s3_len-1; count++, count2++) {

			if(count > s1_len) {


				if(s2[count2] != s3[i]) {

					return false;
				}

				i++;
				continue;
			}
			else if(count2 > s2_len) {

				if(s1[count] != s3[i]) {

					return false;
				}
				i++;
				continue;
			}
			else if (s1[count] != s3[i] || s2[count2] != s3[i+1]) {

				return false;
			}

			i += 2;
		}
	}
	else {



		// second array is 1st then 1st
		for(int count = 0, count2 = 0; s3[i] != '\0'; count++, count2++) {


			if(count > s1_len) {

				if(s2[count2] != s3[i]) {

					return false;
				}

				i++;
				continue;
			}
			else if(count2 > s2_len) {

				if(s1[count] != s3[i]) {

					return false;
				}

				i++;
				continue;

			}
			else if (s3[i] != s2[count2] || s3[i+1] != s1[count]) {

				cout<<s3[i] <<" "<<s2[count2]<<endl;
				cout<<s3[i+1] <<" "<<s1[count]<<endl;


				return false;
			}

			i += 2;
		}
	}
	return true;

}




int main() {

  freopen("../io/input.txt", "r", stdin);
  freopen("../io/output.txt", "w", stdout);
  auto start = high_resolution_clock::now();


  
  int t  = 1;

  while(t--) {


	int n, n1;
	cin>>n>>n1;

	char s1[n];
	char s2[n1];
	char s3[n+n1];

	for(int i = 0; i < n; i++) {

		cin>>s1[i];
	}

	for(int i = 0; i < n1; i++) {

		cin>>s2[i];
	}

	for(int i = 0; i < n+n1; i++) {

		cin>>s3[i];
	}


	cout<<isInterleaved(s1, s2, s3, n, n1)<<endl;



  }














  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout<<"\n\nTime :"<<(duration.count()/1000.0)<<" ms" << endl;
  fclose(stdin);
  fclose(stdout);


}