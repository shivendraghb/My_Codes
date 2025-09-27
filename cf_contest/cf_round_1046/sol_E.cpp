#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        long long V;
        cin >> n >> m >> V;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<vector<int>> g(n);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            --u; --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<int> dist(n, -1);
        bool ok = true;
        int free_components = 0;

        for (int i = 0; i < n; i++) {
            if (dist[i] == -1) {
                dist[i] = 0;
                stack<int> st;
                st.push(i);
                while (!st.empty() && ok) {
                    int u = st.top(); st.pop();
                    for (int v : g[u]) {
                        if (dist[v] == -1) {
                            dist[v] = dist[u] ^ 1;
                            st.push(v);
                        } else {
                            if ((dist[v] ^ dist[u]) != 1) {
                                ok = false;
                                break;
                            }
                        }
                    }
                }
                if (!ok) break;

                bool comp_free = true;
                for (int j = 0; j < n; j++) {
                    if (dist[j] != -1 && a[j] != -1) {
                        comp_free = false;
                        break;
                    }
                }
                if (comp_free) free_components++;
            }
        }

        if (!ok) {
            cout << 0 << "\n";
        } else {
            auto modpow = [&](long long base, int exp) {
                long long res = 1;
                base %= MOD;
                while (exp > 0) {
                    if (exp & 1) res = res * base % MOD;
                    base = base * base % MOD;
                    exp >>= 1;
                }
                return res;
            };
            cout << modpow(V, free_components) << "\n";
        }
    }
    return 0;
}
