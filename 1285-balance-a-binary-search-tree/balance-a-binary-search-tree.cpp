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
    TreeNode* buildTree(int s, int e, vector<int> store)
    {
        if(s > e) return NULL;
        int mid = (s+e)/2;
        TreeNode* root = new TreeNode(store[mid]);
        root->left = buildTree(s, mid-1, store);
        root->right = buildTree(mid+1, e, store);
        return root;
    }

    void inorder(TreeNode* root, vector<int>& store) {
        if (root == NULL) {
            return;
        }

        inorder(root->left, store);
        store.push_back(root->val);
        inorder(root->right , store);
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> store;

        if (root == NULL) {
            return root;
        }

        inorder(root, store);
        return buildTree(0, store.size()-1, store);
    }
};