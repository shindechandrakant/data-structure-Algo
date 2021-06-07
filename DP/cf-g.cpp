#include<bits/stdc++.h>
#include<iostream>
#include<math.h>
#include<map>
#include<vector>
#include<set>
#include<cstdlib>
#include<string>
using namespace std;
 
#define int long long

int32_t main(){
 
    int t;
    cin>>t;
    while(t--)
    {
        int ac,bc;
        cin>>ac>>bc;
        int n=ac+bc;
        map<int,int> cnt;
        cnt[0]=ac;
        cnt[1]=bc;
        char a[ac+bc];
        memset(a, ' ', sizeof(a));
        for(int i=0;i<=n/2;i++){
            int j=n-i-1;
            if(a[i]==a[j]){
                cnt[a[i]]-=2;
            }
            else if(a[i]=='0' && a[j]=='1' || a[i]=='1' && a[j]=='0'){
                cnt[a[i]]--;
                cnt[a[j]]--;
            }
            else if(a[i]=='?' && a[j]=='0'){
                a[i]='0';
                cnt[0]--;
            }
            else if(a[j]=='?' && a[i]=='0'){
                a[j]='0';
                cnt[0]--;
            }
            else if(a[i]=='?' && a[j]=='1'){
                a[i]='1';
                cnt[1]--;
            }
            else if(a[j]=='?' && a[i]=='1'){
                a[j]='1';
                cnt[1]--;
            }
        }
        for(int i=0;i<=n/2;i++){
            int j=n-i-1;
            if(a[i]=='?' && a[j]=='?'){
                if(cnt[0]%2==0){
                    cnt[0]-=2;
                    a[i]='0';
                    a[j]='0';
                }
                else if(cnt[1]%2==0){
                    cnt[1]-=2;
                    a[i]='1';
                    a[j]='1';
                }
            }
        }
        for(int i=0;i<n;i++){
            cout<<a[i];
        }
        cout<<endl;
    }
    return 0;
}








