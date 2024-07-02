/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {

    void traverse(TreeNode* cloned, TreeNode*& result, int targetData) {
        if (cloned == NULL) {
            return;
        }

        if (cloned->val == targetData) {
            result = cloned;
        }
        traverse(cloned->left, result, targetData);
        traverse(cloned->right, result, targetData);
    }

public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned,
                            TreeNode* target) {

        if (cloned == NULL) {
            return cloned;
        }
        TreeNode* result = NULL;

        int targetData = target->val;

        traverse(cloned, result, targetData);

        return result;
    }
};