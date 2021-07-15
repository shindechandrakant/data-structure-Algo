#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void buidTree(int *arr, int *segTree, int s, int e, int tindx)
{

	// base case
	if(s == e) {
		segTree[tindx] = arr[s];
		return;
	}

	int mid = (s+e)/2;
	buidTree(arr, segTree, s, mid, 2 * tindx); // left tree
	buidTree(arr, segTree, mid + 1, e, 2 * tindx + 1); // right tree

	// self work
	segTree[tindx] = segTree[2*tindx] + segTree[2 * tindx + 1];
}


void update(int *arr, int *segTree, int s, int e, int tindx, int sindx, int sval)
{

	// base case
	if(s == e)
	{
		arr[sindx] = sval;
		segTree[tindx] = sval;
		return;
	}

	int mid = (s+e) / 2;
	if(sindx > mid) {
		update(arr, segTree, mid+1, e, tindx * 2 + 1, sindx, sval);
	}
	else {
		update(arr, segTree, s, mid, tindx * 2, sindx, sval);
	}

	segTree[tindx] = segTree[2*tindx] + segTree[2 * tindx + 1];
}

int query(int *segTree, int s, int e, int tindx, int left, int right)
{

	if(s > right or e < left)
	{
		// complete outside range
		return 0;
	}

	if(s >= left and e <= right) {
		// complete inside
		return segTree[tindx];
	}

	int mid = (s+e) / 2;
	int a1 = query(segTree, s, mid, 2 * tindx, left, right);
	int a2 = query(segTree, mid+1, e, 2 * tindx + 1, left, right);

	return a1 + a2;
	
}

int main()
{
	int n;
	cin>>n;

	int *arr = new int[n];
	int *segTree = new int[4*n] { 0 };

	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}

	buidTree(arr, segTree, 0, n-1, 1);


	for (int i = 0; i < 4 * n; ++i)
	{
		cout<<segTree[i]<<" ";
	}

	cout<<endl<<endl;

	int q;
	cin>>q;

	while(q--)
	{

		int type;
		cin>>type;

		if(type == 1)
		{
			// find val
			
			int l, r;
			cin>>l>>r;

			cout<<query(segTree, 0, n -1, 1, l ,r)<<endl;
		}
		else
		{
			// update
			// update(int *arr, int *segTree, int s,
			// int e, int tindx, int sindx, int sval)
			int indx,val;
			cin>>indx>>val;
			update(arr, segTree, 0, n-1, 1, indx, val);
		}
	}

	return 0;
}
