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
 Problem link -> https://codeforces.com/problemset/problem/1374/C
 */
 
 int main() {
 
     #ifndef ONLINE_JUDGE
         freopen("../io/input.txt", "r", stdin);
         freopen("../io/output.txt", "w", stdout);
         freopen("../io/err.txt", "w", stderr);
         auto start = high_resolution_clock::now();
     #endif
 
   
 
 	int t;
 	cin>>t;

 	while(t--) {

 		string str;
 		int n;
 		cin>>n>>str;

 		stack<pair<char, int> > stk;
 		vector<bool> contribution(n, false);

 		stk.push({str[0], 0});

 		for(int i = 1; i < n; i++) {


            if(str[i] == '(') {

                stk.push({'(', i});
                continue;
            }

            if(!stk.empty()) {

                if(stk.top().first == '(') {

                    contribution[stk.top().second] = true;
                    contribution[i] = true;
                    stk.pop();
                }
            }
 		}

 

        int open = 0;
        int close = 0;

        for(int i = 0; i < n; i++) {

            if(!contribution[i]) {

                if(str[i] == '(')
                    open++;
                else
                    close++;

            }


        }

        cout<<min(open, close)<<endl;
 
 
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