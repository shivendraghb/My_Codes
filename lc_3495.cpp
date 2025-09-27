#include<bits/stdc++.h>
using namespace std;

#define int long long

long long prefix(long long x) {
    if(x <= 0) return 0;
    long long res = 0;
    long long p = 1;
    int step = 1;
    while(p <= x) {
        long long next = min(x, p * 4 - 1);
        long long cnt = next - p + 1;
        res += cnt * step;
        p *= 4;
        step++;
    }

    return res;
}

long long minimumOperations(vector<vector<int>>& queries) {
    long long total = 0;
    for(auto &q : queries) {
        long long l = q[0], r = q[1];
        long long s = prefix(r) - prefix(l - 1);
        total += (s + 1) / 2;
    }

    return total;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    vector<vector<int>> queries(q, vector<int>(2));

    for(int i = 0; i < q; i++)
        cin >> queries[i][0] >> queries[i][1];

    cout << minimumOperations(queries) << '\n';

    return 0;
}
