class Solution {
public:
    // target, idx
    int dp[50005][305];

    int help(vector<int> &coins, int target, int idx) {
        if (idx == 0) {
            // check if the 0th coin can form the target
            return (target % coins[0] == 0);
        }

        if (dp[target][idx] != -1) return dp[target][idx];

        int pick = 0, skip;

        skip = help(coins, target, idx - 1);

        if (coins[idx] <= target)
            pick = help(coins, target - coins[idx], idx);

        return dp[target][idx] = pick + skip;

    }

    int change(int amount, vector<int>& coins) {
        memset(dp, -1, sizeof(dp));
        return help(coins, amount, coins.size() - 1);

    }
};