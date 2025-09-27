#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

void solve() {
    int n;
    long long s;
    std::cin >> n >> s;
    std::vector<int> a(n);
    std::vector<int> counts(3, 0);
    long long total_sum = 0;

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        counts[a[i]]++;
        total_sum += a[i];
    }

    if (s < total_sum) {
        // Bob wins because minimum possible sum is total_sum
        // and Alice cannot achieve a smaller sum with non-negative values.
        // Any rearrangement will work.
        // A simple one is to print the numbers in sorted order.
        for (int i = 0; i < counts[0]; ++i) {
            std::cout << 0 << " ";
        }
        for (int i = 0; i < counts[1]; ++i) {
            std::cout << 1 << " ";
        }
        for (int i = 0; i < counts[2]; ++i) {
            std::cout << 2 << " ";
        }
        std::cout << std::endl;
    } else if (s == total_sum) {
        // Alice can always achieve this sum by taking a straight path
        // from index 1 to n. Bob cannot prevent this.
        std::cout << -1 << std::endl;
    } else if (s == total_sum + 1) {
        // Bob can win by arranging the array such that no 0 is adjacent to a 1.
        // This makes the minimum possible sum increase from a detour to be 2.
        // The arrangement [0...0, 2...2, 1...1] works.
        // This prevents a sum increase of 1, so Alice cannot reach total_sum + 1.
        for (int i = 0; i < counts[0]; ++i) {
            std::cout << 0 << " ";
        }
        for (int i = 0; i < counts[2]; ++i) {
            std::cout << 2 << " ";
        }
        for (int i = 0; i < counts[1]; ++i) {
            std::cout << 1 << " ";
        }
        std::cout << std::endl;
    } else { // s > total_sum + 1
        // Bob cannot win.
        // Even with the arrangement [0...0, 2...2, 1...1], Alice can form detours
        // with sums of 2 (from 0-2 or 1-1 adjacencies) and 3 (from 1-2 adjacency).
        // With sum increases of 2 and 3, she can achieve any sum increase >= 2.
        // Therefore, she can achieve any sum s >= total_sum + 2.
        std::cout << -1 << std::endl;
    }
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
