class Solution {
public:

  int help(vector<int> &nums, vector<int> &dp) {
    dp[0] = nums[0];

    for (int i = 1; i < nums.size(); i++) {

      int pick = nums[i];
      if (i >= 2) pick += dp[i - 2];

      int ignore = 0 + dp[i - 1];

      dp[i] = max(pick, ignore);

    }

    return dp[nums.size() - 1];

  }

  int rob(vector<int>& nums) {

    int n = nums.size();
    vector<int> dp(n, -1);

    return help(nums, dp);
  }
};