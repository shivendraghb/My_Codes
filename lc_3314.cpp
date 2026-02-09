#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
        
    vector<int> ans;
    ans.reserve(n);

    for (int x : v) {
        if (x == 2) {
            ans.push_back(-1);
            continue;
        }

        for (int i = 1; i < 32; i++) {
            if (((x >> i) & 1) == 0) {
                ans.push_back(x ^ (1 << (i - 1)));
                break;
            }
        }
    }

    for (int i : ans)
        cout << i << " ";
    cout << '\n';
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