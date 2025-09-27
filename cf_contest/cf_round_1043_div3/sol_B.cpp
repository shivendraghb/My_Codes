#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        vector<long long> answers;

        long long power10 = 10;
        for (int k = 1; k <= 18; k++) {
            long long d = power10 + 1; // divisor = 10^k + 1
            if (n % d == 0) {
                long long x = n / d;
                answers.push_back(x);
            }
            if (power10 > 1e18 / 10) break; // avoid overflow
            power10 *= 10;
        }

        if (answers.empty()) {
            cout << 0 << "\n";
        } else {
            sort(answers.begin(), answers.end()); // ensure ascending order
            cout << answers.size() << "\n";
            for (auto x : answers) cout << x << " ";
            cout << "\n";
        }
    }
    return 0;
}
