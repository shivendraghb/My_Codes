#include<bits/stdc++.h>
using namespace std;

// #define int long long

int freq[26];

void solve() {
    string s;
    cin >> s;

    // static int freq[26];
    int vow = 0, con = 0;
    for(char c : s) {
        int i = c - 'a';
        freq[i]++;
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            vow = max(vow, freq[i]);
        else
            con = max(con, freq[i]);
    }

    cout << vow + con << '\n';
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
