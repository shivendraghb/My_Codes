#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    string s;
    cin >> s;

    int n = s.size();

    for(int i = 0; i < n - 1; i++) {
        int a = s[i] - '0';
        int b = s[i + 1] - '0';
        if(a % 2 == b % 2 && a > b) {
            swap(s[i], s[i + 1]);
            break;
        }
    }

    cout << s << '\n';
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