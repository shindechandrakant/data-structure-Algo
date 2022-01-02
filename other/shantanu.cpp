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

// int solution(vector<int> &A) {

//     sort(A.begin(), A.end());

//     int start = 0;
//     int end = A.size()-1;

//     while(start < end) {

//         if(A[start] < 0 && abs(A[start]) == A[end]) {

//             return A[end];
//         }
//         else if(abs(A[start]) > A[end]) {

//             start++;
//         }
//         else {
//             end--;
//         }
//     }

//     return 0;
// }



int solution(string &S, vector<int> &C) {


    if(S.size() < 2) {

        return 0;
    }
    int ans = 0;
    int back = 0;
    int forward = 1;
    while(forward < S.size()) {

        if(S[back] == S[forward]) {

            if(C[back] <= C[forward]) {

                ans += C[back];
                back = forward;
                forward++;
            }
            else {

                ans += C[forward];
                forward++;
            }
        }
        else {

            back = forward;
            forward++;
        }
    }
    return ans;
}

int main() {

    freopen("../io/input.txt", "r", stdin);
    freopen("../io/output.txt", "w", stdout);
    auto start = high_resolution_clock::now();




    int n;
    cin>>n;
    string s;
    cin>>s;

    vector<int> vec(n);

    for (int i = 0; i < n; i++)
    {
        cin>>vec[i];
    }

    cout<<solution(s, vec);







    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout<<"\n\nTime :"<<(duration.count()/1000.0)<<" ms" << endl;
    fclose(stdin);
    fclose(stdout);
}