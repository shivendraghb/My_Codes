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
        
    if(m <= 2 || n <= 2) {cout << 0 << '\n'; return;}

    vector<vector<bool>> visited(m, vector<bool>(n, false));
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    //push
    for(int i = 0; i < m; i++) {
        pq.push({v[i][0], i, 0});
        pq.push({v[i][n - 1], i, n - 1});
        visited[i][0] = visited[i][n - 1] = true;
    }

    for(int j = 1; j < n - 1; j++) {
        pq.push({v[0][j], 0, j});
        pq.push({v[m - 1][j], m - 1, j});
        visited[0][j] = visited[m - 1][j] = true;
    }

    int water = 0;
    vector<int> dirs = {0,1,0,-1,0};

    while(!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        int h = cur[0], x = cur[1], y = cur[2];

        for(int k = 0; k < 4; k++) {
            int nx = x + dirs[k], ny = y + dirs[k + 1];
            if(nx < 0 || ny < 0 || nx >= m || ny >= n || visited[nx][ny])
                continue;
            visited[nx][ny] = true;

            //trap water if neighbor is lower
            if(v[nx][ny] < h)
                water += h - v[nx][ny];

            pq.push({max(v[nx][ny], h), nx, ny});
        }
    }

    cout << water << '\n';
}

auto init = atexit([](){ ofstream("display_runtime.txt") << "0"; });

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
}