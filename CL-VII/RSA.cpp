/*
Assignment 1: Write a program in C++ or JAVA to implement RSA algorithm for key generation and cipher verification
Name: Amogh Kulkarni

*/
#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<cstdlib>
#include<string.h>
#include<ctime>
using namespace std;
bool isprime(int n)
{
	if(n==2)
		return true;
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
			return false;
	}
	return true;
}
int gcd(int n1,int n2)
{
	if(n1==n2)
		return n1;
	if(n1==0)
		return n2;
	else if(n2==0)
		return n1;
	if(n1<n2)
		return gcd(n1,n2-n1);
	return gcd(n1-n2,n2);
}
int getkey(int phi,int *arr)
{
	int k=0;
	for(int i=2;i<phi;i++)
	{
		int g=gcd(i,phi);
		//cout<<"gcd of"<<i<<","<<phi<<" ="<<g<<endl;
		if(gcd(i,phi)==1)
		{
			arr=(int*)realloc(arr,sizeof(int));
			arr[k++]=i;
			//cout<<"found "<<arr[k-1]<<endl;
		}	
	}
	/*for(int i=0;i<k;i++)
		cout<<arr[i]<<",";
	cout<<endl;*/
	return k;
}
int d_find(int phi,int e)
{
	int y1=0,y2=1,y3,d3,d1=phi,d2=e,k=phi/e;
	do
	{
		y3=y1-(y2*k);
		d3=d1%d2;
		y1=y2;
		y2=y3;
		d1=d2;
		d2=d3;
		k=d1/d2;
		//cout<<"d3="<<d3<<endl;
	}while(d3!=1);
	if(y2<0)
		return y2+phi;
	return y2;
}
int mod(int a,int b,int n)
{
	if(b==2)
	{
		return ((a%n)*(a%n))%n;
	}
	return ((a%n)*mod(a,b-1,n))%n;
}
int main()
{
	int p,q,phi,e,d,n,ct,*keys,s=0;
	keys=(int*)malloc(0);
	string m;
	//srand((unsigned) time(0));
	cout<<"Enter numbers"<<endl;
	cin>>p;
	while(!isprime(p))
	{
		cout<<"Not prime ! enter again"<<endl;
		cin>>p;
	}
	cin>>q;
	while(!isprime(q))
	{
		cout<<"Not prime ! enter again"<<endl;
		cin>>q;
	}
	n=p*q;
	phi=(p-1)*(q-1);
	cout<<"n="<<n<<",phi="<<phi<<endl;
	s=getkey(phi,keys);
	cout<<"Keys are "<<endl;
	for(int i=0;i<s-1;i++)
		cout<<keys[i]<<",";
	cout<<keys[s-1]<<endl;
	srand(time(0));
	e=keys[(rand()%s)];
	cout<<"public key="<<e<<endl;
	d=d_find(phi,e);
	cout<<"d="<<d<<endl<<"Enter message"<<endl;
	cin.clear();
	cin.ignore();
	getline(cin,m,'\n');
	char CT[m.length()],PT[m.length()];
	for(int i=0;i<m.length();i++)
	{
		int times=(int)m[i]/n,x=(int)m[i]%n;
		ct=mod(x,e,n);
		CT[i]=(char)ct;
		PT[i]=(char)(mod(ct,d,n)+times*n);
	}
	PT[m.length()]='\0';
	cout<<"Cipher text is "<<CT<<endl;
	cout<<"Decrypted plane text is "<<PT<<endl;
	
	return 0;
}

/*
Output:-

Enter numbers
11
13
n=143,phi=120
Keys are
7,11,13,17,19,23,29,31,37,41,43,47,49,53,59,61,67,71,73,77,79,83,89,91,97,101,103,107,109,113,119
public key=53
d=77
Enter message
Hi I am SANTOSH
Cipher text is Ç(6p6Pm6AmY@
Decrypted plane text is Hi I am SANTOSH
*/
