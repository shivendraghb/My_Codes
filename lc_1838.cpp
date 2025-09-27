#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());
    int i = 0, j = 0, ans = 1, sum = v[0];

    for(; i < n; i++) {
        while(j < n && (j - i + 1) * v[j] - sum <= k) {
            ans = max(ans, j - i + 1);
            j++;
            if(j < n) sum += v[j];
        }
        sum -= v[i];
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
