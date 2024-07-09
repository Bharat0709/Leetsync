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
#include <queue>
class Solution {
private:
    void levelOrder(TreeNode* root, vector<int> &ans) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int max = INT_MIN;

        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();

            if (temp == NULL) {
                ans.push_back(max);
                max = INT_MIN;
                if (!q.empty()) {
                    q.push(NULL);
                }
            } else {
                if (temp ->val > max) {
                    max = temp->val;
                }
                if (temp->left) {
                    q.push(temp->left);
                }
                if (temp->right) {
                    q.push(temp->right);
                }
            }
        }
    }

public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }
        levelOrder(root, ans);
        return ans;
    }
};