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
public:
    bool checkTree(TreeNode* root) {
        int rootVal = root -> val;
        TreeNode* right = root -> right;
        int rightValue = right -> val;
        TreeNode* left = root -> left;
        int leftValue = left -> val;

        if(rootVal == rightValue + leftValue){
            return true;
        } else {
            return false;
        }
    }
};