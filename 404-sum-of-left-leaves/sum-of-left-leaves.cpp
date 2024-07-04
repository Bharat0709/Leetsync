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
    void leftTraverse(TreeNode* root, int& sum) {
        if (root == NULL) {
            return;
        }

        if (root->left && root -> left -> left == NULL && root -> left -> right == NULL) {
            sum += root->left->val;
        }
        cout << sum << endl;

        leftTraverse(root->left, sum);
        leftTraverse(root->right, sum);
    }

public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int sum = 0;

        leftTraverse(root, sum);

        return sum;
    }
};