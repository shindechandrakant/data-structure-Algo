#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define MOD 1000000007
#define vi vector<int>
#define vs vector<string>
#define vp vector<pair<int, int>

vs formPair(string s) {

  vp ans(s.size());

  int n = s.size();

  for(int i = n - 1; i >= 0; i--) {





  }







  return ans;
}





int main() {
  

  int t;
  cin>>t;
  while(t--)
  {
    string s;
    cin>>s;
 
    int fe1 = s.find('0');
    
    if(fe1 == -1) {

        cout<<"0\n";
        continue;
    }
    
    fe1 = s.find('1');
    if(fe1 == -1) {

        cout<<"1\n";
        continue;
    }

    string ans = "0";
    lli limit = 1 << s.size();
    for(lli i = 1; i <= limit; i++) {
        
        string temp = bitset<64> (i).to_string();
        int digits = log2(i)+1;
        int indx = temp.size() - digits;
        temp = temp.substr(indx);
        int pos = s.find(temp);
        if(pos == -1) {
             ans = temp;
            break;
        }
    }
    cout<<ans<<endl;
  }
}