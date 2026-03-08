#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    vector<string> nums(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    string ans(n, '0');

    for (int i = 0; i < n; i++)
        ans[i] = nums[i][i] ^ 1;

    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}