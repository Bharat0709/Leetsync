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
 #include<queue> 
class Solution {
private:
    void LevelOrder(TreeNode* root, vector<int> levels, vector<vector<int>> &result) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        while (!q.empty()) {
           TreeNode* temp = q.front();
            q.pop();
            if (temp == NULL) {
                result.push_back(levels);
                levels.clear();
                if (!q.empty()) {
                    q.push(NULL);
                }
            } else {
                levels.push_back(temp-> val);
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL) {
            return result;
        }
        vector<int> levels;
        LevelOrder(root, levels, result);
        return result;
    }
};