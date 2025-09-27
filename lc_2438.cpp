#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;

long long modPow(long long base, long long exp) {
    long long res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long x) {
    return modPow(x, MOD - 2);
}

vector<long long> getPowers(int n) {
    vector<long long> powers;
    long long curr = 1;
    while (n > 0) {
        if (n % 2 == 1) powers.push_back(curr);
        n /= 2;
        curr *= 2;
    }
    sort(powers.begin(), powers.end());
    return powers;
}

vector<long long> productQueries(int n, vector<vector<int>>& queries) {
    vector<long long> powers = getPowers(n);
    int m = powers.size();
    vector<long long> pref(m);
    pref[0] = powers[0] % MOD;
    for (int i = 1; i < m; i++) {
        pref[i] = (pref[i-1] * powers[i]) % MOD;
    }

    vector<long long> ans;
    for (auto &q : queries) {
        int l = q[0], r = q[1];
        if (l == 0) ans.push_back(pref[r]);
        else ans.push_back((pref[r] * modInverse(pref[l-1])) % MOD);
    }
    return ans;
}

int main() {
    int n = 15;
    vector<vector<int>> queries = {{0,1},{2,2},{0,3}};
    vector<long long> res = productQueries(n, queries);
    for (auto x : res) cout << x << " " << '\n';
}
