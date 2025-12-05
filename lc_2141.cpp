#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int s, n;
    cin >> s >> n;

    vector<int> v(s);
    for(int i = 0; i < s; i++)
        cin >> v[i];

    sort(v.begin(), v.end());
    long long total = accumulate(v.begin(), v.end(), 0LL);

    for(int i = s - 1; i >= 0; i--) {
        if (v[i] <= total / n) break;
        total -= v[i];
        n--;
    }

    cout << total / n << '\n';
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