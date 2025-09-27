#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, k;
    cin >> n >> k;

    int r_q, c_q;
    cin >> r_q >> c_q;

    vector<vector<int>> obstacles(k, vector<int>(2));
    for(int i = 0; i < k; i++)
        for(int j = 0; j < 2; j++)
            cin >> obstacles[i][j];

    set<pair<int, int>> obs;
    for(auto &v : obstacles)
        obs.insert({v[0], v[1]});

    vector<pair<int, int>> directions = {
        {-1, 0}, {1, 0}, //up and down
        {0, -1}, {0, 1}, //left and right
        {-1, -1}, {-1, 1}, //top left and top right
        {1, -1}, {1, 1}, //bottom left and bottom right
    };

    int cnt = 0;

    for(auto &dir : directions) {
        int r = r_q + dir.first;
        int c = c_q + dir.second;

        while(r >= 1 && r <= n && c >= 1 && c <= n && obs.find({r, c}) == obs.end()) {
            cnt++;
            r += dir.first;
            c += dir.second;
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
