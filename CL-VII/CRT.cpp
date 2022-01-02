/*
Assignment 2: 
*/
#include<iostream>
using namespace std;
int gcd(int n1,int n2) {
	
	return n1 == 0 ? n2 : gcd(n2, n1%n2);
}

bool check_coprimes(int n[],int index)
{
	for(int i=0;i<index;i++)
	{
		if(gcd(n[index],n[i])!=1)
		{
			cout<<"enter valid number "<<endl;
			return false;
		}
			
	}
	return true;
}
int d_find(int phi,int e) {
	
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

int main()
{
	int e,N=1;
	cout<<"Enter number of euqations"<<endl;
	cin>>e;
	int n[e],a[e],y[e],z[e];
	for(int i=0;i<e;i++)
	{
		cout<<"enter a["<<i+1<<"]"<<endl;
		cin>>a[i];
		do
		{
			cout<<"enter n["<<i+1<<"]"<<endl;
			cin>>n[i];
		}while(!check_coprimes(n,i));
		N*=n[i];
	}
	int sum=0;
	for(int i=0;i<e;i++)
	{
		y[i]=N/n[i];
		z[i]=d_find(n[i],y[i]);
		sum+=a[i]*z[i]*y[i];
	}
	cout<<"X is "<<sum%N<<endl;
}

