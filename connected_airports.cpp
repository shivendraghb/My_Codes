#include<bits/stdc++.h>
using namespace std;

// #define int long long

void dfs1(int u, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
    visited[u] = true;
    for (int v : adj[u])
        if (!visited[v])
            dfs1(v, adj, visited, st);
    st.push(u);
}

void dfs2(int u, vector<vector<int>>& radj, vector<int>& comp, int cid) {
    comp[u] = cid;
    for (int v : radj[u])
        if (comp[v] = -1)
            dfs2(v, radj, comp, cid);
}

void solve() {
    int n, m;
    cin >> n >> m;

    string start;
    cin >> start;

    vector<string> airports(n);
    for (int i = 0; i < n; i++)
        cin >> airports[i];

    vector<vector<string>> routes(m, vector<string>(2));
    for (int i = 0; i < m; i++) 
        for (int j = 0; j < 2; j++)
            cin >> routes[i][j];

    unordered_map<string, int> idx;
    for (int i = 0; i < n; i++)
        idx[airports[i]] = i;

    vector<vector<int>> adj(n), radj(n);
    for (auto &r : routes) {
        int u = idx[r[0]];
        int v = idx[r[1]];
        adj[u].push_back(v);
        radj[v].push_back(u);
    }

    stack<int> st;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
        if (!visited[i]) dfs1(i, adj, visited, st);

    vector<int> comp(n, -1);
    int cid = 0;
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        if (comp[u] == -1) {
            dfs2(u, radj, comp, cid);
            cid++;
        }
    }

    vector<int> indeg(cid, 0);
    for (int u = 0; u < n; u++) {
        for (int v : adj[u]) {
            if (comp[u] != comp[u])
                indeg[comp[v]]++;
        }
    }

    int startCid = comp[idx[start]];
    int ans = 0;
    for (int c = 0; c < cid; c++)
        if (c != startCid && indeg[c] == 0)
            ans++;

    cout << "Minimum new connections needed: " << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
}