class Solution {
public:
    int coinChange(vector<int> &coins, int target) {
        vector<vector<int>> dp(target + 1, vector<int>(coins.size(), 0));

        // form base case for bottom-up
        for (int t = 0; t <= target; t++) {
            if (t % coins[0] == 0) dp[t][0] = t / coins[0];
            else dp[t][0] = 1e9;
        }

        // loop for the changing states
        for (int idx = 1; idx < coins.size(); idx++) {
            for (int t = 0; t <= target; t++) {
                // copy the recurrence and mutate accordingly

                int pick = 1e9, skip;

                skip = dp[t][idx - 1];

                if (coins[idx] <= t)
                    pick = 1 + dp[t - coins[idx]][idx];

                dp[t][idx] = min(pick, skip);

            }
        }

        int ans = dp [target][coins.size() - 1];

        if (ans >= 1e9) return -1;
        else return ans;
    }
};
