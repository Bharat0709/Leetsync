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
    void solve(TreeNode* root1, TreeNode* root2, TreeNode*& root) {
        if (root1 == NULL && root2 == NULL) {
            return;
        }

        int sum = 0;
        TreeNode *left1 = nullptr, *right1 = nullptr, *left2 = nullptr, *right2 = nullptr;

        if (root1 != NULL) {
            sum += root1->val;
            left1 = root1->left;
            right1 = root1->right;
        }

        if (root2 != NULL) {
            sum += root2->val;
            left2 = root2->left;
            right2 = root2->right;
        }

        root = new TreeNode(sum);

        solve(left1, left2, root->left);
        solve(right1, right2, root->right);
    }

public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode* root = nullptr;
        solve(root1, root2, root);
        return root;
    }
};
