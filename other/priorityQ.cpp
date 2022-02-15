#include<bits/stdc++.h>
#include<iostream>
using namespace std;

struct person {
	int height; 
	int age;
};

struct comparator {

	bool operator()(person const &p1, person const &p2) {

		if(p1.age == p2.age) {

			return p1.height < p2.height;
		}
		
		return p1.age < p2.age;
	}
};

int main()
{

	priority_queue<person, vector<person>, comparator>q;

	for(int i = 1; i <= 4; i++) {

		person p;
		cin>>p.height;
		cin>>p.age;
		q.emplace(p);
	}

	while(not q.empty()) {

		person p = q.top();
		q.pop();
		cout<<p.age<<" "<<p.height<<endl;
	}


}





