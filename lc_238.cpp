#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> r(n, 1);

    vector<int> prefix(n, 1), suffix(n, 1);

    for(int i = 1; i < n; i++) {
        prefix[i] = prefix[i-1] * a[i-1];
    }
    for(int i = n-2; i >= 0; i--) {
        suffix[i] = suffix[i+1] * a[i+1];
    }
    for(int i = 0; i < n; i++) {
        r[i] = prefix[i] * suffix[i];
    }

    for(int i : prefix)
        cout << i << " ";
    cout << '\n';

    for(int i : suffix)
        cout << i << " ";
    cout << '\n';

    for(int i : r)
        cout << i << " ";

    cout << '\n';
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
