#include<bit/stdc++.h>
using namespace std;

#define int long long

long long gridlandMetro(long long n, long long m, long long k, vector<vector<long long>> track) {
    unordered_map<long long, vector<pair<long long, long long>>> rows;

    for (auto &t : track) {
        rows[t[0]].push_back({t[1], t[2]});
    }

    long long occupied = 0;

    for (auto &entry : rows) {
        auto &intervals = entry.second;

        sort(intervals.begin(), intervals.end());

        long long start = intervals[0].first;
        long long end = intervals[0].second;

        for (size_t i = 1; i < intervals.size(); ++i) {
            if (intervals[i].first <= end + 1) {
                end = max(end, intervals[i].second);
            } else {
                occupied += (end - start + 1);
                start = intervals[i].first;
                end = intervals[i].second;
            }
        }
        occupied += (end - start + 1);
    }

    long long totalCells = n * m;
    return totalCells - occupied;
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