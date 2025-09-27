#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int m;
    cin >> m;

    vector<vector<int>> v(m, vector<int>(2));
    for(int i = 0; i < m; i++)
        for(int j = 0; j < 2; j++)
            cin >> v[i][j];

    int extraStudents;
    cin >> extraStudents;

    // auto gain = [](int pass, int total) {
    //     return 1.0 * (pass + 1) / (total + 1) - 1.0 * pass / total;
    // };

    // vector<pair<int, int>> classes(m);
    // for (int i = 0; i < m; ++i) {
    //     classes[i] = {v[i][0], v[i][1]};
    // }

    // while (extraStudents--) {
    //     int idx = 0;
    //     double maxGain = gain(classes[0].first, classes[0].second);
    //     for (int i = 1; i < m; ++i) {
    //         double g = gain(classes[i].first, classes[i].second);
    //         if (g > maxGain) {
    //             maxGain = g;
    //             idx = i;
    //         }
    //     }
    //     classes[idx].first += 1;
    //     classes[idx].second += 1;
    // }

    // double sum = 0.0;
    // for (int i = 0; i < m; ++i) {
    //     sum += 1.0 * classes[i].first / classes[i].second;
    // }
    // double maxRatio = sum / m;

    // cout << fixed << setprecision(5) << maxRatio << '\n';

    auto gain = [](int pass, int total) {
        return (double)(pass + 1) / (total + 1) - (double)pass / total;
    };

    priority_queue<tuple<double, int, int>> pq;

    for(auto &c : v) {
        pq.push({gain(c[0], c[1]), c[0], c[1]});
    }

    while(extraStudents--) {
        auto [g, pass, total] = pq.top();
        pq.pop();
        pass++, total++;

        pq.push({gain(pass, total), pass, total});
    }

    double sum = 0.0;
    while(!pq.empty()) {
        auto [g, pass, total] = pq.top();
        pq.pop();
        sum += (double)pass / total;
    }

    cout << fixed << setprecision(5) << sum / v.size() << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
}
