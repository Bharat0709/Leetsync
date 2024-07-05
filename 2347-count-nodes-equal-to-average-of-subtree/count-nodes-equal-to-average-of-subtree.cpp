class Solution {
pair<int,int> count(TreeNode* root, int& nodecount)
{
    if(root == NULL)
    {
        return {0,0};
    }
    auto lh = count(root->left,nodecount);
    auto rh = count(root->right,nodecount);

    int sum = lh.first + rh.first + root->val;
    int totalele = lh.second + rh.second + 1;

    if(sum/totalele == root->val)
    {
        nodecount++;
    }
    return {sum,totalele};
}
public:
    int averageOfSubtree(TreeNode* root) {
        int cnt = 0;
        count(root,cnt); 
        return cnt;
    }
};