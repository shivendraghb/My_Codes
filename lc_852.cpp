#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    int l = 0, r = n, mid;

    while(l < r) {
        mid = (l + r) / 2;
        if(v[mid] < v[mid + 1])
            l = mid + 1;
        else
            r = mid;
    }

    cout << l << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
}