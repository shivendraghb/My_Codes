#include <bits/stdc++.h>
using namespace std;

// iterative Kosaraju (handles large graphs safely)
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n; cin >> n;
        string s; cin >> s;
        // list zero positions
        vector<int> zeros;
        zeros.reserve(n);
        for (int i = 0; i < n; ++i) if (s[i] == '0') zeros.push_back(i);
        int m = (int)zeros.size();
        if (m == 0) { // no rabbits -> always valid
            cout << "YES\n";
            continue;
        }

        auto id = vector<int>(n, -1);
        for (int i = 0; i < m; ++i) id[zeros[i]] = i;

        int N = 2 * m; // node 2*v => X_v == true (look right), 2*v+1 => X_v == false (look left)
        vector<vector<int>> g(N), gr(N);
        auto add_imp = [&](int a, int b){
            g[a].push_back(b);
            gr[b].push_back(a);
        };

        // Build implications
        for (int idx = 0; idx < m; ++idx) {
            int pos = zeros[idx];
            int v_true = 2*idx;
            int v_false = 2*idx + 1;

            // Check left neighbor (pos-1). If it's '1', looking left (X=0) would try to jump.
            if (pos-1 >= 0 && s[pos-1] == '1') {
                // If pos-2 is zero, then (not X_pos) => X_{pos-2}
                if (pos-2 >= 0 && s[pos-2] == '0') {
                    int u = id[pos-2];
                    add_imp(v_false, 2*u); // not X_pos => X_u
                } else {
                    // (not X_pos) impossible => force X_pos = true
                    add_imp(v_false, v_true);
                }
            }
            // Check right neighbor (pos+1). If it's '1', looking right (X=1) would try to jump.
            if (pos+1 < n && s[pos+1] == '1') {
                // If pos+2 is zero, then X_pos => not X_{pos+2}
                if (pos+2 < n && s[pos+2] == '0') {
                    int w = id[pos+2];
                    add_imp(v_true, 2*w + 1); // X_pos => not X_w
                } else {
                    // X_pos impossible => force X_pos = false
                    add_imp(v_true, v_false);
                }
            }
        }

        // Kosaraju: iterative first pass to get order
        vector<char> used(N, 0);
        vector<int> order; order.reserve(N);
        vector<int> it(N, 0);
        for (int start = 0; start < N; ++start) {
            if (used[start]) continue;
            // iterative DFS
            stack<int> st;
            st.push(start);
            while (!st.empty()) {
                int v = st.top();
                if (!used[v]) used[v] = 1;
                bool pushed = false;
                while (it[v] < (int)g[v].size()) {
                    int to = g[v][it[v]++];
                    if (!used[to]) {
                        st.push(to);
                        pushed = true;
                        break;
                    }
                }
                if (!pushed) {
                    st.pop();
                    order.push_back(v);
                }
            }
        }

        // second pass: assign components on reversed graph
        vector<int> comp(N, -1);
        int cid = 0;
        vector<int> it2(N, 0);
        for (int i = (int)order.size() - 1; i >= 0; --i) {
            int v0 = order[i];
            if (comp[v0] != -1) continue;
            // iterative DFS on gr
            stack<int> st;
            st.push(v0);
            comp[v0] = cid;
            while (!st.empty()) {
                int v = st.top(); st.pop();
                for (int to : gr[v]) {
                    if (comp[to] == -1) {
                        comp[to] = cid;
                        st.push(to);
                    }
                }
            }
            ++cid;
        }

        // check satisfiability: for each variable, true and false must be in different components
        bool ok = true;
        for (int i = 0; i < m; ++i) {
            if (comp[2*i] == comp[2*i + 1]) { ok = false; break; }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}