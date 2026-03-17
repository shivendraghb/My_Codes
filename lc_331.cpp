#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    string p;
    cin >> p;

    int s = 1;

    stringstream ss(p);
    string val;

    while(getline(ss, val, ',')) {
        s--;

        if (s < 0) { cout << "false" << '\n'; return; }
        if (val != "#") s += 2;
    }

    cout << (s == 0 ? "true\n" : "false\n");
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