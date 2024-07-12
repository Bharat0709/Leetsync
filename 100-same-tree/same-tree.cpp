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
    void traverse(TreeNode* p , TreeNode* q , bool &r){
        if(p == NULL && q == NULL){
            return;
        } 

        if((p == NULL && q != NULL) || (p != NULL && q == NULL)){
            r = false;
            return;
        }

        if(p -> val != q -> val){
            r = false;
            return ;
        }

        traverse(p -> left , q -> left , r);
        traverse(p -> right , q -> right , r);

    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q== NULL){
            return true;
        }

        bool r = true;
        traverse(p , q , r);
        return r ;
    }
};