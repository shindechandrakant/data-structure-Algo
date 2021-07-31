// new one
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
void buildSegmentTree(int *arr, int *segmetTree, int start, int end, int level) {


	if(start == end) {

		segmetTree[level] = arr[start];
		return;
	}

	int mid = (start + end) /2;

	buildSegmentTree(*arr, *segmetTree, start, mid, 2*level);
	buildSegmentTree(*arr, *segmetTree, mid+1, end, 2*level+1);

	segmetTree[level] = segmetTree[2*level] + segmetTree[2*level+1];
}

void updateSegmentTree(int *arr, int *segmetTree, int start, int end, 
	int updateIDX, int updtedVal, int level) 
{
	if(start == end) {

		arr[updateIDX] = updtedVal;
		segmetTree[level] = updtedVal;
		return;
	}

	int mid = (start + end) / 2;

	if(mid > updateIDX) {

		updateSegmentTree(arr, segmetTree, start, mid, updateIDX, updtedVal, 2*level);
	}
	else {
		updateSegmentTree(arr, segmetTree, mid+1, end, updateIDX, updtedVal, 2*level+1);
	}
	segmetTree[level] = segmetTree[level*2] + segmetTree[2*level+1];

}


int segmetTreeQuery(int *tree, int start, int end, int level, int left, int right) {

	if(start > right or end < left) {
		//complete outside
		return 0;
	}

	if(start >= left and end <= right) {

		return tree[level]; 
		//complete inside
	}

	// partial inside
	int mid = (start+end)/2;
	int ans1 = segmetTreeQuery(tree, start, mid, level*2, left, right);
	int ans2 = segmetTreeQuery(tree, mid+1, end, level*2+1, left, right);

	return ans1 + ans2;
}



int main() {

    freopen("../io/input.txt", "r", stdin);
    freopen("../io/output.txt", "w", stdout);


	cout<<"I'm Running";






    fclose(stdin);
    fclose(stdout);

}