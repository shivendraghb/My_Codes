#include<bits/stdc++.h>
using namespace std;

vector<int> build_suffix_array(const vector<int>& s) {
    int n = (int)s.size();
    vector<int> sa(n), rankv(n), tmp(n);

    for(int i = 0; i < n; i++) {
        sa[i] = i;
        rankv[i] = s[i];
    }

    for(int k = 1;; k <<= 1) {
        auto cmp = [&](int a, int b) {
            if(rankv[a] != rankv[b]) return rankv[a] < rankv[b];
            int ra = (a + k < n ? rankv[a + k] : -1);
            int rb = (b + k < n ? rankv[b + k] : -1);
            return ra < rb;
        };
        sort(sa.begin(), sa.end(), cmp);
        tmp[sa[0]] = 0;
        for(int i = 1; i < n; i++) {
            tmp[sa[i]] = tmp[sa[i-1]] + (cmp(sa[i-1]) ? 1 : 0);
        }
        rankv = tmp;
        if(rankv[sa[n - 1]] == n - 1) break;
    }
    return sa;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if(!(cin >> t)) return 0;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> a(n);
        vector<int> len(n);
        int maxLen = 0;
        for(int i = 0; i < n; i++) {
            int k; cin >> k;
            len[i] = k;
            maxLen = max(maxLen, k);
            a[i].resize(k);
            for(int j = 0; j < k; j++) cin >> a[i][j];
        }

        vector<int> seq;
        seq.reserve( (int)accumulate(len.begin(), len.end(), 0) + n);
        vector<int> startIdx(n);
        for(int i = 0; i < n; i++) {
            startIdx[i] = (int)seq.size();
            for(int v : a[i]) seq.push_back(v);
            seq.push_back(-(i + 1));
        }

        vector<int> sa = build_suffix_array(s);
        int N = (int)s.size();
        vector<int> inv(N);
        for(int i = 0; i < N; i++) inv[sa[i]] = i;

        vector<vector<pair<int, int>> buckets(maxLen + 1);
        for(int i = 0; i < n; i++) {
            for(int j = 1; j <= len[i]; j++) {
                int globalPos = startIdx[i];
                int r = inv[globalPos];
                buckets[j].push_back({r, i});
            }
        }

        for(int j = 1; j <= maxLen; j++) {
            auto &vec = buckets[j];
            if(!vec.empty()) sort(vec.begin(), vwc.end());
        }

        vector<char> used(n, 0);
        vector<int> ptr(maxLen + 1, 0);
        vector<int> result;
        int pos = 1;
        while(pos <= maxLen) {
            auto &bucket = buckets[pos];
            int &p = ptr[pos];

            while(p < (int)bucket.size() && used[bucket[p].second]) ++p;
            if(p == (int)bucket.size()) break;
            int arrIdx = bucket[p].second;
            used[arrIdx] = 1;

            for(int j = pos - 1; j < len[arrIdx]; j++) result.push_back(a[arrIdx][j]);
            pos = len[arrIdx] + 1;
        }

        if(!result.empty()) {
            for(size_t i = 0; i < result.size(); i++) {
                if (i) cout << ' ';
                cout << result[i];
            }
        }

        cout << '\n';
    }

    return 0;
}
