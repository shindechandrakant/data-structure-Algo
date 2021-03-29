#include<bits/stdc++.h>
#include<iostream>
#include <math.h>
using namespace std;


// fibonacchi sequence pattern using recursion
void fibonacchi_sequence_print(int a, int b, int x) {

	if(x == 0) return;
	cout<<a<<" ";
	fibonacchi_sequence_print(b, a+b, x-1);
}

// fibonacchi sequence pattern using loops
void fibonacchi_sequence_print_loops(int n) {

	int start = 0;
	int next = 1;

	while(n--)
	{
		cout<<start<<" ";
		int temp = start;
		start = next;
		next = next + temp;
	}
}

// Recursion
int ndp = 0;
int nth_fibonacchi_number(int a) {

	if(a < 0) return 0;
	if(a == 0 or a == 1) return a;
	ndp++;
	int s1 = nth_fibonacchi_number(a - 1);
	int s2 = nth_fibonacchi_number(a - 2);
	return s1 + s2;
}


// nth fibonacchi number using Dynamic Programing
int dp = 0;
int nth_fibonacchi_number_DP(int a, unordered_map<int, int> &sequence) {

	if(sequence.count(a) != 0) { return sequence[a]; } 

	if(a < 0) return 0;
	if(a == 0 or a == 1) return a;
	dp++;
	int s1 = nth_fibonacchi_number_DP(a - 1, sequence);
	sequence[a-1] = s1;
	int s2 = nth_fibonacchi_number_DP(a - 2, sequence);
	sequence[a-2] = s2;
	return s1 + s2;
}




int main()
{
	int x;
	cin>>x;
	fibonacchi_sequence_print(0, 1, x);
	cout<<endl;
	fibonacchi_sequence_print_loops(x);
	unordered_map<int, int>sequence;
	cout<<endl<<nth_fibonacchi_number(x-1);

	cout<<endl<<nth_fibonacchi_number_DP(x-1, sequence);
	cout<<endl<<endl<<"Non-DP : "<<ndp;
	cout<<endl<<"DP : "<<dp;
}









