#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#include<math.h>
int rob(int indx, vector<int> &house) {

	if(indx == 0)	return house[0];
	else if(indx == 1) max(house[0], house[1]);
	return max(rob(i-2, house) + house[i],rob(i-2, house));
}

int main() {
	
	cout<<"Hello house";
	rob(n, house);

}