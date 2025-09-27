#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int n = 100;
        int val = 1000;
        cout << "? " << n;
        for (int i = 0; i < n; i++) cout << " " << val;
        cout << "\n";
        cout.flush();

        int lines;
        cin >> lines;
        if (lines == -1) return 0;

        long long low, high;
        if (lines == 1) {
            low = 100000;
            high = 100000;
        } else {
            low = 100000 / lines;
            high = 100000 / (lines - 1);
        }

        // Second query
        cout << "? 1 " << high << "\n";
        cout.flush();
        int res;
        cin >> res;
        if (res == -1) return 0;

        long long W;
        if (res == 0) {
            W = high - 1;
        } else {
            W = high;
        }

        cout << "! " << W << "\n";
        cout.flush();
    }
    return 0;
}
