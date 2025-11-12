#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(const vector<int>& nums, int k) {
        unordered_set<int> window;
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (window.count(nums[i])) return true;
            window.insert(nums[i]);
            if ((int)window.size() > k) {
                window.erase(nums[i - k]);
            }
        }
        return false;
    }
};

int main() {
    // Example usage:
    // Input format: first line n k
    // next line n integers
    // Example:
    // 5 3
    // 1 2 3 1 4
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    if (!(cin >> n >> k)) return 0;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];

    Solution sol;
    cout << (sol.containsNearbyDuplicate(nums, k) ? "true" : "false") << '\n';
    return 0;
}