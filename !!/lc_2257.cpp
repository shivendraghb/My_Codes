#include <bits/stdc++.h>
using namespace std;

#define int long long

class UnionFind {
public:
    vector<int> root, Size;
    int components;

    UnionFind(int n): root(n), Size(n, 1), components(n) {
        iota(root.begin(), root.end(), 0);
    }

    int Find(int x) {
        return x == root[x] ? x : root[x] = Find(root[x]);
    }

    bool Union(int x, int y) {
        x = Find(x); y = Find(y);
        if (x == y) return false;
        if (Size[x] < Size[y]) swap(x, y);
        Size[x] += Size[y];
        root[y] = x;
        components--;
        return true;
    }
};

void solve() {
    int m, n, g, w;
    cin >> m >> n >> g >> w;

    vector<vector<int>> guards(g, vector<int>(2)), walls(w, vector<int>(2));
    for (int i = 0; i < g; i++) cin >> guards[i][0] >> guards[i][1];
    for (int i = 0; i < w; i++) cin >> walls[i][0] >> walls[i][1];

    int N = m * n;
    vector<bool> grid(N, false);
    UnionFind G(N + 1); // last index = N for guarded zone

    auto idx = [&](int r, int c) {
        return r * n + c;
    };

    auto cross = [&](int r, int c, UnionFind &G) {
        // down
        for (int i = r + 1; i < m; i++) {
            if (grid[idx(i, c)]) break;
            G.Union(idx(i, c), N);
        }
        // up
        for (int i = r - 1; i >= 0; i--) {
            if (grid[idx(i, c)]) break;
            G.Union(idx(i, c), N);
        }
        // right
        for (int j = c + 1; j < n; j++) {
            if (grid[idx(r, j)]) break;
            G.Union(idx(r, j), N);
        }
        // left
        for (int j = c - 1; j >= 0; j--) {
            if (grid[idx(r, j)]) break;
            G.Union(idx(r, j), N);
        }
    };

    // Mark walls
    for (auto &p : walls) {
        int r = p[0], c = p[1];
        grid[idx(r, c)] = true;
        G.components--;
    }

    // Mark guards
    for (auto &p : guards) {
        int r = p[0], c = p[1];
        grid[idx(r, c)] = true;
        G.components--;
    }

    // Connect guarded zones
    for (auto &p : guards) {
        int r = p[0], c = p[1];
        cross(r, c, G);
    }

    cout << G.components - 1 << "\n"; // subtract 1 for guard zone
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