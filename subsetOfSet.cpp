#include<iostream>
using namespace std;
#include <unordered_set>
void printSubset(int *arr,int indx, int size, string osf)
{
	if(indx == size) {

		cout<<"[ "<<osf<<"] \n";
		return;
	}
	printSubset(arr, indx+1, size, osf + to_string(arr[indx]) + " ");
	printSubset(arr, indx+1, size, osf);
}

// Wrong
void combinationsOfString(string os, string s, int indx, bool change = false) {

	if(os == s ) return;

	if(!change)
		cout<<s<<endl;

	if(indx == 0) {

		combinationsOfString(os, s, os.size()-1, true);
	}
	else {

		char c = s[indx];
		s[indx] = s[indx-1];
		s[indx -1 ] = c;
		combinationsOfString(os, s, indx-1);
	}

	// cout<<"-"<<indx<<"-\n";

}



void permutation(string str, string per)
{

	if(str.size() == 0)
	{
		cout<<per<<endl;
		return;
	}

	unordered_set<char> set;
	for(int i = 0; i < str.size(); i++)
	{
		char c = str[i];
		if(set.count(c) == 0)
		{

			string res = str.substr(0, i) + str.substr(i+1);
			permutation(res, per + c);
			set.insert(c);
		}
	}

}



int main() {
	
	// int n;
	// cin>>n;
	// int *arr = new int[n];
	// int x;

	// for(int i = 0; i < n; i++)
	// {
	// 	cin>>arr[i];
	// }

	// printSubset(arr, 0, n, "");

	string s;
	cin>>s;
	// string os = s;
	// int indx = s.size() -1;
	// char c = s[indx];
	// s[indx] = s[indx-1];
	// s[indx -1] = c;
	// cout<<os<<endl;
	// combinationsOfString(os, s, s.size()-2);

	// cout<<"*******************\n";
	permutation(s,"");
	return 0;
}







