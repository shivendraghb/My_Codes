#include<bits/stdc++.h>
using namespace std;

// #define int long long

void solve() {
    int n;
    cin >> n;

    vector<string> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    
    int r = 0;
    for(auto& i : v)
        r += (i[1] == '+') ? 1 : -1;

    cout << r << '\n';
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