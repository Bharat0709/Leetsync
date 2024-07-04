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

    void traverse(TreeNode* root , vector<int> &store){
        if(root == NULL){
            return ;
        }

        store.push_back(root -> val);
        traverse(root -> left , store);
        traverse(root -> right , store);
    }

    int findMinDifference(vector<int>& store) {
    if (store.size() < 2) {
        return 0; 
    }

    sort(store.begin(), store.end());

    int minDiff = INT_MAX;

    for (size_t i = 1; i < store.size(); ++i) {
        int diff = store[i] - store[i - 1];
        minDiff = min(minDiff, diff);
    }

    return minDiff;
}
public:
    int minDiffInBST(TreeNode* root) {
                
        vector<int> store;

        if(root == NULL){
            return 0;
        }

        traverse(root , store);

        int difference = findMinDifference(store);

        return difference;
    }
};