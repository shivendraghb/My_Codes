#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> m(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> m[i][j];
    
    // count negatives
    auto cnt_neg = [&](const vector<vector<int>>& m) {
        int neg = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (m[i][j] < 0)
                    neg++;

        return neg;
    };

    // find the absolute sum of all the elements in the matrix 
    auto find_sum = [&](const vector<vector<int>>& m) {
        // int s = 0;
        // for (int i = 0; i < n; i++)
        //     for (int j = 0; j < n; j++)
        //         s += abs(m[i][j]);
        int s = 0;
        for (auto &row : m) {
            s += accumulate(row.begin(), row.end(), 0LL,
                [](int a, int b) {
                    return a + abs(b);
                } 
            );
        }

        return s;
    };

    // find the minimum absolute 
    auto min_abs_neg = [&](const vector<vector<int>>& m) {
        int min_neg = LLONG_MAX;
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++) 
                min_neg = min(min_neg, llabs(m[i][j]));

        return min_neg;
    };

    if (cnt_neg(m) % 2 == 0)
        { cout << find_sum(m) << '\n'; }
    else
        cout << find_sum(m) - 2 * min_abs_neg(m) << '\n';

    long long sum = 0;
    long long mn = LLONG_MAX;
    int neg = 0;

    for (auto &row : m) {
        for (int x : row) {
            if (x < 0) neg++;
            sum += llabs(x);
            mn = min(mn, llabs(x));
        }
    }

    if (neg & 1) sum -= 2 * mn;
    cout << sum << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}