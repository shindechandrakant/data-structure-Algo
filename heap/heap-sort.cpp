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
Problem link -> https://www.geeksforgeeks.org/heap-sort/
*/

void display(vi &arr) {

	for(auto it: arr) {

		cout<<it<<" ";
	}
	cout<<endl;
}



void max_heapify(vi &arr, int indx, int n) {

	if(indx*2 > n)	return;

	int root = indx;
	int left_child = indx*2;
	int right_child = indx*2 + 1;

	if(left_child < n and arr[left_child] > arr[root]) {

		root = left_child;
	}

	if(right_child < n and arr[right_child] > arr[root]) {

		root = right_child;
	}

	if(root != indx) {

		swap(arr[indx], arr[root]);
		max_heapify(arr, root, n);
	}
}


void max_heap_sort(vi &arr, int n) {

	for(int i = n/2; i >= 0; i--) {

		max_heapify(arr, i, n);
	}

	for(int i = n-1; i >= 0; i--) {

		swap(arr[0], arr[i]);
		max_heapify(arr, 0, i);
	}
}

void min_heapify(vi &arr, int indx, int n) {

	int root = indx;
	int left_child= indx*2;
	int right_child = indx*2+1;

	if(left_child < n and arr[left_child] < arr[root]) {

		root = left_child;
	}

	if(right_child < n and arr[right_child] < arr[root]) {

		root = right_child;
	}

	if(indx != root) {

		swap(arr[root], arr[indx]);
		min_heapify(arr, root, n);
	}
}

void min_heap_sort(vi &arr) {

	int n = arr.size();

	for(int i = n/2; i >= 0; i--) {

		min_heapify(arr, i, n);
	}


	for(int i = n-1; i >=0; i--) {

		swap(arr[0], arr[i]);
		min_heapify(arr, 0, i);
	}


}



int main() {

    freopen("../io/input.txt", "r", stdin);
    freopen("../io/output.txt", "w", stdout);

	// int n;
	// cin>>n;
	// vi arr(n);

	// for(int i = 0; i < n; i++) {

	// 	cin>>arr[i];
	// }


	// min_heap_sort(arr);
	// display(arr);
	// // min_heap_sort(arr);
	// // display(arr);
	// max_heap_sort(arr, n);
	// display(arr);



    fclose(stdin);
    fclose(stdout);
}

