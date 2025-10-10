#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e7 + 5;
int spf[MAXN];

void sieve() {
    for (int i = 0; i < MAXN; i++) spf[i] = i;
    for (int i = 2; i * i < MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXN; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}

// Factorize n using spf, return set of distinct prime factors
vector<int> factorize(int n) {
    vector<int> primes;
    while (n > 1) {
        int p = spf[n];
        primes.push_back(p);
        while (n % p == 0) n /= p;
    }
    sort(primes.begin(), primes.end());
    primes.erase(unique(primes.begin(), primes.end()), primes.end());
    return primes;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve();

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> primes = factorize(n);

        // Sum f_m(x,n) over 1 <= x <= n-1
        long long ans = 0;
        for (int p : primes) {
            // For prime p, contribution is number of x < p
            ans += min(p - 1, n - 1);  // x from 1 to n-1
        }

        cout << ans << "\n";
    }

    return 0;
}