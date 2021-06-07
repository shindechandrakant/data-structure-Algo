// problem link -> https://www.hackerearth.com/practice/codemonk/

#include <iostream>
using namespace std;
#include<bits/stdc++.h>
#define lli long long int

map<lli, vector<lli>> mp;
void preComput() {
    lli limit = 1073741;


    for(lli i = 1; i <= limit; i++) {

        lli crr = i;
        lli count = 0;

        while(crr) {
            crr = crr & (crr-1);
            count++;
        }
        mp[count].push_back(i);
    }
}


void display() {

    for(int i = 1; i < 31; i++) {
        cout<<i<<" -> ";
        for(auto it : mp[i]) 
            cout<<it<<" ";
        cout<<endl;
    }
}


int main() {

    preComput();
    display();
    // lli t;
    // cin>>t;
    // while(t--)
    // {
    //     int n, st;
    //     cin>>n>>st;
    //     vector<lli>v(n);
    //     for(int i = 0; i < n; i++)  cin>>v[i];
    //     vector<lli>temp = mp[st];

    //     if(temp.size() == 0) {
    //         cout<<-1<<endl;
    //         continue;
    //     }
    //     lli max = 0;
    //     lli ans;
    //     for(int i = 0; i < n; i++) {
    //         for(int j = 0; j < temp.size(); j++) {

    //             lli x = v[i] & temp[j];
    //             if(x > max) {
    //                 max = x;
    //             }
    //         }
    //     }
    //     cout<<max<<endl;
    // }
}


