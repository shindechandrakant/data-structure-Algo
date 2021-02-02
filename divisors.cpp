#include<bits/stdc++.h>
#include<iostream>
#include <math.h>
using namespace std;

void printVector(vector<int> v)
{
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); ++i) cout<<v[i]<<" ";
	cout<<endl;
}

void Divisors1(int n)
{
	vector<int>v;
	for (int i = 1; i <= sqrt(n); ++i)
	{
		if(n % i == 0)
		{
			if(n / i != i) {
				v.push_back(n/i);
			}
			v.push_back(i);
		}
	}
	// cout<<"Found in "<<(int)sqrt(n)<<" iterations\n";
	cout<<"Total Divisors1 : "<<v.size()<<endl;
	// cout<<"Divisors : ";
	// printVector(v);
}

// Using prime factorization
void Divisors2(int n)
{
	int x = sqrt(n);
	map<int, int> map;
	while(n >= 1)
	{
		bool isPrime = true;
		for(int i = 2; i <= x; i++)
		{
			if(n % i == 0)
			{
				map[i]++;
				n /= i;
				isPrime = false;
				break;
			}
		}
		if(isPrime)
		{
			map[n]++;
			break;
		}
	}
	int divisors = 1;
	int sumDivs = 1;
	
	for(auto it : map)
	{
		divisors *= (it.second + 1);
		int num = pow(it.first, it.second+1) - 1;
        int deno = it.first - 1;
        cout<<num<<" "<<deno<<endl;
        sumDivs *= (num / deno);
	}
	cout<<endl;
	cout<<"Total Divisors2 : "<<divisors<<endl;
	cout<<"Divisors Sum : "<<sumDivs<<endl;
}








int main()
{
	int n;
	cin>>n;

	Divisors1(n);
	Divisors2(n);
	// cout<<endl<<endl<<pow(5, 3);


}

