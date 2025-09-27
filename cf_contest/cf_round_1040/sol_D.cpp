#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> p[i];
    }

    long long inv_p = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (p[i] > p[j]) {
                inv_p++;
            }
        }
    }

    long long total_min_inv = inv_p;

    for (int i = 0; i < n; ++i) {
        long long num_inv_before = 0;
        for (int j = 0; j < i; ++j) {
            if (p[j] > p[i]) {
                num_inv_before++;
            }
        }

        long long num_noninv_after = 0;
        for (int j = i + 1; j < n; ++j) {
            if (p[i] < p[j]) {
                num_noninv_after++;
            }
        }

        long long C_i = num_noninv_after - num_inv_before;
        total_min_inv += std::min(0LL, C_i);
    }

    std::cout << total_min_inv << " \n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
