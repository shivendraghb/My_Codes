#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k <= 0 || nums.empty() || t < 0) return false;
        multiset<long long> window;
        for (int i = 0; i < (int)nums.size(); ++i) {
            long long x = nums[i];
            auto it = window.lower_bound(x - (long long)t);
            if (it != window.end() && *it <= x + (long long)t) return true;
            window.insert(x);
            if (i >= k) {
                auto eraseIt = window.find((long long)nums[i - k]);
                if (eraseIt != window.end()) window.erase(eraseIt);
            }
        }
        return false;
    }
};
// Two-pointer approach: sort (value, index) pairs and slide by value
bool containsNearbyAlmostDuplicateTwoPointer(vector<int>& nums, int k, int t) {
    if (k <= 0 || nums.empty() || t < 0) return false;
    int n = nums.size();
    vector<pair<long long,int>> a;
    a.reserve(n);
    for (int i = 0; i < n; ++i) a.emplace_back((long long)nums[i], i);
    sort(a.begin(), a.end()); // sort by value

    int l = 0;
    for (int r = 0; r < n; ++r) {
        while (l < r && a[r].first - a[l].first > (long long)t) ++l;
        for (int i = l; i < r; ++i) {
            if (llabs(a[r].second - a[i].second) <= k) return true;
        }
    }
    return false;
}

// Example usage (for local testing):
// int main() {
//     vector<int> nums = {1,2,3,1};
//     cout << containsNearbyAlmostDuplicateTwoPointer(nums, 3, 0) << "\n"; // expected 1
//     return 0;
// }

// Example usage (for local testing):
// int main() {
//     Solution sol;
//     vector<int> nums = {1,2,3,1};
//     cout << sol.containsNearbyAlmostDuplicate(nums, 3, 0) << "\n"; // expected 1
//     return 0;
// }