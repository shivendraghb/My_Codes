#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<unsigned int> a(n), b(n);
        for (auto &x : a) cin >> x;
        for (auto &x : b) cin >> x;

        bool ok = true;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] != b[i]) {
                unsigned int new_val = a[i] ^ a[i+1];
                if (new_val != b[i]) {
                    ok = false;
                    break;
                }
                a[i] = new_val; // perform operation at i
            }
        }
        if (a[n-1] != b[n-1]) ok = false;

        cout << (ok ? "YES\n" : "NO\n");
    }
}
