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

    void inOrder(TreeNode* root, TreeNode* &current) {
        if (root == NULL) {
            return;
        }

        inOrder(root->left, current);


        current -> right = new TreeNode(root->val);
        current = current -> right;
        inOrder(root->right, current);
    }

public:
    TreeNode* increasingBST(TreeNode* root) {

        TreeNode* root1 = new TreeNode(0);
        TreeNode* current = root1;

        inOrder(root, current);
        return root1 -> right ;
    }
};