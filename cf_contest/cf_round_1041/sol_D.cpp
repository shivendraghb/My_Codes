#include <iostream>
#include <vector>
#include <numeric>
#include <queue>

using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;

vector<int> adj[MAXN];
int color[MAXN];
long long fact[MAXN];

void precompute_factorials(int n) {
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
        color[i] = 0;
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (m > n - 1) {
        cout << 0 << endl;
        return;
    }

    long long count1 = 0, count2 = 0;
    bool is_bipartite = true;

    queue<int> q;
    q.push(1);
    color[1] = 1;
    count1++;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (color[v] == 0) {
                color[v] = (color[u] == 1) ? 2 : 1;
                if (color[v] == 1) count1++;
                else count2++;
                q.push(v);
            } else if (color[v] == color[u]) {
                is_bipartite = false;
                break;
            }
        }
        if (!is_bipartite) break;
    }

    if (!is_bipartite) {
        cout << 0 << endl;
        return;
    }

    if (count1 + count2 != n) {
        // This case should not happen for a connected graph, but as a safeguard.
        cout << 0 << endl;
        return;
    }

    long long ans = (2 * fact[count1]) % MOD;
    ans = (ans * fact[count2]) % MOD;

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute_factorials(200005);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

