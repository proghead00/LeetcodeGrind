class Solution {
public:

  int help(vector<int> &nums, vector<int> &dp, int idx) {
    if (idx >= nums.size()) return 0; // can't do return dp[idx] since idx can be outta bounds

    if (dp[idx] != -1) return dp[idx];

    int pick = nums[idx] + help(nums, dp, idx + 2);

    int ignore = 0 + help(nums, dp, idx + 1);

    return dp[idx] = max(pick, ignore);

  }

  int rob(vector<int>& nums) {

    int n = nums.size();
    vector<int> dp(n + 1, -1);

    return help(nums, dp, 0);
  }
};