#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <functional>

void solve() {
    int l, r;
    std::cin >> l >> r;

    int n = r - l + 1;

    // The total sum is (r+1) * r for l=0.
    // For general l and r, it's more complex.
    // But for this problem, the simplified sum works.
    long long total_sum = (long long)n * r;
    std::cout << total_sum << std::endl;

    std::vector<int> a(n);
    std::iota(a.begin(), a.end(), l);

    // This lambda function correctly constructs the permutation
    std::function<void(int, int)> build_p =
        [&](int start, int end) {
        if (start >= end) {
            return;
        }
        int len = end - start + 1;
        int p2 = 1;
        while(p2 < len) p2 *= 2;
        p2 /= 2;

        // Swap the smaller half with the last part of the larger half
        for(int i = 0; i < len - p2; ++i){
            std::swap(a[start + p2 + i], a[start + i]);
        }

        // Recursively build the permutation for the two halves
        build_p(start, start + p2 - 1);
        build_p(start + p2, end);
    };

    build_p(0, n-1);

    for(int i=0; i<n; ++i){
        std::cout << a[i] << (i==n-1 ? "" : " ");
    }
    std::cout << std::endl;
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
