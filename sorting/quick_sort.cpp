#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;
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

int partition(vi &arr, int start, int end) {

    int pivote = arr[end];
    int partitionIndex = start;

    for(int i = start; i < end; i++) {

        if(arr[i] <= pivote) {

            std::swap(arr[i], arr[partitionIndex]);
            partitionIndex++;
        }
    }

    swap(arr[partitionIndex], arr[end]);
    return partitionIndex;

}



void quickSort(vi &arr, int start, int end) {


    if(start < end) {

        int partitionIndex = partition(arr, start, end);
        quickSort(arr, start, partitionIndex-1);
        quickSort(arr, partitionIndex+1, end);

    }
}




int main() {

    #ifndef ONLINE_JUDGE
        freopen("../io/input.txt", "r", stdin);
        freopen("../io/output.txt", "w", stdout);
        auto start = high_resolution_clock::now();
    #endif

  



    int n;
    cin>>n;
    vi array(n);


    for(int i = 0; i < n; i++)
        cin>>array[i];

    // print array before sorting
    for(auto it : array) cout<<it<<" ";
    
    //Quicl sort function


    array.shrink_to_fit();

    newline(3);
    quickSort(array, 0, n-1);


    // print array after sorting
    for(auto it : array) cout<<it<<" ";







    #ifndef ONLINE_JUDGE
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout<<"\n\nTime :"<<(duration.count()/1000.0)<<" ms" << endl;
        fclose(stdin);
        fclose(stdout);
    #endif


}