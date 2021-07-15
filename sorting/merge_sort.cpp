#include<iostream>
using namespace std;
int tempArray[100];


void megreArray(int array[],int lowerBound,int mid,int upperBound)
{
	int x = lowerBound;
	cout<<endl<<endl;
	for(int i = lowerBound; i <=upperBound ; i++)
	{
		cout<<array[i]<<" ";
	}
	cout<<endl;
	int temp = 0;
	int tempStart = mid + 1;
	while(lowerBound < ( mid + 1 ) && tempStart <= upperBound)
	{
		if(array[lowerBound] < array[tempStart])
		{
			tempArray[temp] = array[lowerBound];
			lowerBound++;
		}
		else
		{
			tempArray[temp] = array[tempStart];
			tempStart++;
		}
		
		temp++;
	}
	
	if(lowerBound < ( mid + 1 ))
	{
		while(lowerBound < ( mid + 1 ))
		{
			tempArray[temp] = array[lowerBound];
			lowerBound++;
			temp++;
		}
	}
	else if(tempStart <= upperBound)
	{
		while(tempStart <= upperBound)
		{
			tempArray[temp] = array[tempStart];
			tempStart++;
			temp++;
		}
	}
	for(int i = x; i <=upperBound ; i++)
	{
		cout<<tempArray[i]<<" ";
	}
	
	
}

void mergeSort(int array[],int lowerBound,int upperBound) {
	cout<<endl<<"LowerBound "<<lowerBound<<" , upperBound "<<upperBound<<endl;
	if(lowerBound < upperBound) {

		int mid = ( lowerBound + upperBound ) / 2;
		mergeSort(array,lowerBound,mid);
		mergeSort(array,mid+1,upperBound);
		megreArray(array,lowerBound,mid,upperBound);
		
	}
}



int main() {
	int array[] = {7,6,5,4,3,2,1};

	cout<<"Array before Sorting : ";
	for(int i = 0; i < 7; i++) {
		cout<<array[i]<<" ";
	}
	cout<<endl<<endl;

	int lowerBound = 0;
	int upperBound = 6;
	mergeSort(array,lowerBound,upperBound);

	cout<<"Array After Sorting : ";
	for(int i = 0; i < 7; i++) {
		cout<<tempArray[i]<<" ";
	}
	cout<<endl<<endl;

}

















