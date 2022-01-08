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
#define MOD 1000000007

/*
problem statement -> 
Problem link -> https://codeforces.com/problemset/problem/1359/A
*/

int main() {

    #ifndef ONLINE_JUDGE
        freopen("../io/input.txt", "r", stdin);
        freopen("../io/output.txt", "w", stdout);
        freopen("../io/err.txt", "w", stderr);
        auto start = high_resolution_clock::now();
    #endif

  

    int t = 1;
    cin>>t;

    while(t--) {

    	int cards, jokers, players;
    	cin>>cards>>jokers>>players;

        if(jokers == 0) {

            cout<<0<<endl;
            continue;
        }

        int remCards = cards - jokers;
        int eachPlayer = cards / players;

        if((jokers == eachPlayer) || (jokers < eachPlayer)) {

            cout<<jokers<<endl;
        }
        else{

            int rem = jokers - eachPlayer;
            players -= 1;

           if(rem > players) {
                
                int baki = rem / players;
                if((baki * players) != rem)
                    eachPlayer -= (baki +1);
                else
                    eachPlayer -= baki;

           }
           else
               eachPlayer -= 1;
            cout<<eachPlayer<<endl;
        }

    	

    	



    }














    #ifndef ONLINE_JUDGE
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout<<"\n\nTime :"<<(duration.count()/1000.0)<<" ms" << endl;
        fclose(stdin);
        fclose(stdout);
        fclose(stderr);
    #endif


}