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
    void levelOrder(TreeNode* root, int x, int y, bool& result) {

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int height = 1;
        int heightx;
        int heighty;

        while (!q.empty()) {
            bool flag1 = true;
            bool flag2 = true;

            TreeNode* temp = q.front();
            q.pop();

            if (temp == NULL) {
                if (!q.empty()) {
                    height++;
                    q.push(NULL);
                    cout << endl;
                }
            } else {
                if (temp->val == x) {
                    heightx = height;
                }
                if (temp->val == y) {
                    heighty = height;
                }

                if (temp->left) {
                    if (temp->left->val == x || temp->left->val == y) {
                        flag1 = false;
                    }
                    q.push(temp->left);
                }
                if (temp->right) {
                    if (temp->right->val == x || temp->right->val == y) {
                        flag2 = false;
                    }
                    q.push(temp->right);
                }
                if (flag1 == false && flag2 == false) {
                    result = false;
                }
            }
        }
        if (heightx != heighty) {
            result = false;
        }
    }

public:
    bool isCousins(TreeNode* root, int x, int y) {
        if (root == NULL) {
            return false;
        }

        bool result = true;

        levelOrder(root, x, y, result);

        return result;
    }
};