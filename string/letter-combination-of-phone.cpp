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

int main() {

    freopen("../io/input.txt", "r", stdin);
    freopen("../io/output.txt", "w", stdout);


	
    int y = -9;
    int x = 0 - y;

    cout<<x;





    fclose(stdin);
    fclose(stdout);

}
class Solution {
public:
    
    const vector<string> pad {
        "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
    };
    
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        
        vector<string> result;
        result.push_back("");
        
        for(auto digit : digits){
            vector<string> temp;
            for(auto dial : pad[digit- '0']){
                for(auto s : result){
                    temp.push_back(s + dial);
                }
            }
            result.swap(temp);
        }
        return result;
    }
};