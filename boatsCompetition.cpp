
// Problem Link :- https://codeforces.com/contest/1399/problem/C

#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#include<math.h>


int main() {

	int t;
	cin>>t;
	while(t--)
	{

		map<int, int>nums;
		int n;
		cin>>n;
		int x;
		for(int i = 0; i < n; i++) {

			cin>>x;
			nums[x]++;
		}
		if(n == 1)
		{
			cout<<0<<endl;
			continue;
		}
		if(n <= 3) {
			cout<<1<<endl;
			continue;
		}

		map<int, int>ans;
		for(auto it = nums.begin(); it != nums.end(); it++) {
			
			auto temp = it;
			temp++;
			for(auto it2 = temp; it2 != nums.end(); it2++) {

				int minVal = min(it -> second, it2 -> second);
				int val = it -> first + it2 -> first;

				ans[val] += minVal;
			}

		}

		for(auto it : nums) {

			int sum = it.first * 2;
			int teams = it.second / 2;
			if(teams > 0) {

				ans[sum] += teams;

			}
		}

		int maxVal = 0;

		for(auto it : ans) {

			if(maxVal < it.second) {

				maxVal = it.second;
			}
		}

		cout<<maxVal<<endl;












	}

}






