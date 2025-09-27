#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> f(n);
    for(int i = 0; i < n; i++)
        cin >> f[i];

    vector<int> b(n);
    for(int i = 0; i < n; i++)
        cin >> b[i];

    vector<bool> seen(n, false);

    int r = 0;
    for(int i = 0; i < n; i++) {
        int j = 0;
        while(j < n) {
            if(b[j++] >= f[i] && !seen[j - 1]) {
                seen[j - 1] = true;
                break;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        if(!seen[i])
            r++;
    }

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
