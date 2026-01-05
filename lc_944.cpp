class Solution {
public:
    int minDeletionSize(vector<string>& a) {
        int n = a.size(), m = a[0].size(), ans = 0;

        for (int j = 0; j < m; j++) {
            for (int i = 1; i < n; i++) {
                if (a[i][j] < a[i - 1][j]) {
                    ans++;
                    break;
                }
            }
        }

        return ans;
    }
};