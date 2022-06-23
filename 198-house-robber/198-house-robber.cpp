class Solution {
public:

  int help(vector<int> &nums, vector<int> &dp, int n) {
    dp[n] = dp[n + 1]  = 0;

    for (int i = nums.size() - 1; i >= 0; i--) {

      int pick = nums[i] + dp[i + 2];
      int ignore = 0 + dp[i + 1];

      dp[i] = max(pick, ignore);

    }
    return dp[0];
  }


  int rob(vector<int>& nums) {

    int n = nums.size();
    vector<int> dp(n + 2, -1);

    return help(nums, dp, n);
  }
};