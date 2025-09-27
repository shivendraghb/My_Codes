#include<bits/stdc++.h>
using namespace std;

#define int long long

// bool seen(int x, const vector<int>& b) {
//     for(int i : b)
//         if(i == x)
//             return true;

//     b.push_back(x);
//     return false;
// }

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    unordered_set<int> seen;

    int l = 0;
    int s = 0, ans = 0;
    for(int r = 0; r < a.size(); r++) {
        while(seen.count(a[r])) {
            s -= a[l];
            seen.erase(a[l]);
            l++;
        }
        seen.insert(a[r]);
        s += a[r];
        ans = max(ans, s);
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
