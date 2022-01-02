#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;
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
//						0   1 	 2 		3 	   4
 vector<string> nums = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"} ;


    vector<string> keypadCombination(string str) {

        if(str.size() == 1) {

            vector<string> temp;


            for(auto chr: nums[str[0] - '0']) {

                string tt;
                tt.push_back(chr);
                temp.push_back(tt);
            }

            return temp;
        }

        char currDigit = str[0];
        str = str.substr(1);
        vector<string> rem = keypadCombination(str);

        vector<string> answer;

        for(auto it : rem) {

            for(char chr : nums[currDigit - '0']) {

                string temp = chr+it;
                answer.push_back(temp);
            }
        }


        return answer;
    }



int main() {

    #ifndef ONLINE_JUDGE
        freopen("../io/input.txt", "r", stdin);
        freopen("../io/output.txt", "w", stdout);
        auto start = high_resolution_clock::now();
    #endif

  

    string str;
    cin>>str;
    cout<<str<<endl;


    vector<string> ans = keypadCombination(str);

    for(auto it : ans) {

    	cout<<it<<endl;
    }













    #ifndef ONLINE_JUDGE
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout<<"\n\nTime :"<<(duration.count()/1000.0)<<" ms" << endl;
        fclose(stdin);
        fclose(stdout);
    #endif
}