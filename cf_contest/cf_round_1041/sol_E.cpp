#include <iostream>
#include <vector>
#include <numeric>
#include <map>
#include <queue>
#include <algorithm> // Required for std::remove
#include <functional> // Required for std::function

using namespace std;

const int MAXN = 2e5 + 5;

vector<int> adj[MAXN];
long long w[MAXN];
int c[MAXN];
int final_colors[MAXN];

long long min_cost;

// This DFS function performs a post-order traversal to collect color information
// and make coloring decisions from the bottom up.
map<int, int> dfs(int u, int p) {
    // This map will store the colors found in the subtree rooted at u
    // and how many of u's children's subtrees they appeared in.
    map<int, int> u_colors;

    // First, process all children
    for (int v : adj[u]) {
        if (v == p) continue;
        map<int, int> child_colors = dfs(v, u);
        // Merge the child's color map into the current map
        for (auto const& [color, count] : child_colors) {
            u_colors[color]++;
        }
    }

    // After processing children, check for problematic colors (clashes)
    map<int, int> problematic_colors_count;
    for (auto const& [color, count] : u_colors) {
        if (count >= 2) {
            problematic_colors_count[color]++;
        }
    }

    // Decide on the color for vertex u
    if (c[u] != 0) { // If color is pre-determined
        final_colors[u] = c[u];
        // Check if u becomes cutie due to a clash with a different color
        bool cutie = false;
        for (auto const& [color, count] : problematic_colors_count) {
            if (color != c[u]) {
                cutie = true;
                break;
            }
        }
        if (cutie) {
            min_cost += w[u];
        }
    } else { // If color is missing
        if (problematic_colors_count.size() >= 2) {
            // More than one conflicting color, so u will be a cutie regardless of its color choice.
            min_cost += w[u];
            // Pick an arbitrary color to fill in, e.g., the first one from the problematic set.
            final_colors[u] = problematic_colors_count.begin()->first;
        } else if (problematic_colors_count.size() == 1) {
            // Exactly one conflicting color, we can set u's color to this color to prevent it from being a cutie.
            final_colors[u] = problematic_colors_count.begin()->first;
        } else {
            // No conflicting colors, so u will not be a cutie.
            // We can pick any color, e.g., 1.
            final_colors[u] = 1;
        }
    }

    // Include the final color of u itself in the map returned to the parent
    map<int, int> result_colors;
    for (auto const& [color, count] : u_colors) {
        result_colors[color] = 1;
    }
    result_colors[final_colors[u]] = 1;

    return result_colors;
}

void solve() {
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
    }

    for (int i = 1; i <= n; ++i) cin >> w[i];
    for (int i = 1; i <= n; ++i) cin >> c[i];

    vector<pair<int, int>> edges;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.push_back({u, v});
    }

    // Set up parent-child relationships for a rooted tree (root is 1)
    vector<int> q;
    q.push_back(1);
    vector<bool> visited(n + 1, false);
    visited[1] = true;
    int head = 0;

    // Perform BFS to create a parent-child structure from the unrooted tree
    // and remove parent edges from adjacency lists to simplify DFS.
    vector<int> new_adj[MAXN];
    vector<int> parent(n + 1, 0);

    while(head < q.size()){
        int u = q[head++];
        for(int v : adj[u]){
            if(!visited[v]){
                visited[v] = true;
                parent[v] = u;
                new_adj[u].push_back(v);
                q.push_back(v);
            }
        }
    }
    for(int i = 1; i <= n; ++i) adj[i] = new_adj[i];


    min_cost = 0;

    dfs(1, 0);

    cout << min_cost << endl;
    for (int i = 1; i <= n; ++i) {
        cout << final_colors[i] << (i == n ? "" : " ");
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
// #include <bits/stdc++.h>
// using namespace std;

// const int MOD = 1e9 + 7;
// const int MAXN = 2e5 + 5;

// vector<int> tree[MAXN];
// int w[MAXN], c[MAXN], res_c[MAXN];
// unordered_map<int, int> color_count[MAXN];
// bool cutie[MAXN];

// void dfs(int u, int p) {
//     color_count[u][res_c[u]]++;
//     for (int v : tree[u]) {
//         if (v == p) continue;
//         dfs(v, u);
//         for (auto& [col, cnt] : color_count[v]) {
//             if (col != res_c[u] && cnt + color_count[u][col] >= 2) {
//                 cutie[u] = true;
//             }
//             color_count[u][col] += cnt;
//         }
//     }
// }

// void solve() {
//     int n, k;
//     cin >> n >> k;

//     for (int i = 0; i <= n; ++i) {
//         tree[i].clear();
//         color_count[i].clear();
//         cutie[i] = false;
//     }

//     for (int i = 1; i <= n; ++i)
//         cin >> w[i];

//     for (int i = 1; i <= n; ++i)
//         cin >> c[i];

//     for (int i = 1; i < n; ++i) {
//         int u, v;
//         cin >> u >> v;
//         tree[u].push_back(v);
//         tree[v].push_back(u);
//     }

//     // Assign missing colors (greedily with any valid color)
//     for (int i = 1; i <= n; ++i) {
//         res_c[i] = c[i];
//     }

//     function<void(int, int)> assign_colors = [&](int u, int p) {
//         set<int> banned;
//         if (c[u]) return;
//         if (p && res_c[p]) banned.insert(res_c[p]);
//         for (int v : tree[u]) {
//             if (v == p) continue;
//             if (res_c[v]) banned.insert(res_c[v]);
//         }
//         for (int color = 1; color <= k; ++color) {
//             if (!banned.count(color)) {
//                 res_c[u] = color;
//                 break;
//             }
//         }
//         if (res_c[u] == 0) res_c[u] = 1; // fallback
//         for (int v : tree[u]) {
//             if (v != p)
//                 assign_colors(v, u);
//         }
//     };
//     assign_colors(1, 0);

//     dfs(1, 0);

//     long long cost = 0;
//     for (int i = 1; i <= n; ++i) {
//         if (cutie[i])
//             cost += w[i];
//     }

//     cout << cost << '\n';
//     for (int i = 1; i <= n; ++i) {
//         cout << res_c[i] << ' ';
//     }
//     cout << '\n';
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     cin >> t;
//     while (t--) {
//         solve();
//     }

//     return 0;
// }
