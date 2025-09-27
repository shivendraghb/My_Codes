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
        vector<int> a(n), b(n);
        for (int &x : a) cin >> x;
        for (int &x : b) cin >> x;

        int pos_sum = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > b[i]) pos_sum += a[i] - b[i];
        }
        cout << pos_sum + 1 << "\n";
    }
}
