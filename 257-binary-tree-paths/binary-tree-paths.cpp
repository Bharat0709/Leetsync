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
private:
    void solve(TreeNode* root, vector<string>& result, string path) {
        if (root == NULL) {
            return;
        }
        
        // Add the current node's value to the path
        if (!path.empty()) {
            path += "->";
        }
        path += to_string(root->val);

        // If it's a leaf node, add the path to the result
        if (root->left == NULL && root->right == NULL) {
            result.push_back(path);
        }
        
        // Otherwise, continue the path with the left and right child
        solve(root->left, result, path);
        solve(root->right, result, path);
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (root == NULL) {
            return result;
        }
        
        solve(root, result, "");
        return result;
    }
};
