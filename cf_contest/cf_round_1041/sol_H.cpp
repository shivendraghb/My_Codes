#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int n, m;
vector<pair<int, int>> edges;
vector<int> degree;
int max_edges;

/**
 * @brief Recursive backtracking function to find the maximum number of edges.
 * * This function explores all possible subsets of edges to find the one that
 * forms a "candy" subgraph with the maximum number of edges.
 * * @param edge_index The index of the current edge being considered.
 * @param current_edges The number of edges selected so far in the current path.
 */
void solve(int edge_index, int current_edges) {
    if (current_edges + (m - edge_index) <= max_edges) {
        return;
    }

    if (edge_index == m) {
        max_edges = max(max_edges, current_edges);
        return;
    }

    solve(edge_index + 1, current_edges);

    int u = edges[edge_index].first;
    int v = edges[edge_index].second;

    if (degree[u] < 2 && degree[v] < 2) {
        degree[u]++;
        degree[v]++;
        solve(edge_index + 1, current_edges + 1);

        degree[u]--;
        degree[v]--;
    }
}

/**
 * @brief Main function to run a single test case.
 */
void run_case() {
    cin >> n >> m;
    edges.resize(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].first >> edges[i].second;
        edges[i].first--;
        edges[i].second--;
    }

    max_edges = 0;
    degree.assign(n, 0);

    solve(0, 0);
    cout << max_edges << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        run_case();
    }
    return 0;
}
