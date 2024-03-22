
class Solution {
public:
    int totalSteps(vector<int>& nums) {
           stack<pair<int, int>> stk;
    
    int cnt = 0;
    int res = 0;
    
    for(int i = nums.size() - 1;i >= 0;i--) {
    
        cnt = 0;
        
        while(!stk.empty() && nums[i] > stk.top().first) {
            cnt = max(cnt+1, stk.top().second);
            stk.pop();
        }
        res = max(res, cnt);
        stk.push({nums[i], cnt});
        
    }
    return res;
}
};