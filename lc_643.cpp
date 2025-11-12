#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    int sum = 0;
    for(int i = 0; i < k; i++) sum += v[i];

    int ans = sum;
    for(int i = k; i < n; i++) {
        sum += v[i];
        sum -= v[i - k];
        if (sum > ans) ans = sum;
    }

    cout << (double)ans / k << '\n';

    
}