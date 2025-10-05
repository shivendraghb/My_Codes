#include<bits/stdc++.h>
using namespace std;

// #define int long long

vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dfs(int i, int j, vector<vector<int>>& v, vector<vector<bool>>& visited) {
    int m = v.size(), n = v[0].size();
    visited[i][j] = true;

    for(auto& d : dir) {
        int x = i + d[0], y = j + d[1];

        if(x < 0 || x >= m || y < 0 || y >= n) continue;
        if(visited[x][y]) continue;
        if(v[x][y] < v[i][j]) continue;

        dfs(x, y, v, visited);
    }
}

void solve() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> v(m, vector<int>(n));
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> v[i][j];

    vector<vector<bool>> pacific(m, vector<bool>(n, false)); 
    vector<vector<bool>> atlantic(m, vector<bool>(n, false)); 

    for(int i = 0; i < n; i++) dfs(0, i, v, pacific);
    for(int j = 0; j < m; j++) dfs(j, 0, v, pacific);

    for(int i = 0; i < n; i++) dfs(m - 1, i, v, atlantic);
    for(int j = 0; j < m; j++) dfs(j, n - 1, v, atlantic);

    vector<vector<int>> r;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(pacific[i][j] && atlantic[i][j])
                r.push_back({i, j});

    for(const auto& row : r) {
        for(const auto& ele : row) {
            cout << ele << " ";
        }
        cout << '\n';
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