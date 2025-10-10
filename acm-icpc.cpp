#include<bits/stdc++.h>
using namespace std;

// #define int long long

void solve() {
    int m, n;
    cin >> m >> n;

    vector<string> v(m);
    for(int i = 0; i < m; i++)
        cin >> v[i];

    vector<bitset<500>> masks(m);
    for(int i = 0; i < m; i++)
        masks[i] = bitset<500>(v[i]);

    int mt = 0;
    int cnt = 0;

    for(int i = 0; i < m; i++) {
        for(int j = i + 1; j < m; j++) {
            int t = (masks[i] | masks[j]).count();
            if(t > mt) {
                mt = t;
                cnt = 1;
            } else if(t == mt)
                cnt++;
        }
    }

    cout << mt << " " << cnt << '\n';
}

int32_t main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}