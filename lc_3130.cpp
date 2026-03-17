#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX = 200005; 

long long fact[MAX], invFact[MAX];

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n) {
    return power(n, MOD - 2);
}

void precompute() {
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i < MAX; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invFact[MAX - 1] = modInverse(fact[MAX - 1]);
    for (int i = MAX - 2; i >= 1; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

// Number of ways to distribute x items into g groups, each group size <= limit, size >= 1
long long ways(int x, int g, int limit) {
    if (g == 0) return (x == 0) ? 1 : 0;
    if (x < g) return 0;
    
    long long ans = 0;
    for (int k = 0; k * limit <= x - g && k <= g; k++) {
        long long ways_k = nCr(g, k) * nCr(x - k * limit - 1, g - 1) % MOD;
        if (k % 2 == 1) {
            ans = (ans - ways_k + MOD) % MOD;
        } else {
            ans = (ans + ways_k) % MOD;
        }
    }
    return ans;
}

void solve() {
    int zero, one, limit;
    cin >> zero >> one >> limit;
    
    long long total_stable = 0;
    
    // Zeros and Ones blocks must alternate.
    // Iterating through all possible valid block pairings:
    for (int g = 1; g <= min(zero, one); g++) {
        long long w0 = ways(zero, g, limit);
        long long w1 = ways(one, g, limit);
        
        // 1. (g, g) case: Can start with 0 or start with 1 (hence the 2 multiplier)
        total_stable = (total_stable + 2LL * w0 % MOD * w1 % MOD) % MOD;
        
        // 2. (g+1, g) case: Starts and ends with 0 (e.g., 0...0)
        long long w0_plus = ways(zero, g + 1, limit);
        total_stable = (total_stable + w0_plus * w1 % MOD) % MOD;
        
        // 3. (g, g+1) case: Starts and ends with 1 (e.g., 1...1)
        long long w1_plus = ways(one, g + 1, limit);
        total_stable = (total_stable + w0 * w1_plus % MOD) % MOD;
    }
    
    cout << total_stable << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    precompute(); 
    
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}