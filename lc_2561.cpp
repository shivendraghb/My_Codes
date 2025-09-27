#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> b1(n), b2(n);
    map<int, int> freq;

    for(int& x : b1) {
        cin >> x;
        freq[x]++;
    }

    for(int& x : b2) {
        cin >> x;
        freq[x]--;
    }

    for(auto &[val, cnt] : freq) {
        if (cnt % 2 != 0) {
            cout << -1 << '\n';
            return;
        }
    }

    int gl_min = min(*min_element(b1.begin(), b1.end()), *min_element(b2.begin(), b2.end()));

    vector<int> extra;

    for(auto &[val, cnt] : freq) {
        int excess = abs(cnt) / 2;
        for(int i = 0; i < excess; i++)
            extra.push_back(val);
    }

    sort(extra.begin(), extra.end());

    int cost = 0;
    for(int i = 0; i < extra.size() / 2; i++)
        cost += min(extra[i], 2 * gl_min);

    cout << cost << '\n';
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
