#include<bits/stdc++.h>
using namespace std;

// #define int long long

int concatenate(int a, int b) {
    int bits = 0;
    int temp = b;
    while (temp > 0) {
        bits++;
        temp >>= 1;
    }
    return (a << bits) | b;
}

void solve() {
    vector<int> a(3);
    cin >> a[0] >> a[1] >> a[2];

    int ans = 0;
    sort(a.begin(), a.end());

    do {
        int value = a[0];
        value = concatenate(value, a[1]);
        value = concatenate(value, a[2]);
        ans = max(ans, value);
    } while (next_permutation(a.begin(), a.end()));

    cout << ans << '\n';
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