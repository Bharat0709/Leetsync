/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    void solve(TreeNode* root, int& good, int currMax) {
        if (root == NULL) {
            return;
        }
        if (root->val >= currMax) {
            currMax = root->val;
            good++;
        }

        solve(root->left, good, currMax);
        solve(root->right, good, currMax);
    }

public:
    int goodNodes(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int good = 0;
        solve(root, good, root->val);
        return good;
    }
};