#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

const int64 MAX_CELL = 1000000000LL;

struct NextWhiteDSU {
    unordered_map<int64,int64> parent;
    NextWhiteDSU(size_t reserve_size = 0) {
        if (reserve_size) parent.reserve(reserve_size);
    }
    int64 find(int64 x) {
        auto it = parent.find(x);
        if (it == parent.end()) return x;
        return parent[x] = find(it->second);
    }
    void mark_black(int64 x) {
        if (x > MAX_CELL) return;
        if (parent.find(x) == parent.end()) {
            parent[x] = find(x+1);
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        vector<int64> a(m);
        for (int i = 0; i < m; i++) cin >> a[i];

        NextWhiteDSU dsu(m + n + 10);

        // mark initial blacks
        for (auto v : a) dsu.mark_black(v);

        set<int64> blacks(a.begin(), a.end());

        int64 pos = 1;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'A') {
                pos++;
            } else { // 'B'
                pos = dsu.find(pos + 1);
            }
            dsu.mark_black(pos);
            blacks.insert(pos);
        }

        cout << blacks.size() << "\n";
        bool first = true;
        for (auto v : blacks) {
            if (!first) cout << " ";
            first = false;
            cout << v;
        }
        cout << "\n";
    }
    return 0;
}
