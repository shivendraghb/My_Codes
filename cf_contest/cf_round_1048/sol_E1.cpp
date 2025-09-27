#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> p(n + 1), depth(n + 1, 0), deg(n + 1, 0);
    vector<vector<int>> adj(n + 1);

    // Read parents and build adjacency list
    for (int i = 2; i <= n; i++) {
        cin >> p[i];
        adj[p[i]].push_back(i);
        deg[p[i]]++;
    }

    // Compute depths using BFS
    queue<int> q;
    q.push(1);
    depth[1] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            depth[v] = depth[u] + 1;
            q.push(v);
        }
    }

    // Find leaves and minimum leaf depth
    vector<int> leaves;
    int min_depth = n;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) {
            leaves.push_back(i);
            min_depth = min(min_depth, depth[i]);
        }
    }

    // Find short leaves (at min_depth)
    vector<int> short_leaves;
    for (int leaf : leaves) {
        if (depth[leaf] == min_depth) {
            short_leaves.push_back(leaf);
        }
    }

    // Compute layers: unique vertices at each depth on short paths
    vector<set<int>> layers(min_depth + 1);
    for (int leaf : short_leaves) {
        int u = leaf;
        int cur_d = min_depth;
        while (true) {
            layers[cur_d].insert(u);
            if (u == 1) break;
            u = p[u];
            cur_d--;
        }
    }

    // g[d] = size of layer d
    vector<int> g(min_depth + 1);
    for (int d = 0; d <= min_depth; d++) {
        g[d] = layers[d].size();
    }

    // Incremental bitset for subset sums
    const int MAX_SUM = 1001;
    bitset<MAX_SUM> bs;
    bs[0] = 1;
    int current_u = 0;
    int ans = 0;  // Will be at least 1, but set to max possible l
    for (int d = 0; d <= min_depth; d++) {
        bs |= (bs << g[d]);
        current_u += g[d];
        int free_vertices = n - current_u;
        int low = max(0, k - free_vertices);
        int high = min(k, MAX_SUM - 1);  // Bound high
        bool possible = false;
        for (int s = low; s <= high; ++s) {
            if (bs[s]) {
                possible = true;
                break;
            }
        }
        if (possible) {
            ans = d + 1;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
