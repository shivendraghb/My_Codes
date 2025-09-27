#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    vector<string> words(n);
    for(int i = 0; i < n; i++)
        cin >> words[i];

    int cnt[26] = {}, pairs = 0, res = 0;
    vector<int> sizes;

    for(const auto &w : words) {
        for(char ch : w)
            pairs += (++cnt[ch - 'a']) % 2 == 0;
        sizes.push_back(w.size());
    }

    sort(sizes.begin(), sizes.end());
    for(int s : sizes) {
        pairs -= s / 2;
        res += pairs >= 0;
    }

    cout << res << '\n';
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
