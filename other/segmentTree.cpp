#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void printArray(int *arr, int n) {

	cout<<endl;
	for(int i = 0; i < n; i++) {

		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void buildSegmentTree(int *tree, int *arr, int start, int end, int level) {

	if(start == end) {

		tree[level] = arr[start];
		return;
	}

	int mid = (start + end) / 2;

	buildSegmentTree(tree, arr, start, mid, 2 * level);
	buildSegmentTree(tree, arr, mid + 1, end, 2 * level + 1);

	tree[level] = tree[level*2] + tree[2*level+1];
}

void updateSegmentTree(int *tree, int *arr, int start, int end, int level, int indxUpdat, int updtedVal)
{

	if(start == end) {

		arr[indxUpdat] = updtedVal;
		tree[level] = updtedVal;
		return;
	}

	int mid = (start + end) / 2;
	if(mid >= indxUpdat)
		updateSegmentTree(tree, arr, start, mid, 2 * level, indxUpdat, updtedVal);
	else
		updateSegmentTree(tree, arr, mid+1, end, 2 * level + 1, indxUpdat, updtedVal);

	tree[level] = tree[2*level] + tree[2*level + 1];
}

int query(int *tree, int start, int end, int level, int left, int right)
{
	if(start > right or end < left) {
		// Completely Outside
		return 0;
	}
	if(start >= left and end <= right) {
		return tree[level];
	}

	int mid = (start + end) / 2;
	int lq = query(tree, start, mid, 2 * level, left, right);
	int rq = query(tree, mid + 1, end, 2 * level + 1, left, right);
	return lq + rq;

}

int main() {

	int n;
	cin>>n;
	int *arr = new int[n] { 0 };
	int *tree = new int[4*n] { 0 };

	for(int i = 0; i < n; i++) {

		cin>>arr[i];
	}

	printArray(arr, n);

	int start = 0;
	int end = n - 1;
	int level = 1;
	buildSegmentTree(tree, arr, start, end, level);

	printArray(tree, 4*n);

	cout<<"-----------\n";

	int queries;
	cin>>queries;

	while(queries--) {

		int t;
		cin>>t;

		if(t == 1) {

			int left, right;
			cin>>left>>right;
			cout<<query(tree, 0, n-1, 1, left, right)<<" ";
			continue;
		}
		int x, y;
		cin>>x>>y;
		updateSegmentTree(tree, arr, 0, n-1, 1, x, y);
	}

	printArray(tree, 4*n);
	printArray(arr, n);


}







