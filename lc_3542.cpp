#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    vector<int> r;
    int res = 0;

    for(int i : v) {
        while(!r.empty() && r.back() > i)
            r.pop_back();

        if(i == 0)
            continue;

        if(r.empty() || r.back() < i) {
            res++;
            r.push_back(i);
        }
    }

    cout << res << '\n';
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