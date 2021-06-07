#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void factors(int num)
{

    while(num >= 1)
    {
        int x = sqrt(num);
        bool isPrime = true;
        for(int i = 2; i <= x; i++)
        {
            if(num % i == 0)
            {
                cout<<i<<", ";
                num /= i;
                isPrime = false;
                break;
            }
        }
        if(isPrime)
        {
            cout<<num;
            break;
        }
    }

}

int main()
{
    int num;
    // for(int i = 0; i < 1; i++)
    {
        // cout<<"Enter a number : ";
        cin>>num;
        // cout<<endl<<"Factors of "<<num<<" are : ";
        factors(num);
        cout<<endl;
    }


    return 0;
}