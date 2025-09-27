#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MAX_X = 19;
    vector<long long> p3(MAX_X + 2, 1);
    for (int i = 1; i <= MAX_X + 1; ++i) p3[i] = p3[i-1] * 3LL;

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        long long cost = 0;

        for (int x = 18; x >= 1; --x) {
            long long d = n / p3[x];
            if (d > 0) {
                cost += d * (p3[x+1] + x * p3[x-1]);
                n -= d * p3[x];
            }
        }
        if (n > 0) cost += n * 3;

        cout << cost << "\n";
    }
    return 0;
}

