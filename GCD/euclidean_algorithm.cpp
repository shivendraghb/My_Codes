#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    /*
    Idea: gcd(a,b) = gcd(b, a % b) — replace subtraction chain with
    one division and remainder per iteration.

    Properties:
    Number of iterations is O(log min(a,b)) (fast).
    But each iteration uses a division/modulo of two multi-word
    integers; the bit cost depends on the cost of division.

    Notation:
    let n be bit-length of inputs and let M(n)
    be cost to multiply/divide n-bit numbers.

    With schoolbook arithmetic M(n) = O(n^2).

    Euclid bit-complexity ≈ O(M(n) * log n)
    (intuitively: ~log n iterations × cost of a division).

    So if division is expensive (naive O(n^2)), total cost
    can be O(n^2 log n). With fast multiplication/division,
    you can reduce this (see Lehmer, advanced gcd algorithms).
    */
    long long a, b;
    cin >> a >> b;

    if(a < 0) a -= a;
    if(b < 0) b -= b;

    while(b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }

    cout << a << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
