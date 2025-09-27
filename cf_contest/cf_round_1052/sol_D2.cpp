#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

long long count_set_bits(long long n, int k) {
    long long count = 0;
    long long block_size = 1LL << (k + 1);
    long long num_blocks = (n + 1) / block_size;
    count += num_blocks * (1LL << k);
    long long remainder = (n + 1) % block_size;
    count += std::max(0LL, remainder - (1LL << k));
    return count;
}

std::vector<long long> solve(long long l, long long r) {
    if (l == r) {
        return {l};
    }

    int k = -1;
    for (int i = 29; i >= 0; --i) {
        if (((l >> i) & 1) != ((r >> i) & 1)) {
            k = i;
            break;
        }
    }

    if (k == -1) {
        std::vector<long long> result;
        for (long long i = r; i >= l; --i) {
            result.push_back(i);
        }
        return result;
    }

    long long middle_l = l;
    long long middle_r = ((l >> k) << k) | ((1LL << k) - 1);

    std::vector<long long> part1 = solve(middle_l, middle_r);

    std::vector<long long> result;
    result.insert(result.end(), part1.begin(), part1.end());

    if (middle_r + 1 <= r) {
        std::vector<long long> part2 = solve(middle_r + 1, r);
        result.insert(result.end(), part2.begin(), part2.end());
    }

    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        long long l, r;
        std::cin >> l >> r;

        long long n = r - l + 1;
        long long sum_b = (r + l) * n / 2;
        long long min_and_sum = 0;

        for (int k = 0; k < 30; ++k) {
            long long count_1s_r = count_set_bits(r, k);
            long long count_1s_l_minus_1 = (l > 0) ? count_set_bits(l - 1, k) : 0;
            long long n_k1 = count_1s_r - count_1s_l_minus_1;

            if (2 * n_k1 > n) {
                min_and_sum += (2 * n_k1 - n) * (1LL << k);
            }
        }

        long long max_or_sum = 2 * sum_b - min_and_sum;
        std::cout << max_or_sum << std::endl;

        std::vector<long long> a = solve(l, r);

        std::vector<long long> final_a;
        for (long long i = r; i >= l; --i) {
            final_a.push_back(i);
        }

        for (size_t i = 0; i < final_a.size(); ++i) {
            std::cout << final_a[i] << (i == final_a.size() - 1 ? "" : " ");
        }
        std::cout << std::endl;
    }
    return 0;
}
