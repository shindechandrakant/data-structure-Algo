#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
#define vi vector<int>

int main() {
  
  int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        int n, k;
        cin >> n >> k;
        vi arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        vi lens;
        int s1 = 0, s2 = 0;
        if (arr[0] != 1) {
            s1 = arr[0] - 1;
        }
        for (int i = 1; i < n; i++) {
            lens.push_back(arr[i] - arr[i - 1] - 1);
        }
        if (arr.back() != k) {
            s2 = k - arr.back();
        }
        int ans1 = max(s1, s2);
        int add1 = 0;
        for (int i = 0; i < lens.size(); i++) {
            add1 = max(add1, ((lens[i] + 1) / 2));
        }
        ans1 += add1;
        int ans = ans1;
        for (int i = 0; i < lens.size(); i++) {
            ans = max(ans, lens[i]);
        }
        long double temp = (float)ans / float(k);
        cout << fixed;
        cout << "Case #" << tt << ": " << setprecision(10) << temp << endl;
    }
}