/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int moves = 0;
    int dfs(TreeNode *curr) {
        // int moves;
        if (curr == NULL) return 0;

        int lc = dfs(curr->left);
        int rc = dfs(curr->right);

        moves += abs(lc) + abs(rc);

        return lc + rc + (curr->val) - 1;
    }
public:
    int distributeCoins(TreeNode* root) {
        moves;
        dfs(root);
        return moves; 
    }
};