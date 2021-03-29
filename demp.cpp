#include <iostream>
using namespace std;
#include<vector>
#include<bits/stdc++.h>
#include<math.h>
#define lli long long int 

int main() 
{

	int x = 0;
	int y = 0;
	for(int i = 1; i < 100; i += 2)
	{
		x++;
		if(x == 3) {
			x = 0;
			cout<<i<<"*\n";
		}
		else
			cout<<i<<"\n";
	}






}