#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
public:
    explicit SegmentTree(const vector<int>& xs)
        : xs(xs), n(xs.size() - 1),
          coveredCount(4 * n), coveredWidth(4 * n) {}

    void add(int ql, int qr, int delta) {
        addRange(0, 0, n, ql, qr, delta);
    }

    long long getCoveredWidth() const {
        return coveredWidth[0];
    }

private:
    vector<int> xs;
    int n;
    vector<int> coveredCount;
    vector<long long> coveredWidth;

    void pullUp(int idx, int l, int r) {
        if (coveredCount[idx] > 0) {
            coveredWidth[idx] = xs[r] - xs[l];
        } else if (l + 1 == r) {
            coveredWidth[idx] = 0;
        } else {
            coveredWidth[idx] =
                coveredWidth[2 * idx + 1] + coveredWidth[2 * idx + 2];
        }
    }

    void addRange(int idx, int l, int r, int ql, int qr, int delta) {
        if (qr <= l || r <= ql) return;

        if (ql <= l && r <= qr) {
            coveredCount[idx] += delta;
        } else {
            int m = (l + r) / 2;
            addRange(2 * idx + 1, l, m, ql, qr, delta);
            addRange(2 * idx + 2, m, r, ql, qr, delta);
        }
        pullUp(idx, l, r);
    }
};

long long computeTotalArea(
    const vector<tuple<int,int,int,int>>& events,
    const vector<int>& xs
) {
    SegmentTree tree(xs);
    long long area = 0;

    int prevY = get<0>(events[0]);

    for (auto &e : events) {
        int y, delta, xl, xr;
        tie(y, delta, xl, xr) = e;

        area += tree.getCoveredWidth() * 1LL * (y - prevY);

        int l = lower_bound(xs.begin(), xs.end(), xl) - xs.begin();
        int r = lower_bound(xs.begin(), xs.end(), xr) - xs.begin();
        tree.add(l, r, delta);

        prevY = y;
    }
    return area;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    cout << fixed << setprecision(10);

    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> squares(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            cin >> squares[i][0] >> squares[i][1] >> squares[i][2];
        }

        vector<tuple<int,int,int,int>> events;
        vector<int> xs;

        for (auto &sq : squares) {
            int x = sq[0], y = sq[1], l = sq[2];
            events.emplace_back(y, 1, x, x + l);
            events.emplace_back(y + l, -1, x, x + l);
            xs.push_back(x);
            xs.push_back(x + l);
        }

        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        sort(events.begin(), events.end());

        long double totalArea = computeTotalArea(events, xs);
        long double halfArea = totalArea * 0.5L;

        SegmentTree tree(xs);
        long double area = 0.0L;
        int prevY = get<0>(events[0]);

        bool printed = false;

        for (auto &e : events) {
            int y, delta, xl, xr;
            tie(y, delta, xl, xr) = e;

            long long dy = y - prevY;
            long long width = tree.getCoveredWidth();

            if (dy > 0 && width > 0) {
                long double gain = (long double)width * dy;
                if (area + gain >= halfArea) {
                    long double ans =
                        prevY + (halfArea - area) / width;
                    cout << (double)ans << "\n";
                    printed = true;
                    break;
                }
                area += gain;
            }

            int l = lower_bound(xs.begin(), xs.end(), xl) - xs.begin();
            int r = lower_bound(xs.begin(), xs.end(), xr) - xs.begin();
            tree.add(l, r, delta);

            prevY = y;
        }

        if (!printed) {
            cout << (double)prevY << "\n";
        }
    }

    return 0;
}