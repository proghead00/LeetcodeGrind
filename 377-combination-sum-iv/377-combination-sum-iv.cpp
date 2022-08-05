class Solution {
public:
    int dp[2051];

    int help(vector<int>& nums, int target) {
        if (target == 0) return 1;

        if (dp[target] != -1) return dp[target];

        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] <= target)
                ans += help(nums, target - nums[i]);

        return dp[target] = ans;
    }

    int combinationSum4(vector<int>& nums, int target) {
        memset(dp, -1, sizeof(dp));
        return help(nums, target);
    }
};