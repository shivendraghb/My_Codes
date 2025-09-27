#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>

struct Pair {
    long long first, second;
};

bool comparePairs(const Pair& a, const Pair& b) {
    return a.first < b.first;
}

void solve() {
    int n;
    long long k;
    std::cin >> n >> k;

    std::vector<long long> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
    }

    if (n == 1) {
        std::cout << std::abs(a[0] - b[0]) << std::endl;
        return;
    }

    long long initial_sum = 0;
    std::vector<Pair> pairs(n);
    for (int i = 0; i < n; ++i) {
        initial_sum += std::abs(a[i] - b[i]);
        pairs[i].first = std::min(a[i], b[i]);
        pairs[i].second = std::max(a[i], b[i]);
    }

    std::sort(pairs.begin(), pairs.end(), comparePairs);

    bool overlap_found = false;
    long long max_end = pairs[0].second;
    for (int i = 1; i < n; ++i) {
        if (pairs[i].first <= max_end) {
            overlap_found = true;
            break;
        }
        max_end = std::max(max_end, pairs[i].second);
    }

    if (overlap_found) {
        std::cout << initial_sum << std::endl;
        return;
    }

    long long min_gap = -1;
    for (int i = 0; i < n - 1; ++i) {
        long long current_gap = pairs[i+1].first - pairs[i].second;
        if (min_gap == -1 || current_gap < min_gap) {
            min_gap = current_gap;
        }
    }

    long long min_increase = 2 * min_gap;
    long long final_sum = initial_sum + k * min_increase;
    std::cout << final_sum << std::endl;
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
