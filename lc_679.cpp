#include<bits/stdc++.h>
using namespace std;

#define int long long

const double EPS = 1e-6;

vector<double> compute(double a, double b);
bool dfs(vector<double>& nums);

bool judgePoint24(vector<int>& cards) {
    vector<double> nums;
    for(int i : cards)
        nums.push_back((double)i);

    return dfs(nums);
}

bool dfs(vector<double>& nums) {
    if(nums.size() == 1)
        return fabs(nums[0] - 24.0) < EPS;

    for(int i = 0; i < nums.size(); i++) {
        for(int j = 0; j < nums.size(); j++) {
            if(i == j) continue;

            vector<double> next;
            for(int k = 0; k < nums.size(); k++)
                if(k != i && k != j)
                    next.push_back(nums[k]);

            for(double val : compute(nums[i], nums[j])) {
                next.push_back(val);
                if(dfs(next)) return true;
                next.pop_back();
            }
        }
    }
    return false;
}

vector<double> compute(double a, double b) {
    vector<double> res;
    res.push_back(a + b);
    res.push_back(a - b);
    res.push_back(b - a);
    res.push_back(a * b);
    if(fabs(b) > EPS) res.push_back(a / b);
    if(fabs(a) > EPS) res.push_back(b / a);

    return res;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;


    while(t--) {
        int n;
        cin >> n;

        vector<int> cards(n);
        for(int i = 0; i < n; i++)
            cin >> cards[i];

        bool ans = judgePoint24(cards);

        cout << (ans ? "YES\n" : "NO\n");
    }

    return 0;
}
