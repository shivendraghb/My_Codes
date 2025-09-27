#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    string s = to_string(n);

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '6') {
            s[i] = '9';
            break;
        }
    }

    cout << stoi(s) << '\n';
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
