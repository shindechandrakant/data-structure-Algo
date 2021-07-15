#include<iostream>
#include <bits/stdc++.h>
using namespace std;


bool comparator(pair<int , int> s, pair<int , int> f)
{

	if(s.first == f.first)
	{
		return s.second > f.second;
	}

	return s.first < f.first;
}

void update(vector<int> &tree, vector<int> &lis, int str, int end, int tindx, int indx, int val)
{

	if(str == end) {

		lis[indx] = val;
		tree[tindx] = val;
		return;
	}

	int mid = (str + end) / 2;

	if(indx > mid) {
		// right
		update(tree, lis, mid + 1, end, 2 * tindx + 1, indx, val);
	}
	else {
		// left
		update(tree, lis, str, mid, 2 * tindx, indx, val);
	}

	tree[tindx] = max(tree[2 * tindx], tree[2 * tindx + 1]);
}

int query(vector<int> &tree, int start, int end, int tindx, int left, int right)
{

	if( right < start or left > end )	return 0;

	if( start >= left and end <= right )
	{
		return tree[tindx];
	}

	int mid = (start+end)/2;

	int ll = query(tree, start, mid, 2 * tindx, left, right);
	int rl = query(tree, mid + 1, end, 2 * tindx + 1, left, right);

	return max(ll , rl);
}

int main()
{
	int n;
	cin>>n;
	vector<pair<int , int> > arr(n);

	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i].first;
		arr[i].second = i;
	}

	sort(arr.begin(), arr.end(), comparator);
	vector<int>tree(4*n, 0);
	vector<int>lis(n, 0);	//answers

	for(int i = 0; i < n; i++)
	{
		int element = arr[i].first;
		int indx = arr[i].second;
		int res = query(tree, 0, n-1, 1, 0, indx-1);
		update(tree, lis, 0, n - 1, 1, indx, res+1);
	}


	int max_el = -1;


	for (int i = 0; i < n; ++i)
	{
		max_el = max(max_el, lis[i]);
	}

	cout<<max_el;



}


