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
    void solve(TreeNode* root1, TreeNode* root2, TreeNode*& root) {
        int sum = 0;

        if (root2 == NULL && root1 == NULL) {
            return;
        }

        TreeNode *left1 = nullptr, *right1 = nullptr, *left2 = nullptr,
                 *right2 = nullptr;

        if (root1 != NULL && root2 != NULL) {
            sum = root1->val + root2->val;
            root = new TreeNode(sum);
            left1 = root1->left;
            right1 = root1->right;
            left2 = root2->left;
            right2 = root2->right;
        }

        if (root1 != NULL && root2 == NULL) {
            sum += root1->val;
            root = new TreeNode(sum);
            left1 = root1->left;
            right1 = root1->right;
        }

        if (root2 != NULL && root1 == NULL) {
            sum += root2->val;
            root = new TreeNode(sum);
            left2 = root2->left;
            right2 = root2->right;
        }

        solve(left1, left2, root->left);
        solve(right1, right2, root->right);
    };

public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {

        if (root1 == NULL && root2 == NULL) {
            return root1;
        };

        if (root1 == NULL && root2 != NULL) {
            return root2;
        };

        if (root2 == NULL && root1 != NULL) {
            return root1;
        }

        TreeNode* root = new TreeNode(root1->val + root2->val);

        solve(root1, root2, root);

        return root;
    }
};