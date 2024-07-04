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
#include <unordered_map>
class Solution {

private:
    void traverse(TreeNode* root, unordered_map<int, int>& mp) {
        if (root == nullptr) {
            return;
        }

        mp[root->val]++;
        traverse(root->left, mp);
        traverse(root->right, mp);
    }

public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> mp;
        traverse(root, mp);

        int maxFrequency = 0;
        for (const auto& pair : mp) {
            maxFrequency = max(maxFrequency, pair.second);
        }

        vector<int> result;
        for (const auto& pair : mp) {
            if (pair.second == maxFrequency) {
                result.push_back(pair.first);
            }
        }

        sort(result.begin(), result.end());
        return result;
    }
};