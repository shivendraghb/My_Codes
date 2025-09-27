#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());
    for(int i = v.size() - 1; i >= 2; i--) {
        if(v[i - 2] + v[i - 1] > v[i]) {
            cout << v[i - 2] + v[i - 1] + v[i] << '\n';
            return;
        }
    }

    cout << 0 << '\n';
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
