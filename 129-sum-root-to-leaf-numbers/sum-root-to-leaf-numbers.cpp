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
    void solve(TreeNode* root, string temp, int &sum) {
        if (root == NULL) {
            return;
        }
        temp = temp + to_string(root->val);
        if(root -> left == NULL && root -> right == NULL){
            sum += stoi(temp);
        }
        solve(root->left, temp, sum);
        solve(root->right, temp, sum);
    }

public:
    int sumNumbers(TreeNode* root) {
        int sum ;
        string temp;

        if(root == NULL){
            return sum;
        }

        solve(root , temp , sum);
        return sum;
    }
};