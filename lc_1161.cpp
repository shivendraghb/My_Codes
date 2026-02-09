#include<bits/stdc++.h>
using namespace std;

// #define int long long

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(vector<optional<int>>& v) {
    if (v.empty() || !v[0].has_value())
        return nullptr;

    TreeNode* root = new TreeNode(*v[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < (int)v.size()) {
        TreeNode* curr = q.front();
        q.pop();

        // Left child
        if (i < v.size() && v[i].has_value()) {
            curr->left = new TreeNode(*v[i]);
            q.push(curr->left); 
        }
        i++;

        // Right child
        if (i < v.size() && v[i].has_value()) {
            curr->right = new TreeNode(*v[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

int maxLevelSum(TreeNode* root) {
    if (!root) return 0;

    queue<TreeNode*> q;
    q.push(root);

    int level = 1;
    int ansLevel = 1;

    long long maxSum = LLONG_MIN;

    while (!q.empty()) {
        int sz = q.size();
        long long currSum = 0;

        for (int i = 0; i < sz; i++) {
            TreeNode* node = q.front();
            q.pop();

            currSum += node->val;

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        if (currSum > maxSum) {
            maxSum = currSum;
            ansLevel = level;
        }

        level++;
    }

    return ansLevel;
}

void solve() {
    int n;
    cin >> n;

    vector<optional<int>> v(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        if (s == "null")
            v[i] = nullopt;
        else
            v[i] = stoi(s);
    }

    TreeNode* root = buildTree(v);

    int ans = maxLevelSum(root);

    cout << ans << '\n';
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