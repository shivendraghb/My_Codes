#include <bits/stdc++.h>
using namespace std;

#define int long long

struct DSU{
    vector<int> p, r;

    DSU(int n) {
        p.resize(n);
        r.assign(n, 0);
        iota(p.begin(), p.end(), 0);
    }

    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if(a == b) return false;

        if(r[a] < r[b]) swap(a, b);

        p[b] = a;

        if(r[a] == r[b]) r[a]++;

        return true;
    }
};

bool check(int n, vector<vector<int>>& edges, int k, int mid) {
    DSU dsu(n);

    int used = 0, up = 0;

    vector<vector<int>> optional;

    // Mandatory edges
    for(auto &e : edges) {
        int u = e[0], v = e[1], s = e[2], must = e[3];
        
        if(must) {
            if(s < mid) return false;

            if(!dsu.unite(u, v))
                return false;

            used++;
        }
        else
            optional.push_back(e);
    }

    // Optional edges WITHOUT upgrade
    for(auto &e : optional) {
        int u = e[0], v = e[1], s = e[2];
        
        if(s >= mid) {
            if(dsu.unite(u, v))
                used++;
        } 
    }

    // Optional edges with upgrade
    for(auto &e : optional) {
        int u = e[0], v = e[1], s = e[2];

        if(s < mid && 2*s >= mid && up < k) {
            if(dsu.unite(u, v)) {
                up++;
                used++;
            }
        }
    }

    return used == n - 1;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> edges(m, vector<int>(4));

    int mx = 0;

    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2] >> edges[i][3];
        mx = max(mx, edges[i][2]);
    }

    int lo = 1, hi = 2 * mx, ans = -1;

    while(lo <= hi) {
        int mid = (lo + hi) / 2;

        if(check(n, edges, k, mid)) {
            ans = mid;
            lo = mid + 1;
        }
        else
            hi = mid - 1;
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