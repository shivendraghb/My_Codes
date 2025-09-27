#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int m, n;

    cin >> m >> n;

    vector<vector<int>> v(m, vector<int>(n));
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> v[i][j];

    vector<int> res(m * n);

    int r = 0, c = 0;
    for(int i = 0; i < m * n; i++) {
        res[i] = v[r][c];
        if((r + c) % 2 == 0) {
            if(c == n - 1)
                r++;
            else if(r == 0)
                c++;
            else {
                r--;
                c++;
            }
        }
        else {
            if(r == m - 1)
                c++;
            else if(c == 0)
                r++;
            else {
                r++;
                c--;
            }
        }
    }

    for(int i = 0; i < m * n; i++)
        cout << res[i] << " ";

    cout << '\n';
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
