class Solution {
private:
    int climbs(int n, int i, vector<int>& dp) {
        // Base case: when we've exactly reached the top
        if (i == n) {
            return 1;
        }
        // Base case: when we've exceeded the top
        if (i > n) {
            return 0;
        }
        // Check if the result is already computed
        if (dp[i] != -1) {
            return dp[i];
        }
        // Recursion with memoization
        dp[i] = climbs(n, i + 1, dp) + climbs(n, i + 2, dp);
        return dp[i];
    }

public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);  // DP array to store results
        return climbs(n, 0, dp);
    }
};
