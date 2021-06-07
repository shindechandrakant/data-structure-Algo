#include<bits/stdc++.h>
#include<iostream>
#include <math.h>
using namespace std;
#define vi vector<int>

int multiply(vi &ans, int number, int count);

void powerOfNumber(int number, int power) {

	vi ans(1000, 0);
	ans[0] = 1;
	int count = 1;

	for(int i = 1; i <= power; i++)
	{
		count = multiply(ans, number, count);
	}
	cout<<number<<"^"<<power<<" "<<count<<endl;

	int answer = 0;
	for(int i = count - 1; i >= 0; i--)
	{
		cout<<ans[i];
		answer += ans[i];
	};

	cout<<endl<<endl<<answer;

}

int multiply(vi &ans, int number, int count) {


	int carry = 0;
	for(int i  = 0; i < count; i++) {

		int num = (ans[i] * number) + carry;
		carry = num / 10;
		num = num % 10;
		ans[i] = num;
	}

	while(carry) {

		int temp = ans[count] + carry;
		ans[count] = temp % 10;
		carry = carry / 10;
		count++;
	}
	return count;
}

int main()
{

	int  num;
	int power;



		cin>>num;
		cin>>power;

		powerOfNumber(num, power);
		cout<<endl<<endl;

}








