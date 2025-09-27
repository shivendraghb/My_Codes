#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

const int INF = 1e9;

std::vector<int> adj[200005];
int parent[200005];
int depth[200005];
bool is_leaf[200005];
int n, k;
std::vector<int> dp[200005];

void dfs_depth(int u, int d) {
    depth[u] = d;
    is_leaf[u] = true;
    for (int v : adj[u]) {
        is_leaf[u] = false;
        dfs_depth(v, d + 1);
    }
}

void solve() {
    std::cin >> n >> k;

    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
        dp[i].clear();
        is_leaf[i] = false;
    }

    for (int i = 2; i <= n; ++i) {
        std::cin >> parent[i];
        adj[parent[i]].push_back(i);
    }

    dfs_depth(1, 1);

    std::vector<int> post_order;
    std::vector<int> s;
    s.push_back(1);
    while (!s.empty()) {
        int u = s.back();
        s.pop_back();
        post_order.push_back(u);
        for (int v : adj[u]) {
            s.push_back(v);
        }
    }
    std::reverse(post_order.begin(), post_order.end());

    for (int u : post_order) {
        if (is_leaf[u]) {
            dp[u].assign(depth[u] + 1, INF);
            for (int i = 0; i <= depth[u]; ++i) {
                dp[u][i] = std::min(i, depth[u] - i);
            }
        } else {
            std::vector<int> merged_dp;
            int max_depth = 0;
            for (int v : adj[u]) {
                max_depth = std::max(max_depth, (int)dp[v].size());
            }

            merged_dp = dp[adj[u][0]];
            for (size_t i = 1; i < adj[u].size(); ++i) {
                int child = adj[u][i];
                std::vector<int> new_merged_dp(max_depth + 1, INF);
                for (size_t j = 0; j < merged_dp.size(); ++j) {
                    for (size_t l = 0; l < dp[child].size(); ++l) {
                        if (merged_dp[j] != INF && dp[child][l] != INF) {
                            new_merged_dp[std::min(j, l)] = std::min(new_merged_dp[std::min(j, l)], merged_dp[j] + dp[child][l]);
                        }
                    }
                }
                merged_dp = new_merged_dp;
            }

            dp[u].assign(depth[u] + 1, INF);
            for (size_t i = 0; i < merged_dp.size(); ++i) {
                if (merged_dp[i] != INF) {
                    // u is 0
                    if (i + 1 <= depth[u]) {
                        dp[u][i + 1] = std::min(dp[u][i + 1], merged_dp[i] + 1);
                    }
                    // u is 1
                    dp[u][i] = std::min(dp[u][i], merged_dp[i]);
                }
            }
        }
    }

    int max_beauty = 0;
    for (size_t i = 0; i < dp[1].size(); ++i) {
        if (dp[1][i] <= k) {
            max_beauty = std::max(max_beauty, (int)i);
        }
    }
    std::cout << max_beauty << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
