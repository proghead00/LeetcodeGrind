class Solution {
public:
    int help(vector<int> &coins, int target, int idx, vector<vector<int>> &dp) {
        if (idx == 0) {
            // check if the 0th coin can form the target
            return (target % coins[0] == 0) ? target / coins[0] : 1e9;
        }

        if (dp[target][idx] != -1) {
            return dp[target][idx];
        }

        int pick = 1e9, skip = 0;
        // pick = 1e9 (and not 0) ==> Why? Because, let's say,
        // skip gives me value of 3 and pick doesn't form the target, so it gives 0
        // the min is 0 which is wrong

        skip = help(coins, target, idx - 1, dp);

        if (coins[idx] <= target)

            // pick that coin and move on for further calls (keep idx fixed since I can take infinite ones of that denomination)
            pick = 1 + help(coins, target - coins[idx], idx, dp); // keeping idx as it is since I have infinite for the same


        return dp[target][idx] = min(pick, skip);
    }

    int coinChange(vector<int> &coins, int amount) {
        vector<vector<int>> dp(amount + 1, vector<int>(coins.size(), -1)); // amount ranges from 0 to amount (hence +1 for the size)

        int ans = help(coins, amount, coins.size() - 1, dp);

        if (ans >= 1e9) return -1;
        else return ans;
    }
};
