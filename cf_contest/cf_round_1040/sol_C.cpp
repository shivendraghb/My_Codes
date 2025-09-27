#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;  // cycle
        parent[y] = x;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<tuple<int, int, int>> edges;  // {index, a, b}
        for (int i = 0; i < n; ++i) {
            int a, b;
            cin >> a >> b;
            edges.emplace_back(i + 1, a, b);  // 1-based index
        }

        // Max possible node = 2n (as per constraint)
        DSU dsu(2 * n + 1);

        vector<int> selected;
        for (auto &[idx, u, v] : edges) {
            if (dsu.merge(u, v)) {
                selected.push_back(idx);  // add edge to forest
            }
        }

        cout << selected.size() << '\n';
        for (int i : selected) cout << i << ' ';
        cout << '\n';
    }

    return 0;
}
