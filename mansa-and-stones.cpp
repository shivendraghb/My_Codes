#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    set<int> curr;
    for(int i = 0; i < n; i++) {
        int v = i * a + (n - 1 - i) * b;
        curr.insert(v);
    }

    vector<int> r(curr.begin(), curr.end());

    for(const auto i : r)
        cout << i << " ";
    
    cout << '\n';
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