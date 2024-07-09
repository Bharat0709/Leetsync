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
    void preOrder(TreeNode* root, vector<int>& ans) {
        if (root == NULL) {
            return;
        }
        ans.push_back(root->val);
        preOrder(root->left, ans);
        preOrder(root->right, ans);
    }

public:
    void flatten(TreeNode* root) {
        vector<int> ans;

        preOrder(root, ans);
        if (root != NULL) {
            root->left = NULL;
            root->right = NULL;
            for (int i = 1 ; i < ans.size() ; i++ ) {
                TreeNode* temp = new TreeNode(ans[i]);
                root->right = temp;
                root = root->right;
            }
        }
    }
};