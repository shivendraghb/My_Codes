#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    string s = "";
    cin >> s;

    int n; cin >> n;

    vector<string> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    int cnt = 0;

    for(const string& t : v) {
        int i = 0, j = 0;
        while(i < s.size() && j < t.size()) {
            if(s[i] == t[j]) j++;
            i++;
        }
        if(j == t.size()) cnt++;
    }

    cout << cnt << '\n';
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
