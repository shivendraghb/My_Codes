#include<bits/stdc++.h>
using namespace std;

// #define int long long

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(2));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 2; j++)
            cin >> v[i][j];

    vector<pair<int,int>> p;
    p.reserve(n);
    for(int i = 0; i < n; ++i) p.emplace_back(v[i][0], v[i][1]);

    sort(p.begin(), p.end(), [](auto &A, auto &B){
        if (A.second != B.second) return A.second < B.second;
        return A.first > B.first;
    });

    int ans = 0;
    long long a = -4e18, b = -4e18; // a < b are the two largest chosen points

    for (auto &it : p) {
        int l = it.first, r = it.second;
        if (l <= a) {
            continue; // both a and b are inside [l,r]
        } else if (l <= b) {
            // only b is inside, add one point (r)
            ans++;
            a = b;
            b = r;
        } else {
            // none are inside, add two points
            ans += 2;
            if (r - 1 >= l) {
                a = r - 1;
                b = r;
            } else {
                // fallback (shouldn't occur for valid inputs where r-l>=1)
                a = l;
                b = r;
            }
        }
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