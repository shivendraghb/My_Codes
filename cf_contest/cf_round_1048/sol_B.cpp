#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

void solve() {
    int n;
    long long m;
    std::cin >> n >> m;
    std::vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::sort(a.rbegin(), a.rend());

    long long total_cakes = 0;
    int num_ovens_to_collect = std::min((long long)n, m);

    for (int i = 0; i < num_ovens_to_collect; ++i) {
        total_cakes += a[i] * (m - i);
    }
    std::cout << total_cakes << std::endl;
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
