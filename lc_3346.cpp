#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, k, minop;
    cin >> n >> k >> minop;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    int ans = 0, r = 0, l = 0;
    sort(v.begin(), v.end());

    unordered_map<int, int> mp;
    for(int i : v)
        mp[i]++;

    for(int mid = 0; mid < n; mid++) {
        while(v[mid] - v[l] > k)
            l++;

        while(r < n - 1 && v[r + 1] - v[mid] <= k)
            r++;

        int total = r - l + 1;

        ans = max(ans, min(total - mp[v[mid]], minop) + mp[v[mid]]);
    }

    l = 0;
    for(r = 0; r < n; r++) {
        int mid = (v[l] + v[r]) / 2;

        while(mid - v[l] > k || v[r] - mid > k) {
            l++;
            mid = (v[l] + v[r]) / 2;
        }

        ans = max(ans, min(r - l + 1, minop));
    }

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
