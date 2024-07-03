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
    void LefttoRight(TreeNode* root, int &value) {

        if (root == NULL) {
            return;
        }

        TreeNode* temp = root -> left ;
         root -> left = root -> right ;
         root -> right = temp;
         
        LefttoRight(root->left, value);
        LefttoRight(root->right, value);
    }

public:
    TreeNode* invertTree(TreeNode* root) {

        if (root == NULL) {
            return root;
        }
        int value = root->val;

        LefttoRight(root, value);
        return root;
    }
};