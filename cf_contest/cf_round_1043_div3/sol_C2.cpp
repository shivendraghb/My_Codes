#include <iostream>
#include <vector>
#include <numeric>

void solve() {
    long long n, k;
    std::cin >> n >> k;

    std::vector<long long> counts;
    long long temp_n = n;

    while(temp_n > 0) {
        counts.push_back(temp_n % 3);
        temp_n /= 3;
    }

    long long current_deals = 0;
    for (long long count : counts) {
        current_deals += count;
    }

    if (current_deals > k) {
        std::cout << -1 << std::endl;
        return;
    }

    long long extra_deals = k - current_deals;

    for (int i = 0; i < counts.size(); ++i) {
        if (extra_deals >= 2 && counts[i] > 0) {
            long long can_convert = std::min(counts[i], extra_deals / 2);
            counts[i] -= can_convert;
            if (i + 1 < counts.size()) {
                counts[i+1] += 3 * can_convert;
            } else {
                counts.push_back(3 * can_convert);
            }
            extra_deals -= 2 * can_convert;
        }
    }

    if (extra_deals > 0) {
        if (counts.back() >= extra_deals / 2) {
             counts.back() -= extra_deals / 2;
             counts.push_back(3 * (extra_deals / 2));
             if (extra_deals % 2 != 0) {
                 counts[0] += 1;
             }
        } else {
            
        }
    }

    long long total_cost = 0;
    long long power_of_3 = 1;
    for (int i = 0; i < counts.size(); ++i) {
        total_cost += counts[i] * (3 * power_of_3 + i * (power_of_3 / 3));
        if (i < counts.size() - 1) {
            power_of_3 *= 3;
        }
    }

    std::cout << total_cost << std::endl;
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
