#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    vector<int> v = {1, 2, 2, 2, 2, 2, 9, 9, 10};

    auto it = upper_bound(v.begin(), v.end(), 2);

    int cnt = upper_bound(v.begin(), v.end(), 2)
            - lower_bound(v.begin(), v.end(), 2);
    cout << cnt << '\n';9

    cout << (it - v.begin()) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // int t;
    // cin >> t;

    // while(t--) {
    //     solve();
    // }
    solve();

    return 0;
}