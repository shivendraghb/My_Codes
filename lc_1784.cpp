#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    string s;
    cin >> s;

    for (int i = 1; i < s.size(); i++) {
        if (s[i] == '1' && s[i-1] == '0') {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";

    /*
        cout << (s.find("01") == string::npos ? "YES" : "NO") << '\n';
    */
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}