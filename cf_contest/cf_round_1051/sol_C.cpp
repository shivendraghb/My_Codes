#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    vector<int> in_degree(n + 1, 0);

    for (int i = 0; i < n - 1; ++i) {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        if (x > y) {
            adj[v].push_back(u);
            in_degree[u]++;
        } else if (y > x) {
            adj[u].push_back(v);
            in_degree[v]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> p(n + 1);
    int current_val = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        p[u] = current_val;
        current_val++;

        for (int v : adj[u]) {
            in_degree[v]--;
            if (in_degree[v] == 0) {
                q.push(v);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << p[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
