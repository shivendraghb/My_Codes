#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    int res = INT_MAX, c1 = 0;

    for(int i = 0; i < n; i++)
        c1 += (v[i] == 1);

    if(c1) { cout << n - c1 << '\n'; return;}

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            v[i] = __gcd(v[i], v[j]);
            if(v[i] == 1) {
                res = min(res, j - i + n - 1);
                break;
            }
        }
    }

    cout << (res == INT_MAX ? -1 : res) << '\n';
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