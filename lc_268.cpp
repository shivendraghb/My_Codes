#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (auto &x : nums) cin >> x;

    int mn = n;

    for (int i = 0; i < n; i++)
        mn ^= i ^ nums[i];

    cout << mn << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}