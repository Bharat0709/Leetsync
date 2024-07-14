class Solution {

private:
    int minCost(int i, vector<int>& cost, vector<int>& dp) {
        int n = cost.size();

        // base case
        if (i >= n) {
            return 0;
        }

        // If the value is already computed, return it
        if (dp[i] != -1) {
            return dp[i];
        }

        // Recursion
        int step1 = cost[i] + minCost(i + 1, cost, dp);
        int step2 = cost[i] + (i + 1 < n ? minCost(i + 2, cost, dp) : 0);
        
        // Store the minimum cost in dp array
        dp[i] = min(step1, step2);
        return dp[i];
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);

        // Find the minimum cost starting from either step 0 or step 1
        return min(minCost(0, cost, dp), minCost(1, cost, dp));
    }
};
