#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj(n + 1);

        for(int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int b = -1;
        for(int i = 1; i <= n; i++) {
            if((int)adj[i].size() >= 3) {
                b = i;
                break;
            }
        }

        if(b == -1)
            cout << -1 << '\n';
        else {
            int a = adj[b][0];
            int c = adj[b][1];
            cout << a << " " << b << " " << c << '\n';
        }
    }

    return 0;
}
