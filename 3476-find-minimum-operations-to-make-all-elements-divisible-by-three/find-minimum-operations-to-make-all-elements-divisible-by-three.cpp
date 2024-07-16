class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        if(nums.size() == 0 ){
            return  0;
        }
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 3 == 2 || nums[i] % 3 == 1) {
                count++;
            }
        }
        return count ;
    }
};