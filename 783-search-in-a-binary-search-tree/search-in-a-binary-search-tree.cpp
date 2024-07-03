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
    void traverse(TreeNode* root, int val, TreeNode*& result) {
        if (root == NULL) {
            return;
        }

        if (root->val == val) {
            result = root;
        }

        traverse(root->left, val, result);
        traverse(root->right, val, result);
    }

public:
    TreeNode* searchBST(TreeNode* root, int val) {

        if (root == NULL) {
            return root;
        }
        if(root -> val == val){
            return root;
        }

        TreeNode* result = NULL;
        if (val > root->val) {
            traverse(root->right, val, result);
        } else {
            traverse(root->left, val, result);
        }

        if (result) {
            return result;
        } else
            return NULL;
    }
};