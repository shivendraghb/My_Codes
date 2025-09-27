#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    string v1;
    cin >> v1;
    string v2;
    cin >> v2;

    int n1 = v1.size(), n2 = v2.size();
    int x1 = 0, x2 = 0;
    for(int i = 0, j = 0; i < n1 || j < n2; i++, j++) {
        while(i < n1 && v1[i] != '.')
            x1 = 10*x1 + (v1[i++] - '0');

        while(j < n2 && v2[j] != '.')
            x2 = 10*x2 + (v2[j++] - '0');

        if(x1 < x2) {cout << -1 << '\n';return;}
        else if(x1 > x2) {cout << 1 << '\n';return;}
        x1 = 0;
        x2 = 0;
    }
    cout << 0 << '\n';
    return;
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
