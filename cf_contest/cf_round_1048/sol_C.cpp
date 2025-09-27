#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int k;
        ull x;
        cin >> k >> x;
        ull init = 1ULL << k;
        ull total = init * 2ULL;
        ull a = x, b = total - x;

        vector<int> rev_ops;
        while (a != init) {
            if (rev_ops.size() > 200) break;
            if (a > b) {
                rev_ops.push_back(2);
                a = a - b;
                b = b * 2ULL;
            } else {
                rev_ops.push_back(1);
                a = a * 2ULL;
                b = b - a / 2ULL;
            }
        }

        reverse(rev_ops.begin(), rev_ops.end());

        cout << rev_ops.size() << "\n";
        if (!rev_ops.empty()) {
            for (size_t i = 0; i < rev_ops.size(); ++i) {
                if (i) cout << ' ';
                cout << rev_ops[i];
            }
        }
        cout << "\n";
    }
    return 0;
}
