#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
#define vi vector<ll>
#define pi pair<ll, ll>
#define vb vector<bool>
#define vs vector<string>
#define newline(n) for(int i = 0; i < (n); i++ )cout<<endl;
#define infor(vect) for(auto it : (vect)) { cout<<it<<endl; }
#define ump unordered_map
#define mp map
#define v2d(name, m, n, inti) vector<vi>(name)(m, vi(n, inti))
#define MOD 1000000007

/*
problem statement -> 
Problem link -> 
*/

void megreArray(vi &array, int start, int mid, int end) {


    vector<ll> tempArray(array.size());
    int counter = 0;
    int first_i = start;
    int second_j = mid+1;


    while(first_i <= mid && second_j <= end) {


        if(array[first_i] < array[second_j]) {

            tempArray[counter] = array[first_i];
            first_i++;
            counter++;
        }
        else {

             tempArray[counter] = array[second_j];
             second_j++;
             counter++;
        }
    }

    while(first_i <= mid) {

        tempArray[counter] = array[first_i];
        counter++;
        first_i++;
    }

    while(second_j <= end) {

        tempArray[counter] = array[second_j];
        counter++;
        second_j++;
    }


    for(int i = start, xx = 0; i <= end; i++, xx++) {

        array[i] = tempArray[xx];

    }




	
}



void mergeSort(vi &array, int start, int end) {

	if(end > start) {	

    	int mid = (start + end) / 2;
    	mergeSort(array, start, mid);
    	mergeSort(array, mid+1, end);
    	megreArray(array, start, mid, end);
    }
}


int main() {

    freopen("../io/input.txt", "r", stdin);
    freopen("../io/output.txt", "w", stdout);


	int n;
    cin>>n;
    vi array(n);

    for(int i = 0; i < n; i++)
    	cin>>array[i];

    // print array before sorting
    for(auto it : array) cout<<it<<" ";
    
    //Merge sort function

    newline(3);
    mergeSort(array, 0, n-1);


    // print array after sorting
    for(auto it : array) cout<<it<<" ";






    fclose(stdin);
    fclose(stdout);

}