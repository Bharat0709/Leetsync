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
    void Traverse(TreeNode* &root, int target) {
        if (root == NULL) {
            return;
        }

        if (root->val == target && root->left == NULL && root->right == NULL) {
            root = NULL;
            return;
        }
        cout << "Root Val " << root->val << " " << endl;

        Traverse(root->left, target);
        if (root->val == target && root->left == NULL && root->right == NULL) {
            root = NULL;
            return;
        }
        cout << "Root" << root->val << " " << endl;
        Traverse(root->right, target);
                if (root->val == target && root->left == NULL && root->right == NULL) {
            root = NULL;
            return;
        }
        cout << "Root" << root->val << " " << endl;
    }

public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (root == NULL) {
            return root;
        }

        Traverse(root, target);

        return root;
    }
};