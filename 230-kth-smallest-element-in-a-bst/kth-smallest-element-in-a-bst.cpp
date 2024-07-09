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
    void kSmallest(TreeNode* root, int& k, int& ans) {
        if (root == NULL) {
            return;
        }
        kSmallest(root->left, k, ans);
        k--;
        if (k == 0) {
            ans = root->val;
            return;
        }
        kSmallest(root->right, k, ans);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        if (root == NULL) {
            return 0;
        }
        int ans;

        kSmallest(root, k, ans);
        return ans;
    }
};