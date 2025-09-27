#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    unordered_map<int, int> mp;
    for(int i : v)
        mp[i]++;

    vector<int> r;

    int threshold = n / 3;

    for (auto &p : mp) {
        if (p.second > threshold)
            r.push_back(p.first);
    }

    sort(r.begin(), r.end());
    for (int x : r)
        cout << x << " ";
    cout << "\n";

    vector<int> majorityElement(vector<int>& nums) {
        int majority1 = 0;
        int majority2 = 0;
        int count1 = 0;
        int count2 = 0;

        for (const int num : nums) {
            if (num == majority1) {
                count1++;
            } else if (num == majority2) {
                count2++;
            } else if (count1 == 0) {
                majority1 = num;
                count1++;
            } else if (count2 == 0) {
                majority2 = num;
                count2++;
            } else {
                count1--;
                count2--;
            }
        }

        count1 = 0;
        count2 = 0;

        for (const int num : nums) {
            if (num == majority1) {
                count1++;
            } else if (num == majority2) {
                count2++;
            }
        }

        std::vector<int> res;

        if (count1 > nums.size() / 3) {
            res.push_back(majority1);
        }
        if (count2 > nums.size() / 3) {
            res.push_back(majority2);
        }

        return res;
    }
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
