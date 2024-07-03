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
    void traverse(TreeNode* root , bool &result , int value){
        if(root == NULL){
            return;
        }

        if( root-> val != value){
            result = false;
            return;
        }
        traverse(root -> left , result , value);
        traverse(root -> right , result , value);
    }
public:
    bool isUnivalTree(TreeNode* root) {

        if(root == NULL){
            return true;
        }
        bool result = true ;
        traverse(root , result, root -> val);
        return result;
    }
};