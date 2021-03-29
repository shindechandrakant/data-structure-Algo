#include<bits/stdc++.h>
#include<iostream>
#include<math.h>
#include<bits/stdc++.h>

using namespace std;


bool isUgly(int n) {
    
    bool is = true;

    int org = n;
    // int x = 1 ;
    while(n >= 2) {
        
    	bool isP = true;
        for(int i = 2; i <= n / 2; i++) {
            
            if(n % i == 0) {

                n = n / i;
                isP = false;
                break;
                
            }
        }
        if(isP)
        {
        	if(n == 3 or n == 5 or n == 2)
        		return true;
        	return false;
        }
    }

    return is;    
}

vector<int> createUglySeve() {
    
    vector<int> uglyNum;
    uglyNum.push_back(0);
    
    for(int i = 1; i <= 10001; i++) {
           
        if(isUgly(i)) {
            uglyNum.push_back(i);
        }  
    } 
       return uglyNum;
   }

int getNthUglyNo(int n) {
    if(n <= 6)
        return n;
        
       vector<int>v = createUglySeve();
       
       return v[n];
}



// m2





// 1 2 3 4 5 6 8 9 10 12 15 16 18 20 24 25 27 30 32 36 
// 1 2 3 4 5 6 8 9 10 12 15 16 18 20 24 25 27 30 32 36 

int main() 
{

	for(int i = 1 ; i <= 20; i++)
		cout<<getNthUglyNo(i)<<" ";

}










