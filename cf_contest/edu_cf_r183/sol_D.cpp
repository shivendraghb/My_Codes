#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tt;
    if (!(cin >> tt)) return 0;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        int S = n * (n - 1) / 2;
        if (k > S) { // impossible
            cout << 0 << '\n';
            continue;
        }
        int T = S - k; // target sum of C(L_i,2)
 
        // dp[len][t] = reachable?
        vector<vector<char>> dp(n + 1, vector<char>(S + 1, false));
        // used[len][t] = last block size s used to reach (len,t), -1 if unreachable
        vector<vector<int>> used(n + 1, vector<int>(S + 1, -1));
        vector<vector<int>> prev_t(n + 1, vector<int>(S + 1, -1));
        
        dp[0][0] = 1;
        used[0][0] = 0; // sentinel
 
        bool found = false;
        for (int len = 0; len <= n; ++len) {
            for (int t = 0; t <= S; ++t) {
                if (!dp[len][t]) continue;
                if (len == n) {
                    if (t == T) { found = true; break; }
                    continue;
                }
                for (int s = 1; s <= n - len; ++s) {
                    int add = s * (s - 1) / 2;
                    int nt = t + add;
                    if (nt > S) continue;
                    if (!dp[len + s][nt]) {
                        dp[len + s][nt] = 1;
                        used[len + s][nt] = s;
                        prev_t[len + s][nt] = t;
                    }
                }
            }
            if (dp[n][T]) { found = true; break; }
        }
        
        if (!dp[n][T]) {
            cout << 0 << '\n';
            continue;
        }
 
        // Reconstruct block sizes
        vector<int> blocks;
        int cur_len = n, cur_t = T;
        while (cur_len > 0) {
            int s = used[cur_len][cur_t];
            // safety check
            if (s <= 0) { blocks.clear(); break; }
            blocks.push_back(s);
            int pt = prev_t[cur_len][cur_t];
            cur_len -= s;
            cur_t = pt;
        }
        if (blocks.empty()) {
            cout << 0 << '\n';
            continue;
        }
        reverse(blocks.begin(), blocks.end()); // blocks in left-to-right order
 
        // Build permutation: assign largest numbers to the first block, next largest to next block, ...
        vector<int> perm;
        perm.reserve(n);
        int cur = n;
        for (int s : blocks) {
            int start = cur - s + 1;
            for (int x = start; x <= cur; ++x) perm.push_back(x); // ascending within block
            cur -= s;
        }
 
        // Output
        for (int i = 0; i < n; ++i) {
            if (i) cout << ' ';
            cout << perm[i];
        }
        cout << '\n';
    }
 
    return 0;
}