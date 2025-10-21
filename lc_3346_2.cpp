#include<bits/stdc++.h>
using namespace std;

// #define int long long

void solve() {
    int n, k, minop;
    cin >> n >> k >> minop;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    int maxval = *max_element(v.begin(), v.end()) + k + 2;
    int* cnt = new int[maxval]();

    for(int i : v)
        cnt[i]++;

    for(int i = 1; i < maxval; i++)
        cnt[i] += cnt[i - 1];

    int res = 0;
    for(int i = 0; i < maxval; i++) {
        int l = max(0, i - k);
        int r = min(maxval - 1, i + k);
        int t = cnt[r] - (l ? cnt[l - 1] : 0);
        int freq = cnt[i] - (i ? cnt[i - 1] : 0);
        res = max(res, freq + min(minop, t - freq));
    }

    cout << res << '\n';
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