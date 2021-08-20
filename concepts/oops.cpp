#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
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





class Parent {

	public:

		void add(string x, string y) {

			cout<<" In ADD sting";
			
		}

};


class Demo: public Parent {

	public:

		void add(int x, int y) {

			cout<<" In ADD int";
		}

		


};


int main() {

    freopen("../io/input.txt", "r", stdin);
    freopen("../io/output.txt", "w", stdout);


	Demo d;

	d.add(3, 4);
	d.add("1.3", "5.4");

	// int s = 0;
	// cout<<typeid(s).name();
	// cout<<endl<<decltype(s);



    fclose(stdin);
    fclose(stdout);

}