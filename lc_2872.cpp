#include<bits/stdc++.h>
using namespace std;

// #define int long long

void solve() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> e(n - 1, vector<int>(2));
    for(int i = 0; i < n - 1; i++)
        for(int j = 0; j < 2; j++)
            cin >> e[i][j];

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    vector<vector<int>> G(n);
    for(auto edge : e) {
        G[edge[0]].push_back(edge[1]);
        G[edge[1]].push_back(edge[0]);
    }

    stack<int> S;
    vector<int> parent(n);

    auto DFS = [&](int u, int p, auto &&DFS) -> void {
        parent[u] = p;
        S.push(u);
        for(auto v : G[u]) {
            if(v == p)  
                continue;
            DFS(v, u, DFS);
        }
    };

    DFS(0, -1, DFS);
    vector<long long> sum(n);
    for(int i = 0; i < n; i++)
        sum[i] = v[i];

    int ans = 0;
    while(!S.empty()) {
        int u = S.top();
        S.pop();
        if(sum[u] % k == 0)
            ans += 1;
        else
            sum[parent[u]] += sum[u];
    }

    cout << ans << '\n';
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