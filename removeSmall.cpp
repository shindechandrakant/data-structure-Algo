// Problem Link https://codeforces.com/contest/1399/problem/A

#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#include<math.h>

int main() {

	int t;
	cin>>t;

	while(t--)
	{
		int n;
		cin>>n;
		vector<int>v(n);
		for(int i= 0; i < n; i++) 	cin>>v[i];

		stack<int>stk;
		sort(v.begin(), v.end());
		for(int i = 0; i < n; i++) {

			if(stk.empty()) {
				stk.push(v[i]);
				continue;
			}

			int top = stk.top();
			int diff = abs(v[i] - top);

			if(diff <= 1) {

				if(top < v[i]) {

					stk.pop();

					while(not stk.empty() and abs(stk.top() - v[i]) <= 1 and stk.top() < v[i]) {
						stk.pop();
					}

					if(stk.empty() or (abs(stk.top() - v[i]) > 1))
						stk.push(v[i]);
				}
			}
			else {
				stk.push(v[i]);
			}
		}


		if(stk.size() == 1)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;




	}
}




