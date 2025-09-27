#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    string s;
    cin >> s;

    int odd_idx = -1;

    for(int i = s.size() - 1; i >= 0; i--) {
        if(s[i] % 2 == 1) {
            odd_idx = i;
            break;
        }
    }

    if(odd_idx > -1)
        cout << s.substr(0, odd_idx + 1) << '\n';
    else
        cout << "" << '\n';
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
