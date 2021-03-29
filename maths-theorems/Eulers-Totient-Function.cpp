#include<bits/stdc++.h>
#include<iostream>
#include <math.h>
using namespace std;

// Euler's totient function, also known as phi-function ϕ(n), 
// counts the number of integers between 1 and n inclusive,
//  which are coprime to n. Two numbers are coprime 
//  if their greatest common divisor equals 1 
//  (1 is considered to be coprime to any number).
// Link -> https://cp-algorithms.com/algebra/phi-function.html#toc-tgt-0




// sqrt(n)
int phi(int n) 
{
    int result = n;
    for (int i = 2; i * i <= n; i++) 
    {
        if (n % i == 0) 
        {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}


// O(nloglog n)
int phi_1_to_n(int n) 
{
    vector<int> phi(n + 1);
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++) 
    {
        if (phi[i] == i) 
        {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
    return phi[n];
}


// O(n log n) worse than previous
int phi_1_to_n2(int n) {
    vector<int> phi(n + 1);
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
        phi[i] = i - 1;

    for (int i = 2; i <= n; i++)
        for (int j = 2 * i; j <= n; j += i)
              phi[j] -= phi[i];

     return phi[n];
}









int main()
{
	
	int n;
	cin>>n;
	cout<<phi(n);
	cout<<endl<<phi_1_to_n(n);
	cout<<endl<<phi_1_to_n2(n);




}








