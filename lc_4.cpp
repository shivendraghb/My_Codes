#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> v1(n);
    for(int i = 0; i < n; i++)
        cin >> v1[i];

    vector<int> v2(m);
    for(int i = 0; i < m; i++)
        cin >> v2[i];

    vector<int> v3;

    for(int i = 0; i < n; i++)
        v3.push_back(v1[i]);

    for(int i = 0; i < m; i++)
        v3.push_back(v2[i]);

    sort(v3.begin(), v3.end());

    int n3 = v3.size();

    if(n3 % 2 == 1) {
        cout << static_cast<double> (v3[n3 / 2]) << '\n';
        return;
    }
    else {
        cout << (static_cast<double>(v3[n3 / 2 - 1]) + static_cast<double>(v3[n3 / 2])) / 2.0 << '\n';
    }
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
