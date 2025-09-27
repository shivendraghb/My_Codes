#include <bits/stdc++.h>
using namespace std;

struct BFSResult {
    int farthest;
    vector<int> dist, parent;
};

BFSResult bfs_far(const vector<vector<int>>& g, int src) {
    int n = (int)g.size() - 1;
    vector<int> dist(n + 1, -1), parent(n + 1, -1);
    queue<int> q;
    q.push(src);
    dist[src] = 0;
    int far = src;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (dist[u] > dist[far]) far = u;
        for (int v : g[u]) if (dist[v] == -1) {
            dist[v] = dist[u] + 1;
            parent[v] = u;
            q.push(v);
        }
    }
    return {far, dist, parent};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> g(n + 1);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        // Step 1: Find diameter ends
        auto res1 = bfs_far(g, 1);
        auto res2 = bfs_far(g, res1.farthest);

        int A = res1.farthest;
        int B = res2.farthest;
        vector<int> parentA = res2.parent;

        // Step 2: Recover path from A to B
        vector<int> path;
        for (int cur = B; cur != -1; cur = parentA[cur]) {
            path.push_back(cur);
            if (cur == A) break;
        }
        reverse(path.begin(), path.end());

        int L = (int)path.size() - 1; // diameter length in edges
        if (L <= 2) {
            cout << 0 << "\n";
            continue;
        }

        // Step 3: Identify center(s)
        vector<int> centers;
        if (L % 2 == 0) {
            centers.push_back(path[L / 2]);
        } else {
            centers.push_back(path[L / 2]);
            centers.push_back(path[L / 2 + 1]);
        }

        // Allowed radius after minimization
        int allowed_depth = L / 2;

        auto count_ops = [&](int root) -> int {
        int ops = 0;
        vector<int> dist(n + 1, -1);
        dist[root] = 0;

        for (int nei : g[root]) {
            // BFS/DFS from this neighbor without crossing root
            queue<int> q;
            q.push(nei);
            dist[nei] = 1;
            int maxd = 1;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                maxd = max(maxd, dist[u]);
                for (int v : g[u]) if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
            if (maxd > allowed_depth) ops++;
        }
        return ops;
    };


        int ans = INT_MAX;
        for (int c : centers) {
            ans = min(ans, count_ops(c));
        }
        cout << ans << "\n";
    }
    return 0;
}
