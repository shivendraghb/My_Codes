#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int v = n; v >= 1; v--) {
        vector<int> b(n + 1);
        vector<int> s(n + 1);
        int cnt_v = 0; // Count of elements equal to v
        for (int i = 1; i <= n; i++) {
            b[i] = (a[i] <= v) ? 1 : 0;
            s[i] = s[i - 1] + b[i];
            if (a[i] == v) cnt_v++;
        }

        deque<int> min_dq, max_dq;
        for (int r = 1; r <= n; r++) {
            // Maintain min and max prefix sums for l <= r - k + 1
            while (!min_dq.empty() && min_dq.front() < r - n) min_dq.pop_front();
            while (!max_dq.empty() && max_dq.front() < r - n) max_dq.pop_front();
            while (!min_dq.empty() && s[min_dq.back()] >= s[r]) min_dq.pop_back();
            while (!max_dq.empty() && s[max_dq.back()] <= s[r]) max_dq.pop_back();
            min_dq.push_back(r);
            max_dq.push_back(r);

            if (r >= k) {
                int l = r - k + 1;
                // Check earlier l if necessary
                while (!min_dq.empty() && min_dq.front() < l - 1) min_dq.pop_front();
                while (!max_dq.empty() && max_dq.front() < l - 1) max_dq.pop_front();
                int min_s = s[min_dq.front()];
                int max_s = s[max_dq.front()];
                int m = r - l + 1;
                int ceil_m2 = (m + 1) / 2;
                int floor_m2 = m / 2;
                int cnt_leq_v = s[r] - min_s;
                int cnt_less_v = s[r] - min_s - cnt_v;
                int cnt_geq_v = m - cnt_less_v;
                if (cnt_leq_v >= ceil_m2 && cnt_geq_v >= ceil_m2) {
                    cout << v << " " << l << " " << r << '\n';
                    return;
                }
                // Check longer subarrays
                for (int ll = l - 1; ll >= 1 && r - ll + 1 <= n; ll--) {
                    m = r - ll + 1;
                    ceil_m2 = (m + 1) / 2;
                    floor_m2 = m / 2;
                    cnt_leq_v = s[r] - s[ll - 1];
                    cnt_less_v = cnt_leq_v - cnt_v;
                    cnt_geq_v = m - cnt_less_v;
                    if (cnt_leq_v >= ceil_m2 && cnt_geq_v >= ceil_m2) {
                        cout << v << " " << ll << " " << r << '\n';
                        return;
                    }
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
