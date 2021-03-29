#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define MOD 1000000007
#define vi vector<int>


int main() 
{
    int t;
    cin>>t;

    for(int tt = 1; tt <= t; tt++) {
        

    cout<<"Case #"<<tt<<": ";
    int p,a,b,cnt=0 ;
    string s;
    cin>>a>>b>>s;
    int i,j;
    p=s.length();
    for(i=0;i<p;i++)
    {
        if(s[i]=='?')
            cnt++;
    }
    if(cnt==p || cnt==p-1)
    {
        cout<<"0"<<endl;
        continue;
    }
    int k;
    for(k=0;k<p-1;k++)
    {
        if(s[k]!='?')
            break;
    }
    int cost = 0;
    if(k==0)
        k++;
    i=k;
    while(i<p-1)
    {
        if(s[i]=='?')
        {
            if(s[i-1]!=s[i+1] && s[i+1]!='?')
            {
                if(s[i-1]=='J')
                    cost+=b;
                else
                    cost+=a;
            }
            else if(s[i-1]!=s[i+1] && s[i+1]=='?')
            {
                j=i+2;
                while(s[j]=='?' && j<p)
                {
                    j++;
                }
                if(j==p)
                {
                    break;
                }
                if(s[i-1]!=s[j])
                {
                    if(s[i-1]=='J')
                        cost+=b;
                    else
                        cost+=a;
                }
                i=j;
            }
        }
        i++;
    }
  
    for(i=0;i<p-1;i++)
    {
        if(s[i]=='J' && s[i+1]=='C')
            cost+=b;
        else if(s[i]=='C' && s[i+1]=='J')
            cost+=a;
    }
    cout<<cost;
    cout<<endl;


 

        
    }
}