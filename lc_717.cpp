#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    auto func = [&] (const vector<int>& v, int n) {
        int i = 0;
        while (i < n - 1) {
            if (v[i] == 1) i += 2;
            else i += 1;
        }

        return i == n - 1;
    };

    cout << (func(v, n) ? "true" : "false") << '\n';
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