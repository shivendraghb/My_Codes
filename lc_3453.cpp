#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> s(n, vector<int>(3));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 3; j++)
            cin >> s[i][j];

    long double half = 0;
    for (auto &sq : s) {
        long double l = sq[2];
        half += l * l;
    }
    half /= 2.0L;

    vector<pair<long long, long long>> events;
    events.reserve(2*n);
    for (auto &sq : s) {
        long long y = sq[1], l = sq[2];
        events.push_back({y, l});
        events.push_back({y + l, -l});
    }

    sort(events.begin(), events.end());

    long double area = 0;
    long long width = 0;
    long long prevY = events[0].first;

    for (auto &ev : events) {
        long long y = ev.first;
        long long delta = ev.second;

        long long dy = y - prevY;
        if (dy > 0) {
            long double segmentArea = (long double)width * (long double)dy;
            if (area + segmentArea >= half) {
                long double remain = half - area;
                cout << prevY + (remain / (long double)width) << '\n';
                return;
            }
            area += segmentArea;
            prevY = y;
        }

        width += delta;
    }

    cout << prevY << '\n';
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