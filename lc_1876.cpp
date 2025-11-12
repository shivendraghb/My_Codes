#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    string s;
    cin >> s;

    unordered_map<int, int> mp;
    int i = 0, j = 0, cnt = 0;

    while(i < s.size() && j < s.size()) {
        mp[s[j]]++;

        if(j - i + 1 < 3)
            j++;
        else if(mp.size() == 3) {
            mp.erase(s[i]);
            cnt++;
            i++;
            j++;
        } else {
            mp[s[i]]--;
            if(mp[s[i]] == 0)
                mp.erase(s[i]);
            i++;
            j++;
        }
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