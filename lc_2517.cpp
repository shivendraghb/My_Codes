#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());
    int l = 0, r = v.back() - v.front();

    while(l - r) {
        int m = (l + r + 1) / 2, cnt = 1;
        for(int i = 1, j = 0; i < n; i++)
            if(v[i] - v[j] >= m) {
                cnt++;
                j = i;
            }
            
            if(cnt >= k)
                l = m;
            else
                r = m - 1;
    }

    cout << l << '\n';
}

int32_t main() {
    ios::sync_with_stdio;
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}