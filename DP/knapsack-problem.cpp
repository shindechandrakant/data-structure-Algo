#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define MOD 1000000007
#define vi vector<int>

void displayFraction(vector<pair<float, int> > &profitPerKg) {

	for(auto it : profitPerKg)
		cout<<it.first<<" "<<it.second<<endl;
	cout<<endl;

}
void displayDP(vector<vi> &dp) {

	for(auto it : dp) {

		for(auto i : it) {
			cout<<i<<" ";
		}
		cout<<endl;
	}
}

// Using Fraction
// int greedyMethod(vi &weight, vi &space, int capacity)
// {
// 	int n = weight.size();

// 	vector<pair<float, int> > profitPerKg (n);

// 	for(int i = 0; i < n; i++) {

// 		float pft = ((float)weight[i])/space[i];

// 		profitPerKg[i] = {pft, i};
// 	}	


// 	sort(profitPerKg.begin(), profitPerKg.end(), greater<pair<float, int>>());

// 	display(profitPerKg);
// 	return 0;
// }


// 0/1 Knapsack Problem
// bounded Duplicacy not allowed
// time complexity will be O(n*capacity)
// space complexity will be O(n*capacity)
int dynamicMethod(vi &weight, vi &value, int capacity) {


	int n = weight.size();

	vector<vi>dp(n+1, vi(capacity+1, 0));


	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= capacity; j++)
		{

			if(weight[i-1] > j) {
				dp[i][j] = dp[i-1][j];
			}
			else {

				dp[i][j] = max(dp[i-1][j], dp[i-1][j - weight[i-1]] + value[i-1]);
			}
		}
	}

	displayDP(dp);

	return dp[n][capacity];
}

// 0/1 Knapsack Problem
// Unbounded Duplicacy allowed
int dynamicMethodUB(vi &weight, vi &value, int capacity) {

	int *arr = new int[capacity+1] { 0 };

	for(int curCap = 1; curCap <= capacity; curCap++) {

		int maxV = 0;

		for(int i = 0; i < weight.size(); i++) {

			if(curCap >= weight[i]) {

				int lastPos = curCap - weight[i];
				int poss = arr[lastPos] + value[i];
				maxV = max(maxV, poss);
			}
		}
		arr[curCap] = maxV;
			for(int i = 0; i <= capacity; i++)
				cout<<arr[i]<<" ";

			cout<<endl;
	}




	return arr[capacity];


}



int main() {

	int n, capacity;
	cin>>n>>capacity;
	vi weight(n);
	vi value(n);
	
	for(int i = 0; i < n; ++i) cin>>weight[i];
	for(int i = 0; i < n; ++i) cin>>value[i];
	// greedyMethod(weight, space, capacity);

	cout<<dynamicMethod(weight, value, capacity)<<endl<<endl;
	cout<<dynamicMethodUB(weight, value, capacity)<<endl<<endl;

}