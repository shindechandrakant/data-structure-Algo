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

bool isPrime(int x) {


	for(int i = 2; i <= sqrt(x); i++) {

		if(x % i == 0) {

			return false;
		}
	}

	return true;
}



void primeDivisors(int x) {


	cout<<"Prime Divisors of "<<x<<" : ";

	while(x) {

		int to = sqrt(x);

		bool temp = true;
	
		for(int i = 2; i <= to; i++) {

			if(x % i == 0) {

				temp = false;
				cout<<i<<" ";
				x = x / i; // x = x / i
				break;
			}
		}
		cout<<x<<" ";
		if(temp) {
			cout<<x<<" ";
			break;
		}
		cout<<endl;
	}
	cout<<endl;
}


void bubbleSort(int arr[], int size) {

	for(int i = 0; i < size; i++) { // size

		for(int j = 0; j < size-1; j++) { // size

			// 1 < 2
			if(arr[j+1] < arr[j]) {

				// swap(arr[j+1] , arr[j]);
				// int temp = arr[j];
				// arr[j] = arr[j+1];
				// arr[j+1] = temp;

				arr[j] = arr[j] + arr[j+1];
				arr[j+1] = arr[j] - arr[j+1];
				arr[j] = arr[j] - arr[j+1];

				// a = a + b
				// b = a - b
				// a = a - b
			}
		}
	}
}



void selectionSort(int arr[], int size) {

	for(int i = 0; i < size; i++) {


		int indx = i;
		for(int j = i + 1; j < size; j++) {

			if(arr[j] < arr[indx]) {

				indx = j;
			}
		}
		swap(arr[i], arr[indx]);
	}
}



int main() {

    freopen("../io/input.txt", "r", stdin);
    freopen("../io/output.txt", "w", stdout);


	// // given num is prime or not
	// for(int i = 0; i < 5; i++) {

	// 	int x;
	// 	cin>>x;
	// 	primeDivisors(x);
	// 	cout<<endl;
	// }


    // int arr[] = { 2, 3, 1, 4, 7};
    // for(int i = 0; i < 5; i++) cout<<arr[i]<<" ";

    // newline(2);
    // bubbleSort(arr, 5);

    // for(int i = 0; i < 5; i++) cout<<arr[i]<<" ";



    //fibonachi
    int start = 0;
	int end = 1;

	for(int i = 0; i < 10; i++) {
	
	int sum = start + end;
	// sum = 1
	cout<<start<<" ";
	end = start;
	start = sum;
}



    fclose(stdin);
    fclose(stdout);

}







//









