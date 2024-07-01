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
    void traversal(TreeNode* root, int low, int high, int& sum) {
        if (root == NULL) {
            return;
        }
        
        if (root->val > low) { // Only traverse left subtree if there might be values within range
            traversal(root->left, low, high, sum);
        }
        
        if (root->val >= low && root->val <= high) {
            sum += root->val;
        }
        
        if (root->val < high) { // Only traverse right subtree if there might be values within range
            traversal(root->right, low, high, sum);
        }
    }

public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        traversal(root, low, high, sum);
        return sum;
    }
};
