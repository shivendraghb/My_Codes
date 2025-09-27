#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    string s = "";
    cin >> s;

    vector<string> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    // int cnt = 0;
    // for(const string& t : v) {
    //     int i = 0, j = 0;
    //     while(i < s.size() && j < t.size()) {
    //         if(s[i] == t[j]) j++;

    //         i++;
    //     }

    //     if(j == t.size()) cnt++;
    // }

    // cout << cnt << '\n';
    vector<vector<int>> pos(26);
    for(int i = 0; i < s.size(); i++)
        pos[s[i] - 'a'].push_back(i);

    int cnt = 0;

    for(const string& t : v) {
        int prev = -1;
        bool ok = true;

        for(char c : t) {
            auto& vec = pos[c - 'a'];
            if(vec.empty()) {
                ok = false;
                break;
            }

            auto it = upper_bound(vec.begin(), vec.end(), prev);
            if(it == vec.end()) {
                ok = false;
                break;
            }

            prev = *it;
        }

        if(ok) cnt++;
    }
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
