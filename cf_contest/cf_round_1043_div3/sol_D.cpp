#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

long long sum_digits_upto(long long n) {
    if (n <= 0) return 0;
    long long res = 0, p = 1;
    while (p <= n) {
        long long left = n / (p * 10);
        long long cur  = (n / p) % 10;
        long long right = n % p;

        res += left * 45 * p;
        res += (cur * (cur - 1) / 2) * p;
        res += cur * (right + 1);

        if (p > n / 10) break;
        p *= 10;
    }
    return res;
}

long long total_digits(long long n) {
    if (n <= 0) return 0;
    long long d = 0;
    long long len = 1, p = 1;
    while (true) {
        long long next = min(n, p * 10 - 1);
        d += (next - p + 1) * len;
        if (next == n) break;
        p *= 10;
        len++;
    }
    return d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long k;
        cin >> k;

        long long lo = 0, hi = 1000000000000000LL, m = 0;
        while (lo <= hi) {
            long long mid = (lo + hi) / 2;
            if (total_digits(mid) <= k) {
                m = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        long long ans = sum_digits_upto(m);
        long long used = total_digits(m);
        long long leftover = k - used;

        if (leftover > 0) {
            string nxt = to_string(m + 1);
            for (int i = 0; i < leftover; i++)
                ans += nxt[i] - '0';
        }

        cout << ans << "\n";
    }
    return 0;
}
