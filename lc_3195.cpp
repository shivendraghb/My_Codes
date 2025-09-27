#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, m;
    cin >> n >> m;

    // if((n == 1 && m == 1) || n == 1 || m == 1) {
    //     cout << 1 << '\n';
    //     return;
    // }

    vector<vector<int>> v(n, vector<int>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> v[i][j];

    int minR = n + 1;
    int maxR = 0;
    int minC = m + 1;
    int maxC = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(v[i][j] == 1) {
                minR = min(minR, i);
                maxR = max(maxR, i);
                minC = min(minC, j);
                maxC = max(maxC, j);
            }
        }
    }

    if(maxR == -1) {
        cout << 0 << '\n';
        return;
    }

    int h = maxR - minR + 1;
    int w = maxC - minC + 1;

    cout << h * w << '\n';
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
