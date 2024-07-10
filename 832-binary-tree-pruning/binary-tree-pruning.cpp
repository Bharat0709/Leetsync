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
    bool prune(TreeNode* &root) {
        if (root == nullptr) {
            return false;
        }
        
        bool leftContainsOne = prune(root->left);
        bool rightContainsOne = prune(root->right);
        
        if (!leftContainsOne) {
            root->left = nullptr;
        }
        if (!rightContainsOne) {
            root->right = nullptr;
        }
        
        // If current node is '1' or any of its subtrees contain '1', return true.
        return root->val == 1 || leftContainsOne || rightContainsOne;
    }

public:
    TreeNode* pruneTree(TreeNode* root) {
        if (prune(root)) {
            return root;
        } else {
            return nullptr;
        }
    }
};