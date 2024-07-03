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
    void solveLeft(TreeNode* root, vector<string>& result, string st) {
        if (root == NULL) {
            return;
        }

        st = st + "->" + to_string(root->val);

        cout << st << endl;
        if(root -> left == NULL && root -> right == NULL){
            result.push_back(st);
            return;
        }
        solveLeft(root->left, result, st);
        solveLeft(root->right, result, st);
    }


public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (root == NULL) {
            return result;
        }

        if (root->left == NULL && root->right == NULL) {
            result.push_back(to_string(root->val));
        }

        if(root -> left){
        string st = to_string(root -> val);
        solveLeft(root-> left, result, st);
        }
        if(root -> right){
        string st = to_string(root -> val);
        solveLeft(root -> right , result, st);
        }

        return result;
    }
};