#include <iostream>
#include <vector>
#include <numeric>

void solve() {
    int n;
    long long k;
    std::cin >> n >> k;
    std::vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::vector<long long> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    long long p = -1;
    for (long long prime : primes) {
        if (k % prime != 0) {
            p = prime;
            break;
        }
    }

    if (p == -1) {
    }

    for (int i = 0; i < n; ++i) {
        if (a[i] % p != 0) {
            long long rem = a[i] % p;
            long long needed = (p - rem) % p;

            long long k_rem = k % p;

            // To find smallest x such that a_i + x*k = 0 mod p
            // rem + x*k_rem = 0 mod p
            // x*k_rem = -rem mod p
            // x = -rem * inv(k_rem) mod p

            // A simpler way: just loop and add k
            long long x = 0;
            while ((a[i] + x * k) % p != 0) {
                x++;
            }
            a[i] += x * k;
        }
    }

    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << (i == n - 1 ? "" : " ");
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
