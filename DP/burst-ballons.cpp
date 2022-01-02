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
Problem link -> https://leetcode.com/problems/burst-balloons/
*/


void printVector(vector<int> &vect) {


	for(int i = 0; i < vect.size(); i++)
		cout<<vect[i];

	cout<<endl;
}

void burstBallons(vector<int> &nums, int current, int &answer) {


	if(nums.size() == 1) {

		answer = max(current + nums[0], answer) ;
		return;
	}

	for(int i = 0; i < nums.size(); i++) {

		int curr = nums[i];
		int mult = nums[i];
		
		mult *= ( i == 0 ? 1 : nums[i-1]);
		mult *= (i == nums.size()-1 ? 1 : nums[i+1]);

		nums.erase(nums.begin()+i);
		burstBallons(nums, current+mult, answer);
		nums.insert(nums.begin()+i, curr);		
	}
}


int dpCalls = 0;

int burstBallonsDP1(vector<int> &nums, map<vector<int>, int> &dp) {

	if(dp.count(nums) != 0)
		return dp[nums];

	if(nums.size() == 1) {

		return nums[0];
	}
	dpCalls++;

	int maX = 0;

	for(int i = 0; i < nums.size(); i++) {

		int curr = nums[i];
		int mult = nums[i];
		
		mult *= ( i == 0 ? 1 : nums[i-1]);
		mult *= (i == nums.size()-1 ? 1 : nums[i+1]);

		nums.erase(nums.begin()+i);
		// maX = max(maX, burstBallonsDP(nums, dp)+mult);
		nums.insert(nums.begin()+i, curr);		
	}



	return dp[nums] = maX;
}



int burstBallonsDP(vector<int> &nums, map<vector<int>, int> &dp) {

	if(dp.count(nums) != 0)
		return dp[nums];

	if(nums.size() == 1) {

		dp[nums] = nums[0];
		return nums[0];
	}
	dpCalls++;

	int maX = 0;

	for(int i = 0; i < nums.size(); i++) {

		int curr = nums[i];
		int mult = nums[i];
		
		mult *= ( i == 0 ? 1 : nums[i-1]);
		mult *= (i == nums.size()-1 ? 1 : nums[i+1]);

		nums.erase(nums.begin()+i);
		maX = max(maX, burstBallonsDP(nums, dp)+mult);
		nums.insert(nums.begin()+i, curr);		
	}



	return dp[nums] = maX;
}


int main() {

    #ifndef ONLINE_JUDGE
        freopen("../io/input.txt", "r", stdin);
        freopen("../io/output.txt", "w", stdout);
        auto start = high_resolution_clock::now();
    #endif

  
     int t = 1;
     while(t--) {
     	int ans = 0;

	 	int n;
	 	cin>>n;
	 	vector<int> vect(n);

	 	for(int i = 0; i < n; i++)
	 		cin>>vect[i];

	 	// burstBallons(vect, 0, ans);
	 	// cout<<ans<<" ";

	 	map<vector<int>, int> mp;
	 	cout<<burstBallonsDP(vect, mp)<<endl;
	 	cout<<"DP CALLS : "<<dpCalls<<endl;


     }

    #ifndef ONLINE_JUDGE
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout<<"\n\nTime :"<<(duration.count()/1000.0)<<" ms" << endl;
        fclose(stdin);
        fclose(stdout);
    #endif


}