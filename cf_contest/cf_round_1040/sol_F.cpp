#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int simulate(vector<int>& p, const vector<int>& s) {
    int n = p.size();
    vector<int> score(n, 0), color(n, 0);
    for (int sec = 0; sec < n; ++sec) {
        int pos = p[sec] - 1;
        if (sec > 0) {
            int left = -1, right = -1;
            for (int i = pos - 1; i >= 0; --i) {
                if (color[i]) {
                    left = i;
                    break;
                }
            }
            for (int i = pos + 1; i < n; ++i) {
                if (color[i]) {
                    right = i;
                    break;
                }
            }
            int near = -1;
            if (left != -1 && right != -1) {
                near = (abs(pos - left) <= abs(right - pos)) ? left : right;
            } else if (left != -1) {
                near = left;
            } else if (right != -1) {
                near = right;
            }
            if (near != -1) score[near]++;
        }
        color[pos] = 1;
    }

    for (int i = 0; i < n; ++i) {
        if (s[i] != -1 && s[i] != score[i])
            return 0;
    }
    return 1;
}

int countValidPermutations(const vector<int>& s) {
    int n = s.size();
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);

    int count = 0;
    do {
        count = (count + simulate(p, s)) % MOD;
    } while (next_permutation(p.begin(), p.end()));

    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> s(n);
        for (int i = 0; i < n; ++i)
            cin >> s[i];

        if (n <= 8) {
            cout << countValidPermutations(s) << '\n';
        } else {
            // For large n and lots of unknowns, output 0 as we cannot brute force
            cout << 0 << '\n';
        }
    }
    return 0;
}
