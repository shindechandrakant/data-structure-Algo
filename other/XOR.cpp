/*
#include <iostream>
using namespace std;
#include<vector>
#include<bits/stdc++.h>
#include<math.h>
#define lli long long int 

int main() {

    int t;
    cin>>t;
    
    while(t--)
    {
      
        lli c;
        cin>>c;
        lli d = ceil(log2(c));
        lli limit = 1 << d; 
        lli ans = 0;
        
        
        if(limit <= c) {
            limit = limit << 1;
        }

        cout<<"C : "<<c<<" D : "<<d<<" limit : "<<limit<<" \n";
        for(lli i = 0; i < limit ; i++)
        {
            for(lli j = i+1; j < limit ; j++)
            {
                
                if((i xor j) == c)
                {
                    cout<<i<<" "<<j<<" ";
                    lli temp = i * j;
                    if(temp > ans) {
                        ans = temp;
                        cout<<ans<<"* ";
                    }
                    cout<<endl;
                }
            }
        }
        cout<<ans<<"\n\n\n";
    }
    

}

*/


/*
D : 30 limit : 1073741824 is : 536870911
610612728 536870911 327820211549555208


*/

/*
C : 13 D : 4 limit : 16 is : 7
10 7 70
C : 21 D : 5 limit : 32 is : 15
26 15 390
C : 7 D : 3 limit : 8 is : 3
4 3 12
C : 10 D : 4 limit : 16 is : 7
13 7 91

C : 13 D : 4 limit : 16 0 13 
1 12 12* 
2 15 30* 
3 14 42* 
4 9 
5 8 
6 11 66* 
7 10 70* 
70


C : 21 D : 5 limit : 32 
0 21 0
1 20 20* 
2 23 46* 
3 22 66* 
4 17 68* 
5 16 80* 
6 19 114* 
7 18 126* 
8 29 232* 
9 28 252* 
10 31 310* 
11 30 330* 
12 25 
13 24 
14 27 378* 
15 26 390* 
390


C : 7 D : 3 limit : 8 
0 7 
1 6 6* 
2 5 10* 
3 4 12* 
12


C : 10 D : 4 limit : 16 0 10 
1 11 11* 
2 8 16* 
3 9 27* 
4 14 56* 
5 15 75* 
6 12 
7 13 91* 
91
*/





#include <iostream>
using namespace std;
#include<vector>
#include<bits/stdc++.h>
#include<math.h>
#define lli long long int 

int main() {

    int t;
    cin>>t;
    
    while(t--)
    {
      
        lli c;
        cin>>c;
        lli d = ceil(log2(c));
        lli limit = 1 << d; 
        
        if(limit <= c) {
            while(limit <= c)
                limit = limit << 1;
            cout<<"hello";
        }
        
        cout<<"C : "<<c<<" D : "<<d<<" limit : "<<limit<<" ";
        lli is = limit / 2;
        is -=1;
        cout<<"is : "<<is<<endl;

        lli sec = c xor is;

        cout<<sec*is<<endl;
        // bool got = true;
        // lli  y = 0;
        
        // if(c % 2 == 0) {
        //     limit -= 1;
        // }

        // for(lli i = limit; i >= is; i -= 2) {
        //     y++;
        //     lli ans = (i xor is);
        //     if( ans == c) {
        //         cout<<i << " "<<is<<" ";
        //         cout<<i*is<<endl;
        //         got = false;
        //         break;
        //     }
        // }
        // cout<<endl<<y<<endl;
        // if(got) {
        //     cout<<0<<endl;
        // }
        
        
    }

}

/**
C : 1000000000 D : 30 limit : 1073741824 is : 536870911

268435456
0
C : 1000000007 D : 30 limit : 1073741824 is : 536870911
610612728 536870911 327820211549555208
463129096


*/