#include<bits/stdc++.h>
using namespace std;

#define int long long

bool check(string s, int l, int h) {
    while(l < h) {
        if(s[l] != s[h]) return false;
        l++;
        h--;
    }

    return true;
}

void solve() {
    string s;
    cin >> s;

    int n = s.size();
    int l = 0, h = n - 1;

    while(l < h) {
        if(s[l] != s[h]) {
            if(check(s, l + 1, h) || check(s, l, h - 1)) {
                cout << "true" << '\n';
                return;
            } else {
                cout << "false" << '\n';
                return;
            }
        }
        l++;
        h--;
    }

    cout << "true" << '\n';
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