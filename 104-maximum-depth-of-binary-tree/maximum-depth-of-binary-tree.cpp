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
    void levelOrder(TreeNode* root, int& result) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();

            if (temp == NULL) {
                result++;
                if (!q.empty()) {
                    q.push(NULL);
                }
            } else {
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
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int result = 0;

        levelOrder(root, result);
        return result ;
    }
};