#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() { 
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    long long x, res = 0;
    vector<int> rem(k, 0);
    for(int i = 0; i < n; i++) {
        x = ((v[i] % k) + k) % k;
        rem[x]++;
    }

    while(rem[res % k]--) res++;

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