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











/*
#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
#define vi vector<int>

vector<pair<ll, ll>> v(10000009);


void seive() {


	v[0].first = 0;
	v[0].second = 0;

	v[1].second = 1;
	v[1].first = 1;
	v[2].second = 3;
	v[2].first = 2;


	for(int i = 3; i < 10000009; i++) {

		ll sum = 0;
		// cout<<"je"<<endl;
		for(int j = 1; j <= sqrt(i)+1; j++) {


			if(i % j == 0) {

				int x = i / j;

				if(x == j) {
					sum += x;
				}
				else {

				  sum = sum + x + j;
				}
			}
		}
		v[i].first = i;
		v[i].second = sum;
	}


}

int main() {
  

  seive();
  ll t;
  cin>>t;
  while(t--)
  {
  		ll n;
  		cin>>n;

  		ll org = n;

  		bool flag = true;
  		for(int i = org; i > 0; i--) {

  			if(v[i].second == org) {

  				cout<<v[i].first<<endl;
  				flag = false;
  				break;
  			} 
  		}
  		if(flag)
  			cout<<-1<<endl;
  }
  
}*/