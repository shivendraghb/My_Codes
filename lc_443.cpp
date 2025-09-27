#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    vector<char> chars(n);
    for(int i = 0; i < n; i++)
        cin >> chars[i];

    int idx = 0;
    for(int i = 0; i < n; i++) {
        int cnt = 0;
        char ch = chars[i];

        while(i < n && chars[i] == ch) {
            i++;
            cnt++;
        }

        if(cnt == 1)
            chars[idx++] = ch;
        else {
            chars[idx++] = ch;
            string str = to_string(cnt);
            for(char c : str)
                chars[idx++] = c;
        }
    }

    chars.resize(idx);

    cout << idx << '\n';
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
