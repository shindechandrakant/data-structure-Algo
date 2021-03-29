#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define MOD 1000000007
#define vi vector<int>




void display(vi &v){

    for(auto it : v)
        cout<<it<<" ";
    cout<<endl;
}




void doRev(vi &v, int start, int end) {

    while(start < end) {

        swap(v[start], v[end]);
        start++;
        end--;
    }
}

int main() 
{
    int t;
    cin>>t;
    map<int, vector<vi>> mp;
    for(int tt = 1; tt <= t; tt++) {
        
        int n = 4;
        // cin>>n;
        vi v(n+1);
        vi org(v);
        for(int i = 1; i <= n; i++) {
             cin>>v[i];
             org[i-1] = v[i];
        }
        // display(v);
        int cost = 0;

        for(int i = 1; i < n; i++)
        {
            int minV = v[i];
            int pos = i;

            for(int j = i; j <= n; j++) {

                if(minV > v[j]) {

                    minV = v[j];
                    pos = j;
                }
            }


            doRev(v, i, pos);
            // display(v);
            cost += (pos - i + 1);
        }

        mp[cost].push_back(org);

        cout<<"Case #"<<tt<<": "<<cost<<endl;
    }
    cout<<endl<<endl;

    for(auto it : mp) {

        cout<<it.first<<endl;
        auto matrix = it.second;

        for(auto row : matrix) {

            for(auto col : row)
                if(col != 0)
                    cout<<col<<" ";

            cout<<endl;
        }
        cout<<endl;



    }



}