#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;
#define lli long long int
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
problem statement -> Your task is to divide the numbers 1,2,…,n 
into two sets of equal sum.
Problem link -> https://cses.fi/problemset/task/1092
*/

set<int, std::greater<int> > answer;

void getSet(int num, int indx, int n, bool &ans, set<int, std::greater<int> > &elements) {


    if(ans or num < 0) {
        return;
    }
    if(num == 0) {

       answer = elements;
       ans = true;

    }

    for(int i = indx; i <= n && !ans; i++) {

        elements.insert(i);
        getSet(num-i, i+1, n, ans, elements);
        elements.erase(i);
    }


}


void bruteForce(lli n) {

    long long int sum = (n*(n+1))/2;

    if(sum % 2 != 0) {

        cout<<"NO";
    }
    else {

        cout<<"YES\n";
        bool flag = false;
        set<int, std::greater<int> > st;
        getSet(sum/2, 1, n, flag, st);

        cout<<answer.size()<<endl;

        for(auto it : answer) {

            cout<<it<<" ";
        }

        cout<<endl<<n-answer.size()<<endl;
        for(int i = n; i > 0; i--) {

            if(answer.count(i) == 0) {

                cout<<i<<" ";
            }

        }

    }


}
void printArray(vector<int> &arr) {

    cout<<arr.size()<<endl;
    for (int i = 0; i < arr.size(); ++i) {

        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


int main() {

    #ifndef ONLINE_JUDGE
        freopen("../io/input.txt", "r", stdin);
        freopen("../io/output.txt", "w", stdout);
        auto start = high_resolution_clock::now();
    #endif

  	long long int n;
  	cin>>n;


    // bruteForce(n);

    lli sum = (n+1)*n;
    sum /= 2;
    

    if(sum & 1) {

        cout<<"NO";
    }
    else {

        cout<<"YES\n";
        sum /= 2; 

        vector<int> set1, set2;
        while(n) {

            if(sum - n >= 0) {


                set1.push_back(n);
                sum -= n;
            }
            else {

                set2.push_back(n);
            }
            n--;
        }

        printArray(set1);
        printArray(set2);


    }






    #ifndef ONLINE_JUDGE
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout<<"\n\nTime :"<<(duration.count()/1000.0)<<" ms" << endl;
        fclose(stdin);
        fclose(stdout);
    #endif
}