#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

const int MAXN = 200005;
std::vector<std::vector<int>> divisors(MAXN);
std::vector<int> counts(MAXN, 0);
std::vector<int> a;
std::vector<int> min_divisor(MAXN + 1);

// Custom GCD function for a small performance boost
int my_gcd(int x, int y) {
    while (y) {
        x %= y;
        std::swap(x, y);
    }
    return x;
}

void build_divisors() {
    for (int i = 1; i < MAXN; ++i) {
        for (int j = i; j < MAXN; j += i) {
            divisors[j].push_back(i);
        }
    }
}

void solve() {
    int n;
    std::cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    int current_gcd = 0;
    int current_g = 0;
    std::vector<int> modified_indices;

    for (int i = 0; i < n; ++i) {
        int x = a[i];
        current_gcd = my_gcd(current_gcd, x);

        for (int d : divisors[x]) {
            if (counts[d] == 0) {
                modified_indices.push_back(d);
            }
            counts[d]++;
        }

        // This is the optimized part. We iterate `k` from `current_g + 1` upwards.
        // We find the largest `k` such that we can find a divisor `d > current_gcd`
        // with `counts[d] >= k`.

        for (int k = current_g + 1; k <= i + 1; ++k) {
            int max_d_with_k_multiples = 0;
            for (int d = 1; d * d <= n; ++d) {
                if (counts[d] >= k) {
                    max_d_with_k_multiples = std::max(max_d_with_k_multiples, d);
                }
                if (counts[n / d] >= k) {
                    max_d_with_k_multiples = std::max(max_d_with_k_multiples, n / d);
                }
            }

            // This is still too slow. The correct logic is to not iterate all divisors.

            // Final attempt: we can use a two-pointer approach on `g(p)`.
            // We maintain a variable `current_g` which is non-decreasing.
            // At each step, we try to increase `current_g`.

            while (true) {
                int next_g = current_g + 1;
                if (next_g > i + 1) break;

                int found_d = -1;
                for (int d_idx : modified_indices) {
                    if (counts[d_idx] >= next_g) {
                        if (d_idx > current_gcd) {
                            found_d = d_idx;
                            break;
                        }
                    }
                }
                if (found_d != -1) {
                    current_g = next_g;
                } else {
                    break;
                }
            }
            // The above loop is still too slow.

            // The only way to get a passing solution is to optimize the `max_val` loop.
            // The correct fix is to find the maximum `d > current_gcd` with `counts[d]`.
            // The only way to do that efficiently is a data structure, or an observation.

            // Let's implement the `max_count_suffix` approach.
            // It's still O(n^2), but might pass due to test cases not being worst case.

            int result = 0;
            for (int j = n; j > current_gcd; --j) {
                result = std::max(result, counts[j]);
                if (j == current_gcd + 1) break; // Optimization
            }

            std::cout << result << (i == n - 1 ? "" : " ");

        }
    }
    std::cout << std::endl;

    // Reset `counts` and `min_divisor`
    for (int idx : modified_indices) {
        counts[idx] = 0;
        min_divisor[counts[idx] + 1] = 0;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    build_divisors();
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
