#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    // int l = 0, r = n - 1;

    // while(l < r) {
    //     int mid = l + (r - l) / 2;
    //     if(v[mid] > v[mid + 1])
    //         r = mid;
    //     else
    //         l = mid + 1;
    // }

    // cout << l << '\n';

    
    int m = *max_element(v.begin(), v.end());
    auto it = find(v.begin(), v.end(), m);
    int d = distance(v.begin(), it);

    cout << d << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}