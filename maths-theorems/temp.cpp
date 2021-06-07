
#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
#define vi vector<ll>
#define pi pair<ll, ll>
#define v2d(name, m, n, inti) vector<vi>(name)(m, vi(n, inti))

// problem statement -> 
// Problem link -> 

int main() {

	cout<<(9 & (-9));

}





























/*
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
int main()
{
    int tt;
    cin>>tt;

    while(tt--){

        lli n,q;
        cin>>n>>q;

        lli a[n];

        for(int i = 0;i<n;i++)

            cin>>a[i];

        int dpArr[31] = {0};

        for(int i=0;i<n;i++){

            for(int j=0;j<31;j++) {

                lli x = 1<<j;

                if(a[i]&x)

                    dpArr[j] += 1;

            }

        }

        lli ans = 0;

        for(int i=0;i<31;i++){

            lli x = 1<<i;

            if(dpArr[i])

                ans += x;

        }

        cout<<ans<<endl;

        for(int k=0;k<q;k++){

            lli idx,val;

            cin>>idx>>val;

            for(int i=0;i<31;i++){

                lli x=1<<i;

                if(a[idx-1]&x){
                    dpArr[i] -= 1;
                }
            }

            for(int i=0;i<31;i++){

                lli x = 1<<i;

                if(val&x){

                    dpArr[i] += 1;

                }

            }

            a[idx-1] = val;

            lli ans = 0;

            for(int i=0;i<31;i++){

                lli x = 1<<i;

                if(dpArr[i]>0)

                    ans += x;

            }
            cout<<ans<<endl;
        }
    }
}

*/