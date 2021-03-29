#include<bits/stdc++.h>
#include<iostream>
#include <math.h>
#define lli long long int
using namespace std;

int main()
{

	lli t;
	cin>>t;
	while(t--)
	{
		lli h, w, n;
		cin>>w>>h>>n;

		if(n == 1) {
			cout<<"YES"<<endl;
			continue;
		}
		else if(h % 2 != 0 and w % 2 != 0) {

			cout<<"NO"<<endl;
			continue;
		}

		queue<pair<int, int> > q;
		q.push({ w, h});
		int pieces = 0;

		while(not q.empty()) {

			if(pieces >= n) {
				break;
			}
			auto it = q.front();
			q.pop();

			if(it.first % 2 != 0 and it.second % 2 != 0)
				pieces++;

			if(it.first % 2 == 0) {

				q.push({ it.first / 2, it.second });
				q.push({ it.first / 2, it.second });

			} else if(it.second % 2 == 0) {

				q.push({ it.first, it.second / 2 });
				q.push({ it.first, it.second / 2 });
				
			}
			

		}

		if(pieces >= n) {
			cout<<"YES"<<endl;
			continue;
		}
		else {
			cout<<"NO"<<endl;
			continue;
		}


	}


}








