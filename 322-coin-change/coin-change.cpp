class Solution {
private:
    int minCoins(const vector<int>& coins, int amount, unordered_map<int, int>& memo) {
        // base cases
        if (amount == 0) {
            return 0;
        }
        if (amount < 0) {
            return INT_MAX;
        }
        if (memo.find(amount) != memo.end()) {
            return memo[amount];
        }

        int mini = INT_MAX;
        for (int coin : coins) {
            int res = minCoins(coins, amount - coin, memo);
            if (res != INT_MAX) {
                mini = min(mini, res + 1);
            }
        }

        memo[amount] = mini;
        return mini;
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        unordered_map<int, int> memo;
        int result = minCoins(coins, amount, memo);
        return result == INT_MAX ? -1 : result;
    }
};
